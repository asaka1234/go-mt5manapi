%module(directors="1") mtmanapi
%{
#include <windows.h>

#include "MT5APIConstants.h"
#include "MT5APILogger.h"
#include "MT5APIPublicKey.h"
#include "MT5APITools.h"
#include "Config/MT5APIConfigCommon.h"
#include "Config/MT5APIConfigFeeder.h"
#include "Config/MT5APIConfigFirewall.h"
#include "Config/MT5APIConfigGateway.h"
#include "Config/MT5APIConfigGroup.h"
#include "Config/MT5APIConfigHistory.h"
#include "Config/MT5APIConfigHoliday.h"
#include "Config/MT5APIConfigManager.h"
#include "Config/MT5APIConfigNetwork.h"
#include "Config/MT5APIConfigPlugin.h"
#include "Config/MT5APIConfigReport.h"
#include "Config/MT5APIConfigRoute.h"
#include "Config/MT5APIConfigSpread.h"
#include "Config/MT5APIConfigSymbol.h"
#include "Config/MT5APIConfigTime.h"
#include "Config/MT5APIConfigEmail.h"
#include "Config/MT5APIConfigMessenger.h"
#include "Config/MT5APIConfigAutomation.h"
#include "Config/MT5APIConfigSubscription.h"
#include "Config/MT5APIConfigVPS.h"
#include "Config/MT5APIConfigKYC.h"
#include "Config/MT5APIConfigLeverage.h"
#include "Bases/MT5APIAccount.h"
#include "Bases/MT5APIBook.h"
#include "Bases/MT5APIByteStream.h"
#include "Bases/MT5APICertificate.h"
#include "Bases/MT5APIChart.h"
#include "Bases/MT5APIConfirm.h"
#include "Bases/MT5APIDaily.h"
#include "Bases/MT5APIDeal.h"
#include "Bases/MT5APIExposure.h"
#include "Bases/MT5APIMail.h"
#include "Bases/MT5APINews.h"
#include "Bases/MT5APIOrder.h"
#include "Bases/MT5APIPosition.h"
#include "Bases/MT5APIRequest.h"
#include "Bases/MT5APISummary.h"
#include "Bases/MT5APITick.h"
#include "Bases/MT5APIUser.h"
#include "Bases/MT5APIOnline.h"
#include "Bases/MT5APIECN.h"
#include "Bases/MT5APIClient.h"
#include "Bases/MT5APIDocument.h"
#include "Bases/MT5APIAttachment.h"
#include "Bases/MT5APIComment.h"
#include "Bases/MT5APISubscription.h"
#include "Bases/MT5APIGeo.h"

#include "MT5APIManager.h"
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
%include "MT5APIConstants.h"
%include "MT5APILogger.h"
%include "MT5APIPublicKey.h"
%include "MT5APITools.h"
%include "Config/MT5APIConfigCommon.h"
%include "Config/MT5APIConfigFeeder.h"
%include "Config/MT5APIConfigFirewall.h"
%include "Config/MT5APIConfigGateway.h"
%include "Config/MT5APIConfigGroup.h"
%include "Config/MT5APIConfigHistory.h"
%include "Config/MT5APIConfigHoliday.h"
%include "Config/MT5APIConfigManager.h"
%include "Config/MT5APIConfigNetwork.h"
%include "Config/MT5APIConfigPlugin.h"
%include "Config/MT5APIConfigReport.h"
%include "Config/MT5APIConfigRoute.h"
%include "Config/MT5APIConfigSpread.h"
%include "Config/MT5APIConfigSymbol.h"
%include "Config/MT5APIConfigTime.h"
%include "Config/MT5APIConfigEmail.h"
%include "Config/MT5APIConfigMessenger.h"
%include "Config/MT5APIConfigAutomation.h"
%include "Config/MT5APIConfigSubscription.h"
%include "Config/MT5APIConfigVPS.h"
%include "Config/MT5APIConfigKYC.h"
%include "Config/MT5APIConfigLeverage.h"
%include "Bases/MT5APIAccount.h"
%include "Bases/MT5APIBook.h"
%include "Bases/MT5APIByteStream.h"
%include "Bases/MT5APICertificate.h"
%include "Bases/MT5APIChart.h"
%include "Bases/MT5APIConfirm.h"
%include "Bases/MT5APIDaily.h"
%include "Bases/MT5APIDeal.h"
%include "Bases/MT5APIExposure.h"
%include "Bases/MT5APIMail.h"
%include "Bases/MT5APINews.h"
%include "Bases/MT5APIOrder.h"
%include "Bases/MT5APIPosition.h"
%include "Bases/MT5APIRequest.h"
%include "Bases/MT5APISummary.h"
%include "Bases/MT5APITick.h"
%include "Bases/MT5APIUser.h"
%include "Bases/MT5APIOnline.h"
%include "Bases/MT5APIECN.h"
%include "Bases/MT5APIClient.h"
%include "Bases/MT5APIDocument.h"
%include "Bases/MT5APIAttachment.h"
%include "Bases/MT5APIComment.h"
%include "Bases/MT5APISubscription.h"
%include "Bases/MT5APIGeo.h"

%include "MT5APIManager.h"

