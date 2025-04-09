%module(directors="1") mt5api
%{
// 确保在Windows平台使用正确的调用约定
#ifdef _WIN32
# define SWIGSTDCALL __stdcall
#else
# define SWIGSTDCALL
#endif

#include <windows.h>

#include "Include\MT5APIManager.h"
#include "Include\MT5APIConstants.h"
#include "Include\MT5APILogger.h"
#include "Include\MT5APIPublicKey.h"
#include "Include\MT5APITools.h"
#include "Include\MT5APITypes.h"

#include "Include\Bases\MT5APIUser.h"

#include "Include\Classes\MT5APIStr.h"
#include "Include\Classes\MT5APIMath.h"
#include "Include\Classes\MT5APIFormat.h"
#include "Include\Classes\MT5APITime.h"
#include "Include\Classes\MT5APIStorage.h"
#include "Include\Classes\MT5APISync.h"
#include "Include\Classes\MT5APIThread.h"
#include "Include\Classes\MT5APIProcess.h"
#include "Include\Classes\MT5APIFile.h"
#include "Include\Classes\MT5APIMemPack.h"
%}

%include <typemaps.i>
%include "carrays.i"


%inline %{
#define LPCSTR char*
#define LPCWSTR const wchar_t*
%}

typedef __time32_t time_t;
typedef long long __time32_t;

// 为回调类型定义正确的调用约定
#ifdef _WIN32
%typemap(ctype) unsigned int (SWIGSTDCALL *)(void *) "unsigned int (__stdcall *)(void *)"
%typemap(imtype) unsigned int (SWIG_STDCALL *)(void *) "uint"
%typemap(cstype) unsigned int (SWIG_STDCALL *)(void *) "Example.CallbackDelegate"
#else
%typemap(ctype) unsigned int (*)(void *) "unsigned int (*)(void *)"
#endif

%include "windows.i"

%include "Include\\MT5APIManager.h"
%include "Include\\MT5APIConstants.h"
%include "Include\\MT5APILogger.h"
%include "Include\\MT5APIPublicKey.h"
%include "Include\\MT5APITools.h"
%include "Include\\MT5APITypes.h"

%include "Include\\Bases\\MT5APIUser.h"

%include "Include\\Classes\\MT5APIStr.h"
%include "Include\\Classes\\MT5APIMath.h"
%include "Include\\Classes\\MT5APIFormat.h"
%include "Include\\Classes\\MT5APITime.h"
%include "Include\\Classes\\MT5APIStorage.h"
%include "Include\\Classes\\MT5APISync.h"
%include "Include\\Classes\\MT5APIThread.h"
%include "Include\\Classes\\MT5APIProcess.h"
%include "Include\\Classes\\MT5APIFile.h"
%include "Include\\Classes\\MT5APIMemPack.h"