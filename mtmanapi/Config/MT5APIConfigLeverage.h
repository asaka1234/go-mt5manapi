//+------------------------------------------------------------------+
//|                                                MetaTrader 5 API  |
//|                             Copyright 2000-2024, MetaQuotes Ltd. |
//|                                               www.metaquotes.net |
//+------------------------------------------------------------------+
#pragma once
//+------------------------------------------------------------------+
//| Commission tier config                                           |
//+------------------------------------------------------------------+
class IMTConLeverageTier
  {
public:
   //--- common methods
   virtual void      Release(void)=0;
   virtual MTAPIRES  Assign(const IMTConLeverageTier* cfg)=0;
   virtual MTAPIRES  Clear(void)=0;
   //--- tier range from
   virtual double    RangeFrom(void) const=0;
   virtual MTAPIRES  RangeFrom(const double value)=0;
   //--- tier range to
   virtual double    RangeTo(void) const=0;
   virtual MTAPIRES  RangeTo(const double value)=0;
   //--- rate for initial orders
   virtual double    MarginRateInitial(void) const=0;
   virtual MTAPIRES  MarginRateInitial(const double value)=0;
   //--- rate for position maintenance
   virtual double    MarginRateMaintenance(void) const=0;
   virtual MTAPIRES  MarginRateMaintenance(const double value)=0;
   //--- explicit destructor is prohibited
protected:
                    ~IMTConLeverageTier(void) {}
  };
//+------------------------------------------------------------------+
//| Floating Leverage rule configuration interface                   |
//+------------------------------------------------------------------+
class IMTConLeverageRule
  {
public:
   //--- range modes
   enum EnRangeMode
     {
      RANGE_VOLUME           =0,  // range in volume
      RANGE_VOLUME_PER_SYMBOL=1,  // range in volume per symbol
      RANGE_VALUE            =2,  // range in value
      RANGE_VALUE_PER_SYMBOL =3,  // range in value per symbol
      //--- enumeration borders
      RANGE_FIRST          =RANGE_VOLUME,
      RANGE_LAST           =RANGE_VALUE_PER_SYMBOL
     };
   //--- common methods
   virtual void      Release(void)=0;
   virtual MTAPIRES  Assign(const IMTConLeverageRule* cfg)=0;
   virtual MTAPIRES  Clear(void)=0;
   //--- commission name
   virtual LPCWSTR   Name(void) const=0;
   virtual MTAPIRES  Name(LPCWSTR name)=0;
   //--- description
   virtual LPCWSTR   Description(void) const=0;
   virtual MTAPIRES  Description(LPCWSTR descr)=0;
   //--- symbols path
   virtual LPCWSTR   Path(void) const=0;
   virtual MTAPIRES  Path(LPCWSTR path)=0;
   //--- EnRangeMode
   virtual UINT      RangeMode(void) const=0;
   virtual MTAPIRES  RangeMode(const UINT mode)=0;
   //---- value calculation currency
   virtual LPCWSTR   RangeValueCurrency(void) const=0;
   virtual MTAPIRES  RangeValueCurrency(LPCWSTR currency)=0;
   //--- commission tiers
   virtual MTAPIRES  TierAdd(IMTConLeverageTier* tier)=0;
   virtual MTAPIRES  TierUpdate(const UINT pos,const IMTConLeverageTier* tier)=0;
   virtual MTAPIRES  TierDelete(const UINT pos)=0;
   virtual MTAPIRES  TierClear(void)=0;
   virtual MTAPIRES  TierShift(const UINT pos,const int shift)=0;
   virtual UINT      TierTotal(void) const=0;
   virtual MTAPIRES  TierNext(const UINT pos,IMTConLeverageTier* tier) const=0;
   //--- explicit destructor is prohibited
protected:
                    ~IMTConLeverageRule(void) {}
  };
//+------------------------------------------------------------------+
//| Floating Leverage configuration interface                        |
//+------------------------------------------------------------------+
class IMTConLeverage
  {
public:
   //--- common methods
   virtual void      Release(void)=0;
   virtual MTAPIRES  Assign(const IMTConLeverage* cfg)=0;
   virtual MTAPIRES  Clear(void)=0;
   //--- name
   virtual LPCWSTR   Name(void) const=0;
   virtual MTAPIRES  Name(LPCWSTR name)=0;
   //--- rules
   virtual MTAPIRES  RuleAdd(IMTConLeverageRule* cfg)=0;
   virtual MTAPIRES  RuleUpdate(const UINT pos,const IMTConLeverageRule* cfg)=0;
   virtual MTAPIRES  RuleDelete(const UINT pos)=0;
   virtual MTAPIRES  RuleClear(void)=0;
   virtual MTAPIRES  RuleShift(const UINT pos,const int shift)=0;
   virtual UINT      RuleTotal(void) const=0;
   virtual MTAPIRES  RuleNext(const UINT pos,IMTConLeverageRule* cfg) const=0;
   virtual MTAPIRES  RuleGet(LPCWSTR name,IMTConLeverageRule* cfg) const=0;
   //--- explicit destructor is prohibited
protected:
                    ~IMTConLeverage(void) {}
  };
//+------------------------------------------------------------------+
//| Group configuration array interface                              |
//+------------------------------------------------------------------+
class IMTConLeverageArray
  {
public:
   //--- common methods
   virtual void      Release(void)=0;
   virtual MTAPIRES  Assign(const IMTConLeverageArray* array)=0;
   virtual MTAPIRES  Clear(void)=0;
   //--- add
   virtual MTAPIRES  Add(IMTConLeverage* record)=0;
   virtual MTAPIRES  AddCopy(const IMTConLeverage* record)=0;
   virtual MTAPIRES  Add(IMTConLeverageArray* array)=0;
   virtual MTAPIRES  AddCopy(const IMTConLeverageArray* array)=0;
   //--- delete & detach
   virtual MTAPIRES  Delete(const UINT pos)=0;
   virtual IMTConLeverage* Detach(const UINT pos)=0;
   //--- update
   virtual MTAPIRES  Update(const UINT pos,IMTConLeverage* record)=0;
   virtual MTAPIRES  UpdateCopy(const UINT pos,const IMTConLeverage* record)=0;
   virtual MTAPIRES  Shift(const UINT pos,const int shift)=0;
   //--- data access
   virtual UINT      Total(void) const=0;
   virtual IMTConLeverage*  Next(const UINT index) const=0;
   //--- sorting and search
   virtual MTAPIRES  Sort(MTSortFunctionPtr sort_function)=0;
   virtual int       Search(const void *key,MTSortFunctionPtr sort_function) const=0;
   virtual int       SearchGreatOrEq(const void *key,MTSortFunctionPtr sort_function) const=0;
   virtual int       SearchGreater(const void *key,MTSortFunctionPtr sort_function) const=0;
   virtual int       SearchLessOrEq(const void *key,MTSortFunctionPtr sort_function) const=0;
   virtual int       SearchLess(const void *key,MTSortFunctionPtr sort_function) const=0;
   virtual int       SearchLeft(const void *key,MTSortFunctionPtr sort_function) const=0;
   virtual int       SearchRight(const void *key,MTSortFunctionPtr sort_function) const=0;
   //--- explicit destructor is prohibited
protected:
                    ~IMTConLeverageArray(void) {}
  };
//+------------------------------------------------------------------+
//| Leverage config events notification interface                    |
//+------------------------------------------------------------------+
class IMTConLeverageSink
  {
public:
   virtual void      OnLeverageAdd(const IMTConLeverage*    /*config*/) {  }
   virtual void      OnLeverageUpdate(const IMTConLeverage* /*config*/) {  }
   virtual void      OnLeverageDelete(const IMTConLeverage* /*config*/) {  }
   virtual void      OnLeverageSync(void)                            {  }
   //--- config modification hooks (only for Server API)
   virtual MTAPIRES  HookLeverageAdd(const UINT64 /*login*/,IMTConLeverage* /*new_cfg*/)                                  { return(MT_RET_OK); }
   virtual MTAPIRES  HookLeverageUpdate(const UINT64 /*login*/,const IMTConLeverage* /*cfg*/,IMTConLeverage* /*new_cfg*/) { return(MT_RET_OK); }
   virtual MTAPIRES  HookLeverageDelete(const UINT64 /*login*/,const IMTConLeverage* /*cfg*/)                             { return(MT_RET_OK); }
  };
//+------------------------------------------------------------------+ 
