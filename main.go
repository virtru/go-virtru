/*
* Copyright © 2021 Virtru Corporation
*
* SPDX - License - Identifier: MIT
*
 */

package main

import (
	"fmt"
	"log"
	"unsafe"
)

/*
* This is a simple one-file Golang example that wraps the Virtru C SDK interface
* and encrypts the `sample.txt` file in this directory as a TDF.
 */

/*
* The following directives tell `cgo` where to look for the
* C static library and header files,
* and should be modified if those files are located elsewhere.
* They may also be overridden by setting CGO_LDFLAGS and CGO_CFLAGS env vars.
* For more info on how cgo works, see: https://golang.org/cmd/cgo/
 */

// #include <stdlib.h>
// #include <stdbool.h>
// #include <virtru_client_c.h>
// #include <virtru_encrypt_file_params_c.h>
// #include <virtru_config_service_c.h>
import "C"

// Update these with a valid name and appID
var yourEmail = C.CString("your-user-name@your-domain.com")
var yourAppID = C.CString("11111111-1111-1111-1111-111111111111")

// replace with actual URL where Configuration Service is running
var configUrl = C.CString("http://localhost:9090")

func main() {
	fmt.Printf("Getting ready to encrypt file")
	getClientAndEncryptFile()
	createAndUpdateConfigService()
	fmt.Printf("Bye!\n")
}

// Directly invokes the Virtru SDK via the C ABI and passes it a filename to encrypt.
// For more information on what functionality the C API exposes, see
// "virtru_xx_c.h" headers that ship with the Virtru SDK.
func getClientAndEncryptFile() {

	fmt.Println("Getting Virtru client")
	inFile := C.CString("./sample.txt")

	clientPtr := C.VClientCreateWithAppId(yourEmail, yourAppID)

	checkVStatus(C.VSetProtocol(clientPtr, C.VProtocolHtml))

	fileParamsPtr := C.VEncryptFileParamsCreate1(inFile)
	checkVStatus(C.VEncryptFileParamsSetDisplayMessage(fileParamsPtr, C.CString("YO FROM GO")))
	//optional - set the Virtru client log level
	checkVStatus(C.VEnableConsoleLogging(clientPtr, C.VLogLevelTrace))

	outID := make([]byte, 256)
	checkVStatus(C.VClientEncryptFile(clientPtr, fileParamsPtr, (**C.char)(unsafe.Pointer(&outID[0]))))

	C.VClientDestroy(clientPtr)
	C.VEncryptFileParamsDestroy(fileParamsPtr)
}

// Checks the VSTATUS C enum, exiting with a fatal error on an unrecognized status
func checkVStatus(status C.VSTATUS) {
	if status == C.VSTATUS_SUCCESS {
		fmt.Println("All Good!")
	} else if status == C.VSTATUS_INVALID_PARAMS {
		fmt.Println("Bad param!")
	} else {
		log.Fatalf("Something went horribly wrong: %d", status)
	}
}

func createAndUpdateConfigService() {
	configService := C.VConfigServiceCreate(configUrl)
	C.VCreateConfig(configService, C.CString("scrum_demo"), C.CString("sample.txt"))
	C.VGetConfig(configService, C.CString("scrum_demo"), C.CString("scrum_demo.txt"))
	_ = C.VGetConfigMetaData(configService, C.CString("scrum_demo"))
}
