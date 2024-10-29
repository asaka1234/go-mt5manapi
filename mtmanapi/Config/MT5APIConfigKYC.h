//+------------------------------------------------------------------+
//|                                                 MetaTrader 5 API |
//|                             Copyright 2000-2024, MetaQuotes Ltd. |
//|                                               www.metaquotes.net |
//+------------------------------------------------------------------+
#pragma once
//+------------------------------------------------------------------+
//| KYC country config                                               |
//+------------------------------------------------------------------+
class IMTConKYCCountry
  {
public:
   //--- common methods
   virtual void      Release(void)=0;
   virtual MTAPIRES  Assign(const IMTConKYCCountry* country)=0;
   virtual MTAPIRES  Clear(void)=0;
   //--- country code
   virtual LPCWSTR   CountryCode(void) const=0;
   virtual MTAPIRES  CountryCode(LPCWSTR code)=0;
  };
//+------------------------------------------------------------------+
//| KYC group config                                                 |
//+------------------------------------------------------------------+
class IMTConKYCGroup
  {
public:
   //--- common methods
   virtual void      Release(void)=0;
   virtual MTAPIRES  Assign(const IMTConKYCGroup* group)=0;
   virtual MTAPIRES  Clear(void)=0;
   //--- phone code
   virtual LPCWSTR   Group(void) const=0;
   virtual MTAPIRES  Group(LPCWSTR group)=0;
  };
//+------------------------------------------------------------------+
//| KYC config                                                       |
//+------------------------------------------------------------------+
class IMTConKYC
  {
public:
   //--- allowed flags
   enum EnFlags
     {
      FLAG_NONE               =0, // none
      FLAG_ENABLED            =1, // config is enabled
      FLAG_DEFAULT            =2, // config is default
      //--- flags borders
      FLAG_FIRST              =FLAG_ENABLED,
      FLAG_ALL                =FLAG_ENABLED|FLAG_DEFAULT
     };
   //--- providers
   enum EnProviderType
     {
      //---- SMS
      PROVIDER_KYC_SUMSUB     =0,
      PROVIDER_KYC_WORLD_CHECK=1,
      PROVIDER_KYC_ESPEAR     =2,
      //--- ranges
      PROVIDER_KYC_FIRST     =PROVIDER_KYC_SUMSUB,
      PROVIDER_KYC_LAST      =PROVIDER_KYC_ESPEAR,
     };
   //--- common methods
   virtual void      Release(void)=0;
   virtual MTAPIRES  Assign(const IMTConKYC* config)=0;
   virtual MTAPIRES  Clear(void)=0;
   //--- name
   virtual LPCWSTR   Name(void) const=0;
   virtual MTAPIRES  Name(LPCWSTR name)=0;
   //--- provider type
   virtual UINT      ProviderType(void) const=0;
   virtual MTAPIRES  ProviderType(const UINT provider)=0;
   //--- provider address
   virtual LPCWSTR   ProviderAddress(void) const=0;
   virtual MTAPIRES  ProviderAddress(LPCWSTR address)=0;
   //--- provider login
   virtual LPCWSTR   ProviderLogin(void) const=0;
   virtual MTAPIRES  ProviderLogin(LPCWSTR login)=0;
   //--- provider password
   virtual LPCWSTR   ProviderPassword(void) const=0;
   virtual MTAPIRES  ProviderPassword(LPCWSTR password)=0;
   //--- provider token
   virtual LPCWSTR   ProviderToken(void) const=0;
   virtual MTAPIRES  ProviderToken(LPCWSTR token)=0;
   //--- EnFlags
   virtual UINT64    Flags(void) const=0;
   virtual MTAPIRES  Flags(const UINT64 flags)=0;
   //--- country settings
   virtual MTAPIRES  CountryAdd(IMTConKYCCountry* country)=0;
   virtual MTAPIRES  CountryUpdate(const UINT pos,const IMTConKYCCountry* country)=0;
   virtual MTAPIRES  CountryDelete(const UINT pos)=0;
   virtual MTAPIRES  CountryClear(void)=0;
   virtual MTAPIRES  CountryShift(const UINT pos,const int shift)=0;
   virtual UINT      CountryTotal(void) const=0;
   virtual MTAPIRES  CountryNext(const UINT pos,IMTConKYCCountry* country) const=0;
   //--- group settings
   virtual MTAPIRES  GroupAdd(IMTConKYCGroup* group)=0;
   virtual MTAPIRES  GroupUpdate(const UINT pos,const IMTConKYCGroup* group)=0;
   virtual MTAPIRES  GroupDelete(const UINT pos)=0;
   virtual MTAPIRES  GroupClear(void)=0;
   virtual MTAPIRES  GroupShift(const UINT pos,const int shift)=0;
   virtual UINT      GroupTotal(void) const=0;
   virtual MTAPIRES  GroupNext(const UINT pos,IMTConKYCGroup* group) const=0;
   //--- explicit destructor is prohibited
protected:
                    ~IMTConKYC(void) {}
  };
//+------------------------------------------------------------------+
//| KYC config events notification interface                         |
//+------------------------------------------------------------------+
class IMTConKYCSink
  {
public:
   virtual void      OnKYCAdd(const IMTConKYC*    /*config*/) {  }
   virtual void      OnKYCUpdate(const IMTConKYC* /*config*/) {  }
   virtual void      OnKYCDelete(const IMTConKYC* /*config*/) {  }
   virtual void      OnKYCSync(void)                          {  }
  };
//+------------------------------------------------------------------+
