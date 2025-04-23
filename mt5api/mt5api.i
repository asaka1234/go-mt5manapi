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

// 定义 LPCWSTR 到 Go string 的类型映射
%typemap(gotype) LPCWSTR "string"
%typemap(in) LPCWSTR {
    $1 = (LPCWSTR)GoStringToWideChar($input); // Go string -> LPCWSTR
}
%typemap(out) LPCWSTR {
    $result = WideCharToGoString($1); // LPCWSTR -> Go string
}

// 辅助函数（需在 %{ %} 中实现）
%{
#include <stdlib.h>
#include <string.h>

wchar_t* GoStringToWideChar(const char* goStr) {
    int len = MultiByteToWideChar(CP_UTF8, 0, goStr, -1, NULL, 0);
    wchar_t* wstr = (wchar_t*)malloc(len * sizeof(wchar_t));
    MultiByteToWideChar(CP_UTF8, 0, goStr, -1, wstr, len);
    return wstr;
}

char* WideCharToGoString(const wchar_t* wstr) {
    int len = WideCharToMultiByte(CP_UTF8, 0, wstr, -1, NULL, 0, NULL, NULL);
    char* goStr = (char*)malloc(len);
    WideCharToMultiByte(CP_UTF8, 0, wstr, -1, goStr, len, NULL, NULL);
    return goStr;
}
%}


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