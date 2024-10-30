%module(directors="1") mt5api
%{
#include <windows.h>
#include "Include\MT5APIManager.h"
#include "Include\MT5APIConstants.h"
#include "Include\MT5APILogger.h"
#include "Include\MT5APITools.h"
#include "Include\MT5APITypes.h"
%}

%include <typemaps.i>
%include "carrays.i"

%array_functions(ConGroup, ConGroupArray);
%array_functions(ConGroupSec, ConGroupSecArray);
%array_functions(UserRecord, UserRecordArray);
%array_functions(TradeRecord, TradeRecordArray);
%array_functions(ConSymbol, ConSymbolArray);
%array_functions(SymbolInfo, SymbolInfoArray);
%array_functions(RateInfo, RateInfoArray);
%array_functions(TickInfo, TickInfoArray);
%array_functions(ConSessions, ConSessionsArray);
%array_functions(ConSession, ConSessionArray);
%array_functions(RequestInfo, RequestInfoArray);

%feature("director") IMTManagerAPI;

%inline %{
#define LPCSTR char*
%}

typedef __time32_t time_t;
typedef long long __time32_t;

%include "windows.i"
%include "Include\\MT5APIManager.h"
%include "Include\\MT5APIConstants.h"
%include "Include\\MT5APILogger.h"
%include "Include\\MT5APITools.h"
%include "Include\\MT5APITypes.h"

