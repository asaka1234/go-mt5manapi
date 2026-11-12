//+------------------------------------------------------------------+
//|                                                 MetaTrader 5 API |
//|                             Copyright 2000-2026, MetaQuotes Ltd. |
//|                                               www.metaquotes.net |
//+------------------------------------------------------------------+
#pragma once
#include "MT5APIConfigParam.h"
//+------------------------------------------------------------------+
//| Liquidity Provider configuration                                 |
//+------------------------------------------------------------------+
class IMTConUltLiquidity
  {
public:
   //--- flags
   enum EnFlags
     {
      FLAGS_NONE                    =0x00000000,
      FLAGS_QUOTES                  =0x00000001,
      FLAGS_TRADE                   =0x00000002,
      FLAGS_SEND_PARTY_ID           =0x00000004,
      //--- enumeration borders
      FLAGS_ALL                     =FLAGS_QUOTES|FLAGS_TRADE|FLAGS_SEND_PARTY_ID
     };
   //--- type
   enum EnType
     {
      TYPE_MT5                    =0,
      TYPE_MT4                    =1,
      TYPE_INTEGRAL               =2,
      TYPE_LMAX                   =3,
      TYPE_HIDDEN_ROAD            =4,
      TYPE_HIDDEN_ROAD_PRIME_BROKER=5,
      //--- enumeration borders
      TYPE_FIRST                  =TYPE_MT5,
      TYPE_LAST                   =TYPE_HIDDEN_ROAD_PRIME_BROKER
     };
   //--- mode
   enum EnMode
     {
      PROVIDER_DISABLED   =0,
      PROVIDER_ENABLED    =1,
      //--- enumeration borders
      PROVIDER_FIRST      =PROVIDER_DISABLED,
      PROVIDER_LAST       =PROVIDER_ENABLED,
     };
   //--- common methods
   virtual void      Release(void)=0;
   virtual MTAPIRES  Assign(const IMTConUltLiquidity* param)=0;
   virtual MTAPIRES  Clear(void)=0;
   //--- id
   virtual uint32_t  ID(void) const=0;
   virtual MTAPIRES  ID(const uint32_t id)=0;
   //--- id
   virtual uint64_t  Server(void) const=0;
   virtual MTAPIRES  Server(const uint64_t server)=0;
   //--- name
   virtual LPCWSTR   Name(void) const=0;
   virtual MTAPIRES  Name(LPCWSTR name)=0;
   //--- EnType
   virtual uint32_t  Type(void) const=0;
   virtual MTAPIRES  Type(const uint32_t action)=0;
   //--- EnMode
   virtual uint32_t  Mode(void) const=0;
   virtual MTAPIRES  Mode(const uint32_t mode)=0;
   //--- EnFlags
   virtual uint32_t  Flags(void) const=0;
   virtual MTAPIRES  Flags(const uint32_t flags)=0;
   //--- liquidity provider
   virtual uint64_t  LiquidityProvider(void) const=0;
   virtual MTAPIRES  LiquidityProvider(const uint64_t lp)=0;
   //--- coverage group
   virtual LPCWSTR   CoverageGroup(void) const=0;
   virtual MTAPIRES  CoverageGroup(LPCWSTR group)=0;
   //--- coverage login
   virtual uint64_t  CoverageLogin(void) const=0;
   virtual MTAPIRES  CoverageLogin(const uint64_t login)=0;
   //--- parameters
   virtual MTAPIRES  ParameterAdd(IMTConParam* param)=0;
   virtual MTAPIRES  ParameterUpdate(const uint32_t pos,const IMTConParam* param)=0;
   virtual MTAPIRES  ParameterDelete(const uint32_t pos)=0;
   virtual MTAPIRES  ParameterClear(void)=0;
   virtual MTAPIRES  ParameterShift(const uint32_t pos,const int32_t shift)=0;
   virtual uint32_t  ParameterTotal(void) const=0;
   virtual MTAPIRES  ParameterNext(const uint32_t pos,IMTConParam* param) const=0;
   virtual MTAPIRES  ParameterGet(LPCWSTR name,IMTConParam* param) const=0;
   //--- coverage currency
   virtual LPCWSTR   CoverageCurrency(void) const=0;
   virtual MTAPIRES  CoverageCurrency(LPCWSTR currency)=0;
   //--- coverage leverage
   virtual uint32_t  CoverageLeverage(void) const=0;
   virtual MTAPIRES  CoverageLeverage(const uint32_t leverage)=0;
//--- explicit destructor is prohibited
protected:
                    ~IMTConUltLiquidity(void) {}
  };
//+------------------------------------------------------------------+
//| Liquidity Provider history record                                |
//+------------------------------------------------------------------+
class IMTConUltLiquidityHistory
  {
public:
   //--- common methods
   virtual void      Release(void)=0;
   virtual MTAPIRES  Assign(const IMTConUltLiquidityHistory* param)=0;
   virtual MTAPIRES  Clear(void)=0;
   //--- id
   virtual uint32_t  ID(void) const=0;
   virtual MTAPIRES  ID(const uint32_t id)=0;
   //--- id
   virtual uint64_t  Server(void) const=0;
   virtual MTAPIRES  Server(const uint64_t server)=0;
   //--- name
   virtual LPCWSTR   Name(void) const=0;
   virtual MTAPIRES  Name(LPCWSTR name)=0;
   //--- EnType
   virtual uint32_t  Type(void) const=0;
   virtual MTAPIRES  Type(const uint32_t action)=0;
   //--- liquidity provider
   virtual uint64_t  LiquidityProvider(void) const=0;
   virtual MTAPIRES  LiquidityProvider(const uint64_t lp)=0;
   //--- parameter for mt5
   virtual uint64_t  ParameterMT5Login(void) const=0;
   virtual MTAPIRES  ParameterMT5Login(const uint64_t login)=0;
   //--- parameter for FIX
   virtual LPCWSTR   ParameterFIXSenderCompID(void) const=0;
   virtual MTAPIRES  ParameterFIXSenderCompID(LPCWSTR id)=0;
   //--- parameter for FIX
   virtual LPCWSTR   ParameterFIXSenderSubID(void) const=0;
   virtual MTAPIRES  ParameterFIXSenderSubID(LPCWSTR id)=0;
//--- explicit destructor is prohibited
protected:
                    ~IMTConUltLiquidityHistory(void) {}
  };
//+------------------------------------------------------------------+
//| Config events notification interface                             |
//+------------------------------------------------------------------+
class IMTConUltLiquiditySink
  {
public:
   virtual void      OnUltLiquidityAdd(const IMTConUltLiquidity*    /*config*/) {  }
   virtual void      OnUltLiquidityUpdate(const IMTConUltLiquidity* /*config*/) {  }
   virtual void      OnUltLiquidityDelete(const IMTConUltLiquidity* /*config*/) {  }
   virtual void      OnUltLiquiditySync(void)                                    {  }
  };
//+------------------------------------------------------------------+
//| Config events notification interface                             |
//+------------------------------------------------------------------+
class IMTConUltLiquidityHistorySink
  {
public:
   virtual void      OnUltLiqHistoryAdd(const IMTConUltLiquidityHistory*    /*config*/) {  }
   virtual void      OnUltLiqHistoryUpdate(const IMTConUltLiquidityHistory* /*config*/) {  }
   virtual void      OnUltLiqHistoryDelete(const IMTConUltLiquidityHistory* /*config*/) {  }
   virtual void      OnUltLiqHistorySync(void)                                           {  }
  };
//+------------------------------------------------------------------+
