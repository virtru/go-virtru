package virtru

// #cgo CFLAGS: -I${SRCDIR}/include
// #cgo darwin,arm64 LDFLAGS: -L${SRCDIR}/lib/darwin/arm64 -lvirtru_tdf3 -lstdc++
// #cgo linux,amd64 LDFLAGS: -L${SRCDIR}/lib/linux/amd64 -lvirtru-tdf3 -lpthread -ldl -lm -lstdc++
// #cgo windows,amd64 LDFLAGS: -L${SRCDIR}\lib\windows\amd64 -lvirtru-tdf3 -lstdc++
// #include <stdlib.h>
// #include <stdbool.h>
// #include <virtru_constants_c.h>
// #include <virtru_client_c.h>
// #include <virtru_config_service_c.h>
import "C"
import (
	"errors"
	"fmt"
	"net/url"
	"os"
)

type Authentication struct {
	Url          *url.URL
	authnService *C.TDFClientPtr
	credentials  *C.TDFCredsPtr
}

func NewAuthentication(url *url.URL) (*Authentication, error) {
	a := &Authentication{
		Url: url,
	}
	return a, nil
}

func (a *Authentication) ClientCredentials(id string, secret string) error {
	var clientId = C.CString(id)
	var clientSecret = C.CString(secret)
	var authnUrl = C.CString(a.Url.String())
	var clientCredentials = C.TDFCreateCredentialClientCreds(authnUrl, clientId, clientSecret, nil)
	authnService := C.TDFCreateClient(clientCredentials, authnUrl)
	if authnService == nil {
		return errors.New("OIDC service creation failed")
	}
	a.authnService = &authnService
	fmt.Println(clientId)
	fmt.Println(clientSecret)
	return nil
}

type Configuration struct {
	Url           *url.URL
	configService *C.ConfigService
}

func NewConfiguration(url *url.URL) (*Configuration, error) {
	c := &Configuration{
		Url: url,
	}
	var configUrl = C.CString(url.String())
	configService := C.VConfigServiceCreate(configUrl)
	if configService == nil {
		return nil, errors.New("config service creation failed")
	}
	c.configService = configService
	return c, nil
}

func (c *Configuration) Get(key string) ([]byte, error) {
	filename := key + ".json"
	metadata := C.VGetConfigMetaData(c.configService, C.CString(key))
	if metadata == nil {
		return nil, errors.New(fmt.Sprintf("config key \"%s\" did not return result from %s", key, c.Url.String()))
	}
	C.VGetConfig(c.configService, C.CString(key), C.CString(filename))
	contentBytes, err := os.ReadFile(filename)
	if err != nil {
		return nil, errors.Join(errors.New("config file not read"), err)
	}
	return contentBytes, nil
}

func (c *Configuration) Create(key string, bytes []byte) {
	C.VCreateConfig(c.configService, C.CString(key), C.CString(string(bytes)))
}
