package mt5api

/*
   #cgo CFLAGS: -I./Include
   #cgo LDFLAGS: -L. -lMT5APIGateway64

   #include <stdlib.h>
   #include "MT5APIGateway.h"

   // 辅助函数：创建网关
   MTAPIRES CreateGateway(CMTGatewayAPIFactory* factory,
                          MTGatewayInfo* info,
                          IMTGatewayAPI** gateway,
                          int argc,
                          wchar_t** argv) {
       return factory->Create(*info, gateway, argc, argv);
   }
*/
import "C"
import (
	"syscall"
	"unsafe"
)

func CreateGateway(factory *C.CMTGatewayAPIFactory,
	info *C.MTGatewayInfo,
	args []string) (*C.IMTGatewayAPI, C.MTAPIRES) {

	argc := len(args)

	// 分配 C 的 argv 数组
	argv := C.malloc(C.size_t(argc+1) * C.sizeof(unsafe.Pointer))
	defer C.free(argv)

	argvSlice := unsafe.Slice((**C.wchar_t)(argv), argc+1)

	for i, arg := range args {
		ptr, _ := syscall.UTF16PtrFromString(arg)
		argvSlice[i] = (*C.wchar_t)(unsafe.Pointer(ptr))
	}
	argvSlice[argc] = nil

	var gateway *C.IMTGatewayAPI
	ret := C.CreateGateway(factory, info, &gateway, C.int(argc), (**C.wchar_t)(argv))

	return gateway, ret
}
