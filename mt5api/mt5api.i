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
#include "Include\Config\MT5APIConfigParam.h"
#include "Include\Config\MT5APIConfigFeeder.h"
#include "Include\Config\MT5APIConfigGateway.h"
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
#include "Include\Bases\MT5APIExecution.h"
#include "Include\Bases\MT5APIBook.h"
%}

%include <typemaps.i>
%include "carrays.i"
//-------------------------------------
%include <stdint.i>


%inline %{
#include <vector>
#include <string>

class WArgv {
private:
    wchar_t** argv;
    int argc;

public:
    WArgv() : argv(nullptr), argc(0) {}

    ~WArgv() {
        clear();
    }

    void clear() {
        if (argv) {
            for (int i = 0; i < argc; i++) {
                delete[] argv[i];
            }
            delete[] argv;
            argv = nullptr;
            argc = 0;
        }
    }

    // 从 Go 的 string 数组构造
    void fromStringArray(const std::vector<std::string>& args) {
        clear();
        argc = (int)args.size();
        argv = new wchar_t*[argc + 1];

        for (int i = 0; i < argc; i++) {
            // UTF-8 转 UTF-16
            std::string utf8 = args[i];
            int len = MultiByteToWideChar(CP_UTF8, 0, utf8.c_str(), -1, NULL, 0);
            argv[i] = new wchar_t[len];
            MultiByteToWideChar(CP_UTF8, 0, utf8.c_str(), -1, argv[i], len);
        }
        argv[argc] = nullptr;
    }

    wchar_t** get() { return argv; }
    int size() { return argc; }
};
%}

// 模板化，让 Go 可以使用
%include <std_vector.i>
%include <std_string.i>
%template(StringVector) std::vector<std::string>;
//%template(WArgvTemplate) WArgv;

%apply long long { INT64 };

%array_functions(MTChartBar, MTChartBarArray);
%array_functions(MTBookItem, MTBookItemArray);
%array_functions(MTBook,MTBookArray);
%array_functions(MTTick,MTTickArray);
%array_functions(LPWSTR,LPWSTRArray);

// 在你的 .i 文件中，MTBook 结构体定义之后添加
%extend MTBook {
    void SetItem(int index, const MTBookItem& item) {
        if (index >= 0 && index < 128) {
            $self->items[index] = item;
        }
    }

    MTBookItem GetItem(int index) {
        if (index >= 0 && index < 128) {
            return $self->items[index];
        }
        MTBookItem empty;
        return empty;
    }
}

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
%feature("director") IMTGatewaySink;
%feature("director") IMTBookSink;

%rename(OnDealerAnswerConfirm)  IMTGatewaySink::OnDealerAnswer(const MTAPIRES      /*retcode*/,const IMTConfirm*   /*confirm*/) ;
%rename(OnDealerAnswerExecution)  IMTGatewaySink::OnDealerAnswer(const UINT64        /*login*/,const MTAPIRES      /*retcode*/,const IMTExecution* /*execution*/) ;

%rename(OnGatewayConfig)  IMTGatewaySink::OnGatewayConfig(const UINT64 /*login*/,const IMTConGateway* /*config*/);
%rename(OnFeedConfig)  IMTGatewaySink::OnGatewayConfig(const UINT64 /*login*/,const IMTConFeeder*  /*config*/);

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
%include "Include\\Config\\MT5APIConfigParam.h"
%include "Include\\Config\\MT5APIConfigFeeder.h"
%include "Include\\Config\\MT5APIConfigGateway.h"
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
%include "Include\\Bases\\MT5APIExecution.h"
%include "Include\\Bases\\MT5APIBook.h"