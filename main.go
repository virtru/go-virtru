package virtru

// #cgo CFLAGS: -I${SRCDIR}/include
// #cgo darwin,arm64 LDFLAGS: -L${SRCDIR}/lib/darwin/arm64 -lvirtru_tdf3_static_combined -lstdc++
// #cgo linux,amd64 LDFLAGS: -L${SRCDIR}/lib/linux/amd64 -lvirtru-tdf3 -lpthread -ldl -lm -lstdc++
// #cgo windows,amd64 LDFLAGS: -L${SRCDIR}\lib\windows\amd64 -lvirtru-tdf3 -lstdc++
// #include <stdlib.h>
// #include <stdbool.h>
// #include <tdf_constants_c.h>
// #include <tdf_client_c.h>
// #include <virtru_constants_c.h>
// #include <virtru_client_c.h>
// #include <virtru_config_service_c.h>
// #include <virtru_encrypt_file_params_c.h>
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
	var kasUrl = C.CString(a.Url.String() + "/api/kas")
	var clientCredentials = C.TDFCreateCredentialClientCreds(authnUrl, clientId, clientSecret, C.CString("tdf"))
	authnService := C.TDFCreateClient(clientCredentials, kasUrl)
	if authnService == nil {
		return errors.New("OIDC service creation failed")
	}
	a.authnService = &authnService
	return nil
}

func (a *Authentication) EncryptString(payload string) []byte {
	//bytesGo := []byte(payload)
	//bytesPtr := (*C.uchar)(unsafe.Pointer(&bytesGo))
	//bytesLength := C.TDFBytesLength(len(payload))
	//storageType := C.TDFCreateTDFStorageStringType(bytesPtr, bytesLength)
	//var cipherBytes C.TDFCBytesPtr
	//var cipherLength C.TDFBytesLength
	cipherBytesGo := make([]byte, 256)
	//cipherBytesC := (C.TDFCBytesPtr)(unsafe.Pointer(&cipherBytesGo[0]))
	//C.TDFEncryptString(*a.authnService, storageType, &cipherBytesC, &cipherLength)
	return cipherBytesGo
}

func (a *Authentication) ClientAndEncryptFile(id string, secret string) {
	inFile := C.CString("./go.mod")

	fileParamsPtr := C.TDFCreateTDFStorageFileType(inFile)
	//storageType := C.TDFCreateTDFStorageFileType(C.CString("./go.mod.tdf"))
	C.TDFEncryptFile(*a.authnService, fileParamsPtr, C.CString("./go.mod.tdf"))

	//C.TDFClientDestroy(*a.authnService)
	//C.TDFEncryptFileParamsDestroy(fileParamsPtr)
}

func (a *Authentication) Log() {
	C.TDFEnableConsoleLogging(*a.authnService, C.TDFLogLevelTrace)
}

func (a *Authentication) Close() {
	C.TDFDestroyClient(*a.authnService)
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
