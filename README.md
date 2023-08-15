# Virtru SDK for Go

Virtru SDK via its C wrapper, using Golang's native `cgo` C interop

## Prerequisites

### Virtru SDK for C++

#### Linux

Download the [C++ archive for Linux](https://sdk.virtru.com/cpp/latest/virtru-tdf3-lib-cpp-lin.tar.gz).
Unpack the archive.  
Move the unpacked folder into your project.  
```shell
 export CGO_LDFLAGS="-L/virtru-tdf3-lib-cpp/lib"
 export CGO_CFLAGS="-I/virtru-tdf3-lib-cpp/include"
 export CGO_ENABLED=1
```

#### macOS

Download the [C++ archive for macOS](https://sdk.virtru.com/cpp/latest/virtru-tdf3-lib-cpp-osx.tar.gz).  
```shell
wget https://sdk.virtru.com/cpp/latest/virtru-tdf3-lib-cpp-osx.tar.gz
```
Unpack the archive.  
Move the unpacked folder into your project.  
```shell
 export CGO_LDFLAGS="-L/virtru-tdf3-lib-cpp/lib"
 export CGO_CFLAGS="-I/virtru-tdf3-lib-cpp/include"
 export CGO_ENABLED=1
```

#### Windows

Download the [C++ archive for Windows](https://sdk.virtru.com/cpp/latest/virtru-tdf3-lib-cpp-win.zip).  
Unpack the archive.  
Move the unpacked folder into your project.  
Install Visual Studio 2017 or newer.  
Generate Visual Studio project files using CMake. Run this in the Developer PowerShell for Visual Studio: 
```shell
Copy
Set-Location .\sample\
cmake -G "Visual Studio 15 2017 Win64"
```
Open the virtru_tdf3_sensitive.sln file with Visual Studio.  
Select Release in configuration.  
Select Build > Build solution to compile, link and create an executable.  

## Install

```shell
go get github.com/virtru/go-virtru
```
