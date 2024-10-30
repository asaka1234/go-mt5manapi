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

