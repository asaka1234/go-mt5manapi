%module(directors="1") mt5api
%{
#include <windows.h>

#include "Include\MT5APIManager.h"
#include "Include\MT5APIConstants.h"
#include "Include\MT5APILogger.h"
#include "Include\MT5APIPublicKey.h"
#include "Include\MT5APITools.h"
#include "Include\MT5APITypes.h"

#include "Include\Config\MT5APIConfigCommon.h"
#include "Include\Config\MT5APIConfigFeeder.h"
#include "Include\Config\MT5APIConfigFirewall.h"
#include "Include\Config\MT5APIConfigGateway.h"
#include "Include\Config\MT5APIConfigGroup.h"
#include "Include\Config\MT5APIConfigHistory.h"
#include "Include\Config\MT5APIConfigHoliday.h"
#include "Include\Config\MT5APIConfigManager.h"
#include "Include\Config\MT5APIConfigNetwork.h"
#include "Include\Config\MT5APIConfigPlugin.h"
#include "Include\Config\MT5APIConfigReport.h"
#include "Include\Config\MT5APIConfigRoute.h"
#include "Include\Config\MT5APIConfigSpread.h"
#include "Include\Config\MT5APIConfigSymbol.h"
#include "Include\Config\MT5APIConfigTime.h"
#include "Include\Config\MT5APIConfigEmail.h"
#include "Include\Config\MT5APIConfigMessenger.h"
#include "Include\Config\MT5APIConfigAutomation.h"
#include "Include\Config\MT5APIConfigSubscription.h"
#include "Include\Config\MT5APIConfigVPS.h"
#include "Include\Config\MT5APIConfigKYC.h"
#include "Include\Config\MT5APIConfigLeverage.h"

#include "Include\Bases\MT5APIAccount.h"
#include "Include\Bases\MT5APIBook.h"
#include "Include\Bases\MT5APIByteStream.h"
#include "Include\Bases\MT5APICertificate.h"
#include "Include\Bases\MT5APIChart.h"
#include "Include\Bases\MT5APIConfirm.h"
#include "Include\Bases\MT5APIDaily.h"
#include "Include\Bases\MT5APIDeal.h"
#include "Include\Bases\MT5APIExposure.h"
#include "Include\Bases\MT5APIMail.h"
#include "Include\Bases\MT5APINews.h"
#include "Include\Bases\MT5APIOrder.h"
#include "Include\Bases\MT5APIPosition.h"
#include "Include\Bases\MT5APIRequest.h"
#include "Include\Bases\MT5APISummary.h"
#include "Include\Bases\MT5APITick.h"
#include "Include\Bases\MT5APIUser.h"
#include "Include\Bases\MT5APIOnline.h"
#include "Include\Bases\MT5APIECN.h"
#include "Include\Bases\MT5APIClient.h"
#include "Include\Bases\MT5APIDocument.h"
#include "Include\Bases\MT5APIAttachment.h"
#include "Include\Bases\MT5APIComment.h"
#include "Include\Bases\MT5APISubscription.h"
#include "Include\Bases\MT5APIGeo.h"

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

%include "Include\\Config\\MT5APIConfigCommon.h"
%include "Include\\Config\\MT5APIConfigFeeder.h"
%include "Include\\Config\\MT5APIConfigFirewall.h"
%include "Include\\Config\\MT5APIConfigGateway.h"
%include "Include\\Config\\MT5APIConfigGroup.h"
%include "Include\\Config\\MT5APIConfigHistory.h"
%include "Include\\Config\\MT5APIConfigHoliday.h"
%include "Include\\Config\\MT5APIConfigManager.h"
%include "Include\\Config\\MT5APIConfigNetwork.h"
%include "Include\\Config\\MT5APIConfigPlugin.h"
%include "Include\\Config\\MT5APIConfigReport.h"
%include "Include\\Config\\MT5APIConfigRoute.h"
%include "Include\\Config\\MT5APIConfigSpread.h"
%include "Include\\Config\\MT5APIConfigSymbol.h"
%include "Include\\Config\\MT5APIConfigTime.h"
%include "Include\\Config\\MT5APIConfigEmail.h"
%include "Include\\Config\\MT5APIConfigMessenger.h"
%include "Include\\Config\\MT5APIConfigAutomation.h"
%include "Include\\Config\\MT5APIConfigSubscription.h"
%include "Include\\Config\\MT5APIConfigVPS.h"
%include "Include\\Config\\MT5APIConfigKYC.h"
%include "Include\\Config\\MT5APIConfigLeverage.h"

%include "Include\\Bases\\MT5APIAccount.h"
%include "Include\\Bases\\MT5APIBook.h"
%include "Include\\Bases\\MT5APIByteStream.h"
%include "Include\\Bases\\MT5APICertificate.h"
%include "Include\\Bases\\MT5APIChart.h"
%include "Include\\Bases\\MT5APIConfirm.h"
%include "Include\\Bases\\MT5APIDaily.h"
%include "Include\\Bases\\MT5APIDeal.h"
%include "Include\\Bases\\MT5APIExposure.h"
%include "Include\\Bases\\MT5APIMail.h"
%include "Include\\Bases\\MT5APINews.h"
%include "Include\\Bases\\MT5APIOrder.h"
%include "Include\\Bases\\MT5APIPosition.h"
%include "Include\\Bases\\MT5APIRequest.h"
%include "Include\\Bases\\MT5APISummary.h"
%include "Include\\Bases\\MT5APITick.h"
%include "Include\\Bases\\MT5APIUser.h"
%include "Include\\Bases\\MT5APIOnline.h"
%include "Include\\Bases\\MT5APIECN.h"
%include "Include\\Bases\\MT5APIClient.h"
%include "Include\\Bases\\MT5APIDocument.h"
%include "Include\\Bases\\MT5APIAttachment.h"
%include "Include\\Bases\\MT5APIComment.h"
%include "Include\\Bases\\MT5APISubscription.h"
%include "Include\\Bases\\MT5APIGeo.h"

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