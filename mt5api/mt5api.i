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


#define _WINSOCKAPI_        // 禁止 winsock.h
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX

#include <winsock2.h>       // 必须在 windows.h 前
#include <windows.h>

#include "Include\MT5APIGateway.h"
#include "Include\MT5APIManager.h"
#include "Include\MT5APIConstants.h"
#include "Include\MT5APILogger.h"
#include "Include\MT5APIPublicKey.h"
#include "Include\MT5APITools.h"
#include "Include\MT5APITypes.h"

#include "Include\Classes\MT5APIStr.h"
#include "Include\Classes\MT5APIMath.h"
#include "Include\Classes\MT5APIFormat.h"
#include "Include\Classes\MT5APITime.h"
#include "Include\Classes\MT5APIStorage.h"
#include "Include\Classes\MT5APISync.h"
#include "Include\Classes\MT5APIProcess.h"
#include "Include\Classes\MT5APIFile.h"
#include "Include\Classes\MT5APIMemPack.h"

#include "Include\Config\MT5APIConfigGroup.h"
#include "Include\Config\MT5APIConfigHoliday.h"
#include "Include\Config\MT5APIConfigSymbol.h"
#include "Include\Bases\MT5APITick.h"
#include "Include\Bases\MT5APIPosition.h"
#include "Include\Bases\MT5APIAccount.h"
#include "Include\Config\MT5APIConfigTime.h"
#include "Include\Bases\MT5APIDeal.h"
#include "Include\Bases\MT5APIUser.h"
#include "Include\Bases\MT5APIOnline.h"
#include "Include\Bases\MT5APIRequest.h"
#include "Include\Bases\MT5APIOrder.h"
#include "Include\Bases\MT5APIChart.h"
#include "Include\Bases\MT5APIConfirm.h"
%}

%include <typemaps.i>
%include "carrays.i"

%include "cpointer.i"

// ==========================
// Go []string → wchar_t**
// ==========================
%typemap(goin) (int argc, wchar_t **argv) {
    int i;
    $1 = (int)len($input);
    if ($1 > 0) {
        $2 = (wchar_t**)malloc(sizeof(wchar_t*) * $1);
        for(i = 0; i < $1; i++) {
            char *s = (char*)GoStringIndex($input, i);

            int len = MultiByteToWideChar(CP_UTF8, 0, s, -1, NULL, 0);
            wchar_t *ws = (wchar_t*)malloc(sizeof(wchar_t) * len);
            MultiByteToWideChar(CP_UTF8, 0, s, -1, ws, len);

            $2[i] = ws;
        }
    } else {
        $2 = NULL;
    }
}

// 释放内存
%typemap(freearg) (int argc, wchar_t **argv) {
    if ($2) {
        for(int i = 0; i < $1; i++) {
            free($2[i]);
        }
        free($2);
    }
}

//-------------------------------------

%array_functions(MTChartBar, MTChartBarArray);

// 启用 director 功能以支持从 Go 继承 C++ 类
%feature("director") IMTTickSink;

// 重命名重载函数以避免Go中的命名冲突
%rename(OnTickShort) IMTTickSink::OnTick(LPCWSTR /*symbol*/,const MTTickShort& /*tick*/);
%rename(OnTickServer) IMTTickSink::OnTick(const int /*feeder*/,const MTTick& /*tick*/);
%rename(OnTickStatShort) IMTTickSink::OnTickStat(const MTTickStat& /*tick*/);
%rename(OnTickStatServer) IMTTickSink::OnTickStat(const int /*feeder*/,const MTTickStat& /*tstat*/);


// 启用 director 功能以支持从 Go 继承 C++ 类
%feature("director") IMTPositionSink;
%feature("director") IMTDealSink;
%feature("director") IMTOrderSink;
%feature("director") IMTUserSink;
%feature("director") IMTDealerSink;
%feature("director") IMTManagerSink;
%feature("director") IMTConGroupSink;
%feature("director") IMTUserSink;
%feature("director") IMTAccountSink;
%feature("director") IMTConTimeSink;
%feature("director") IMTConSymbolSink;
%feature("director") IMTConHolidaySink;

/*
%typemap(goin) LPCWSTR "string"
%typemap(in) LPCWSTR {
    $1 = (LPCWSTR)SWIG_GoString($input);
}
*/
//-------------------------------------


%inline %{
#define LPCSTR char*
#define LPCWSTR const wchar_t*
%}


typedef __time32_t time_t;
typedef long long __time32_t;


%include "windows.i"

%include "Include\\MT5APIGateway.h"
%include "Include\\MT5APIManager.h"
%include "Include\\MT5APIConstants.h"
%include "Include\\MT5APILogger.h"
%include "Include\\MT5APIPublicKey.h"
%include "Include\\MT5APITools.h"
%include "Include\\MT5APITypes.h"

%include "Include\\Classes\\MT5APIStr.h"
%include "Include\\Classes\\MT5APIMath.h"
%include "Include\\Classes\\MT5APIFormat.h"
%include "Include\\Classes\\MT5APITime.h"
%include "Include\\Classes\\MT5APIStorage.h"
%include "Include\\Classes\\MT5APISync.h"
%include "Include\\Classes\\MT5APIProcess.h"
%include "Include\\Classes\\MT5APIFile.h"
%include "Include\\Classes\\MT5APIMemPack.h"

%include "Include\\Config\\MT5APIConfigGroup.h"
%include "Include\\Config\\MT5APIConfigHoliday.h"
%include "Include\\Config\\MT5APIConfigSymbol.h"
%include "Include\\Bases\\MT5APITick.h"
%include "Include\\Bases\\MT5APIPosition.h"
%include "Include\\Config\\MT5APIConfigTime.h"
%include "Include\\Bases\\MT5APIDeal.h"
%include "Include\\Bases\\MT5APIUser.h"
%include "Include\\Bases\\MT5APIOnline.h"
%include "Include\\Bases\\MT5APIRequest.h"
%include "Include\\Bases\\MT5APIOrder.h"
%include "Include\\Bases\\MT5APIChart.h"
%include "Include\\Bases\\MT5APIAccount.h"
%include "Include\\Bases\\MT5APIConfirm.h"