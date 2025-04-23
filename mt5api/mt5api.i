%module(directors="1") mt5api
%{
// 平台调用约定强制定义
#if defined(_WIN32) || defined(__CYGWIN__)
# define SWIG_WINAPI __stdcall
# ifdef __MINGW32__
#  define SWIG_EXPORT __declspec(dllexport)
# else
#  define SWIG_EXPORT
# endif
#else
# define SWIG_WINAPI
# define SWIG_EXPORT
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

%{
#include <stdlib.h>
#include <string.h>

// 辅助函数：Go字符串 -> LPCWSTR (宽字符)
static wchar_t* GoStringToLPCWSTR(const char* goStr) {
    int len = MultiByteToWideChar(CP_UTF8, 0, goStr, -1, NULL, 0);
    wchar_t* wstr = (wchar_t*)malloc(len * sizeof(wchar_t));
    MultiByteToWideChar(CP_UTF8, 0, goStr, -1, wstr, len);
    return wstr;
}

// 辅助函数：LPCWSTR -> Go字符串
static char* LPCWSTRToGoString(const wchar_t* wstr) {
    int len = WideCharToMultiByte(CP_UTF8, 0, wstr, -1, NULL, 0, NULL, NULL);
    char* goStr = (char*)malloc(len);
    WideCharToMultiByte(CP_UTF8, 0, wstr, -1, goStr, len, NULL, NULL);
    return goStr;
}
%}

// 清理分配的内存
%typemap(freearg) LPCWSTR {
    free((wchar_t*)$1);
}

// 输入类型映射 (Go -> C)
%typemap(in) LPCWSTR {
    $1 = GoStringToLPCWSTR($input.p);
}

// 输出类型映射 (C -> Go)
%typemap(out) LPCWSTR {
    $result = Swig_AllocString(LPCWSTRToGoString($1));
    free((char*)$1);
}

// 应用类型映射到特定函数
%apply LPCWSTR { const wchar_t* }; // 也可以处理const变体


typedef __time32_t time_t;
typedef long long __time32_t;


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
%include "Include\\Classes\\MT5APIProcess.h"
%include "Include\\Classes\\MT5APIFile.h"
%include "Include\\Classes\\MT5APIMemPack.h"