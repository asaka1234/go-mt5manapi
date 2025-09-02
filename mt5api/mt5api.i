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

#include "Include\Config\MT5APIConfigGroup.h"
#include "Include\Config\MT5APIConfigSymbol.h"
#include "Include\Bases\MT5APITick.h"
#include "Include\Bases\MT5APIPosition.h"
#include "Include\Config\MT5APIConfigTime.h"
#include "Include\Bases\MT5APIDeal.h"
#include "Include\Bases\MT5APIUser.h"
%}

%include <typemaps.i>
%include "carrays.i"


//-------------------------------------

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
%feature("director") IMTUserSink;

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

%include "Include\\Config\\MT5APIConfigGroup.h"
%include "Include\\Config\\MT5APIConfigSymbol.h"
%include "Include\\Bases\\MT5APITick.h"
%include "Include\\Bases\\MT5APIPosition.h"
%include "Include\\Config\\MT5APIConfigTime.h"
%include "Include\\Bases\\MT5APIDeal.h"
%include "Include\\Bases\\MT5APIUser.h"