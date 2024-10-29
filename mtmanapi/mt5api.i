%module(directors="1") mt5api
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

%inline %{
#define LPCSTR char*
%}

typedef __time32_t time_t;
typedef long long __time32_t;
typedef UINT MTAPIRES;

%include "windows.i"
%include "MT5APIManager.h"
%include "MT5APIManager.h"
%include "MT5APIConstants.h"
%include "MT5APILogger.h"
%include "MT5APITools.h"
%include "MT5APITypes.h"

