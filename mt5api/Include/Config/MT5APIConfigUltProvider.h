//+------------------------------------------------------------------+
//|                                                 MetaTrader 5 API |
//|                             Copyright 2000-2026, MetaQuotes Ltd. |
//|                                               www.metaquotes.net |
//+------------------------------------------------------------------+
#pragma once
#include "MT5APIConfigParam.h"
//+------------------------------------------------------------------+
//| Ultency provider access point                                    |
//+------------------------------------------------------------------+
class IMTConUltProviderPoint
  {
public:
   //--- common methods
   virtual void      Release(void)=0;
   virtual MTAPIRES  Assign(const IMTConUltProviderPoint* config)=0;
   virtual MTAPIRES  Clear(void)=0;
   //--- name
   virtual LPCWSTR   Name(void) const=0;
   virtual MTAPIRES  Name(LPCWSTR name)=0;
   //--- address
   virtual LPCWSTR   Address(void) const=0;
   virtual MTAPIRES  Address(LPCWSTR address)=0;
   //--- unknown ping value
   //--- ping in microseconds
   virtual int64_t   Ping(void) const=0;
   virtual MTAPIRES  Ping(const int64_t ping)=0;
   virtual int64_t   PingUnknown(void) const=0;
//--- explicit destructor is prohibited
protected:
                    ~IMTConUltProviderPoint(void) {}
  };
//+------------------------------------------------------------------+
//| Ultency provider configuration                                   |
//+------------------------------------------------------------------+
class IMTConUltProvider
  {
public:
   //--- provider type
   enum EnType
     {
      TYPE_MT5                       =0,
      TYPE_FIX                       =1,
      TYPE_OTHER                     =2,
      //--- enumeration borders
      TYPE_FIRST                     =TYPE_MT5,
      TYPE_LAST                      =TYPE_OTHER
     };
   //--- provider status
   enum EnStatus
     {
      STATUS_PRELIMINARY             =0,
      STATUS_ACTIVE                  =1,
      STATUS_DISABLED                =2,
      STATUS_CLOSED                  =3,
      STATUS_HIDDEN                  =4,
      //--- enumeration borders
      STATUS_FIRST                   =STATUS_PRELIMINARY,
      STATUS_LAST                    =STATUS_HIDDEN
     };
   //--- common methods
   virtual void      Release(void)=0;
   virtual MTAPIRES  Assign(const IMTConUltProvider* config)=0;
   virtual MTAPIRES  Clear(void)=0;
   //--- provider id
   virtual uint64_t  ID(void) const=0;
   virtual MTAPIRES  ID(const uint64_t id)=0;
   //--- server
   virtual uint64_t  Server(void) const=0;
   virtual MTAPIRES  Server(const uint64_t server)=0;
   //--- name
   virtual LPCWSTR   Name(void) const=0;
   virtual MTAPIRES  Name(LPCWSTR name)=0;
   //--- status EnStatus
   virtual uint32_t  Status(void) const=0;
   virtual MTAPIRES  Status(const uint32_t status)=0;
   //--- type EnType
   virtual uint32_t  Type(void) const=0;
   virtual MTAPIRES  Type(const uint32_t type)=0;
   //--- access points
   virtual MTAPIRES  PointAdd(IMTConUltProviderPoint* point)=0;
   virtual MTAPIRES  PointUpdate(const uint32_t pos,const IMTConUltProviderPoint* point)=0;
   virtual MTAPIRES  PointDelete(const uint32_t pos)=0;
   virtual MTAPIRES  PointClear(void)=0;
   virtual MTAPIRES  PointShift(const uint32_t pos,const int32_t shift)=0;
   virtual uint32_t  PointTotal(void) const=0;
   virtual MTAPIRES  PointNext(const uint32_t pos,IMTConUltProviderPoint* point) const=0;
   //--- zones
   virtual MTAPIRES  ZoneAdd(const uint64_t zone)=0;
   virtual MTAPIRES  ZoneUpdate(const uint32_t pos,const uint64_t zone)=0;
   virtual MTAPIRES  ZoneDelete(const uint32_t pos)=0;
   virtual MTAPIRES  ZoneClear(void)=0;
   virtual MTAPIRES  ZoneShift(const uint32_t pos,const int32_t shift)=0;
   virtual uint32_t  ZoneTotal(void) const=0;
   virtual MTAPIRES  ZoneNext(const uint32_t pos,uint64_t& zone) const=0;
   //--- parameters
   virtual MTAPIRES  ParameterAdd(IMTConParam* param)=0;
   virtual MTAPIRES  ParameterUpdate(const uint32_t pos,const IMTConParam* param)=0;
   virtual MTAPIRES  ParameterDelete(const uint32_t pos)=0;
   virtual MTAPIRES  ParameterClear(void)=0;
   virtual MTAPIRES  ParameterShift(const uint32_t pos,const int32_t shift)=0;
   virtual uint32_t  ParameterTotal(void) const=0;
   virtual MTAPIRES  ParameterNext(const uint32_t pos,IMTConParam* param) const=0;
   virtual MTAPIRES  ParameterGet(LPCWSTR name,IMTConParam* param) const=0;
//--- explicit destructor is prohibited
protected:
                    ~IMTConUltProvider(void) {}
  };
//+------------------------------------------------------------------+
//| Config events notification interface                             |
//+------------------------------------------------------------------+
class IMTConUltProviderSink
  {
public:
   virtual void      OnUltProviderAdd(const IMTConUltProvider*    /*config*/) {  }
   virtual void      OnUltProviderUpdate(const IMTConUltProvider* /*config*/) {  }
   virtual void      OnUltProviderDelete(const IMTConUltProvider* /*config*/) {  }
   virtual void      OnUltProviderSync(void)                                  {  }
  };
//+------------------------------------------------------------------+
