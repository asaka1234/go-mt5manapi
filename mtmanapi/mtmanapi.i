%module(directors="1") mtmanapi
%{
#include <windows.h>

#include "MT5APIManager.h"
#include "MT5APIConstants.h"
#include "MT5APILogger.h"
#include "MT5APITools.h"
#include "MT5APITypes.h"

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


%feature("director") PumpReceiver;
%feature("director") DealReceiver;

%inline %{
#define LPCSTR char*
%}

typedef __time32_t time_t;
typedef int __time32_t;

%include "windows.i"
%include "MT5APIManager.h"
%include "MT5APIManager.h"
%include "MT5APIConstants.h"
%include "MT5APILogger.h"
%include "MT5APITools.h"
%include "MT5APITypes.h"

