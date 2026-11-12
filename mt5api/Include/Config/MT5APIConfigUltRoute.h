//+------------------------------------------------------------------+
//|                                                 MetaTrader 5 API |
//|                             Copyright 2000-2026, MetaQuotes Ltd. |
//|                                               www.metaquotes.net |
//+------------------------------------------------------------------+
#pragma once
//+------------------------------------------------------------------+
//| Ultency routing condition                                        |
//+------------------------------------------------------------------+
class IMTConUltRouteCondition
  {
public:
   //--- condition
   enum EnCondition
     {
      //--- date and time
      CONDITION_DATETIME_DATETIME             =0,
      CONDITION_DATETIME_DATE                 =1,
      CONDITION_DATETIME_TIME                 =2,
      CONDITION_DATETIME_WEEKDAY              =3,
      CONDITION_DATETIME_FIRST                =CONDITION_DATETIME_DATETIME,
      CONDITION_DATETIME_LAST                 =1000,
      //--- account
      CONDITION_ACCOUNT_LOGIN                 =1001,
      CONDITION_ACCOUNT_GROUP                 =1002,
      CONDITION_ACCOUNT_COUNTRY               =1003,
      CONDITION_ACCOUNT_CITY                  =1004,
      CONDITION_ACCOUNT_LANGUAGE              =1005,
      CONDITION_ACCOUNT_PHONE                 =1006,
      CONDITION_ACCOUNT_EMAIL                 =1007,
      CONDITION_ACCOUNT_COLOR                 =1008,
      CONDITION_ACCOUNT_COMMENT               =1009,
      CONDITION_ACCOUNT_REGISTRATION          =1010,
      CONDITION_ACCOUNT_LASTTIME              =1011,
      CONDITION_ACCOUNT_LEVERAGE              =1012,
      CONDITION_ACCOUNT_BALANCE               =1013,
      CONDITION_ACCOUNT_CREDIT                =1014,
      CONDITION_ACCOUNT_POSITIONS             =1015,
      CONDITION_ACCOUNT_ORDERS                =1016,
      CONDITION_ACCOUNT_PROFIT                =1017,
      CONDITION_ACCOUNT_EQUITY                =1018,
      CONDITION_ACCOUNT_MARGIN                =1019,
      CONDITION_ACCOUNT_MARGIN_FREE           =1020,
      CONDITION_ACCOUNT_MARGIN_LEVEL          =1021,
      CONDITION_ACCOUNT_CURRENCY              =1022,
      CONDITION_ACCOUNT_REGISTRATION_ELAPSED  =1023,
      CONDITION_ACCOUNT_LASTTIME_ELAPSED      =1024,
      CONDITION_ACCOUNT_LEAD_SOURCE           =1025,
      CONDITION_ACCOUNT_LEAD_CAMPAIGN         =1026,
      CONDITION_ACCOUNT_ONLINE                =1027,
      CONDITION_ACCOUNT_ACTIVITY_TRADE_ELAPSED=1028,
      CONDITION_ACCOUNT_ENABLED               =1029,
      CONDITION_ACCOUNT_TRADING_ENABLED       =1030,
      CONDITION_ACCOUNT_EXPERT_ENABLED        =1031,
      CONDITION_ACCOUNT_OWN_FUNDS_PERCENT     =1032,
      CONDITION_ACCOUNT_OWN_FUNDS_VOLUME      =1033,
      CONDITION_ACCOUNT_AGENT                 =1034,
      CONDITION_ACCOUNT_STATUS                =1035,
      CONDITION_ACCOUNT_COMPANY               =1036,
      CONDITION_ACCOUNT_CLIENT_ID             =1037,
      CONDITION_ACCOUNT_BANK_ACCOUNT          =1038,
      CONDITION_ACCOUNT_STATE                 =1039,
      CONDITION_ACCOUNT_ZIPCODE               =1040,
      CONDITION_ACCOUNT_POSITIONS_BY_SYMBOL   =1041,
      CONDITION_ACCOUNT_ORDERS_BY_SYMBOL      =1042,
      CONDITION_ACCOUNT_VOLUME_TOTAL          =1043,
      CONDITION_ACCOUNT_VOLUME_NET            =1044,
      CONDITION_ACCOUNT_VOLUME_BY_SYMBOL      =1045,
      CONDITION_ACCOUNT_VOLUME_NET_BY_SYMBOL  =1046,
      CONDITION_ACCOUNT_VOLUME_BUY_BY_SYMBOL  =1047,
      CONDITION_ACCOUNT_VOLUME_SELL_BY_SYMBOL =1048,
      CONDITION_ACCOUNT_FIRST                 =CONDITION_ACCOUNT_LOGIN,
      CONDITION_ACCOUNT_LAST                  =2000,
      //--- request
      CONDITION_REQUEST_SYMBOL                =2001,
      CONDITION_REQUEST_VOLUME                =2002,
      CONDITION_REQUEST_COMMENT               =2003,
      CONDITION_REQUEST_REASON                =2004,
      CONDITION_REQUEST_PRICE                 =2005,
      CONDITION_REQUEST_VALUE                 =2006,
      CONDITION_REQUEST_PARTY_ID              =2007,
      CONDITION_REQUEST_MARKET_DEVIATION      =2008,
      CONDITION_REQUEST_MARKET_DEVIATION_SPR  =2009,
      CONDITION_REQUEST_EXPERT                =2010,
      CONDITION_REQUEST_SIGNAL                =2011,
      CONDITION_REQUEST_DEALER_LOGIN          =2012,
      CONDITION_REQUEST_SOURCE_LOGIN          =2013,
      CONDITION_REQUEST_DATETIME              =2014,
      CONDITION_REQUEST_DATE                  =2015,
      CONDITION_REQUEST_TIME                  =2016,
      CONDITION_REQUEST_WEEKDAY               =2017,
      CONDITION_REQUEST_FIRST                 =CONDITION_REQUEST_SYMBOL,
      CONDITION_REQUEST_LAST                  =3000,
      //--- position
      CONDITION_POSITION_TICKET               =3001,
      CONDITION_POSITION_VOLUME               =3002,
      CONDITION_POSITION_TYPE                 =3003,
      CONDITION_POSITION_PRICE_OPEN           =3004,
      CONDITION_POSITION_PRICE_CURRENT        =3005,
      CONDITION_POSITION_PROFIT               =3006,
      CONDITION_POSITION_REASON               =3007,
      CONDITION_POSITION_TIME_CREATE          =3008,
      CONDITION_POSITION_TIME_UPDATE          =3009,
      CONDITION_POSITION_EXPERT               =3010,
      CONDITION_POSITION_TIME_CREATE_ELAPSED  =3011,
      CONDITION_POSITION_TIME_UPDATE_ELAPSED  =3012,
      CONDITION_POSITION_COMMENT              =3013,
      CONDITION_POSITION_VALUE                =3014,
      CONDITION_POSITION_SL_TOUCHED           =3015,
      CONDITION_POSITION_TP_TOUCHED           =3016,
      CONDITION_POSITION_AVERAGE_TIME         =3017,
      CONDITION_POSITION_SYMBOL               =3018,
      CONDITION_POSITION_DEALER_LOGIN         =3019,
      CONDITION_POSITION_LOGIN                =3020,
      CONDITION_POSITION_FIRST                =CONDITION_POSITION_TICKET,
      CONDITION_POSITION_LAST                 =4000,
      //--- order
      CONDITION_ORDER_TICKET                  =4001,
      CONDITION_ORDER_ORDER_ID                =4002,
      CONDITION_ORDER_TIME_SETUP              =4005,
      CONDITION_ORDER_TIME_SETUP_ELAPSED      =4006,
      CONDITION_ORDER_TIME_EXPIRATION         =4007,
      CONDITION_ORDER_TYPE                    =4008,
      CONDITION_ORDER_PRICE_ORDER             =4009,
      CONDITION_ORDER_PRICE_TRIGGER           =4010,
      CONDITION_ORDER_PRICE_CURRENT           =4011,
      CONDITION_ORDER_PRICE_SL                =4012,
      CONDITION_ORDER_PRICE_TP                =4013,
      CONDITION_ORDER_VOLUME_INITIAL          =4014,
      CONDITION_ORDER_VOLUME_CURRENT          =4015,
      CONDITION_ORDER_STATE                   =4016,
      CONDITION_ORDER_EXPERT                  =4017,
      CONDITION_ORDER_POSITION_ID             =4018,
      CONDITION_ORDER_COMMENT                 =4019,
      CONDITION_ORDER_CONTRACT_SIZE           =4020,
      CONDITION_ORDER_CURRENCY                =4021,
      CONDITION_ORDER_SL_TOUCHED              =4022,
      CONDITION_ORDER_TP_TOUCHED              =4023,
      CONDITION_ORDER_ENTRY_IN                =4024,
      CONDITION_ORDER_ENTRY_OUT               =4025,
      CONDITION_ORDER_SYMBOL                  =4026,
      CONDITION_ORDER_LOGIN                   =4027,
      CONDITION_ORDER_DEALER_LOGIN            =4028,
      CONDITION_ORDER_PARTY_ID                =4029,
      CONDITION_ORDER_FILLING_TYPE            =4030,
      CONDITION_ORDER_VOLUME_EXECUTED         =4031,
      CONDITION_ORDER_REASON                  =4032,
      CONDITION_ORDER_FIRST                   =CONDITION_ORDER_TICKET,
      CONDITION_ORDER_LAST                    =5000,
      //--- symbol
      CONDITION_SYMBOL_GAP                    =5001,
      CONDITION_SYMBOL_SPREAD                 =5002,
      CONDITION_SYMBOL_FIRST                  =CONDITION_SYMBOL_GAP,
      CONDITION_SYMBOL_LAST                   =6000,
      //--- trading statistics
      CONDITION_STAT_DAILY_DEALS              =6001,
      CONDITION_STAT_DAILY_DEALS_PERIOD       =6002,
      CONDITION_STAT_DAILY_PROFIT             =6003,
      CONDITION_STAT_FIRST                    =CONDITION_STAT_DAILY_DEALS,
      CONDITION_STAT_LAST                     =7000,
      //--- enumeration borders
      CONDITION_FIRST                         =CONDITION_DATETIME_FIRST,
      CONDITION_LAST                          =CONDITION_STAT_LAST
     };
   //--- comparison rule
   enum EnConditionRule
     {
      RULE_EQ                       =0,
      RULE_NOT_EQ                   =1,
      RULE_GREATER                  =2,
      RULE_NOT_LESS                 =3,
      RULE_LESS                     =4,
      RULE_NOT_GREATER              =5,
      RULE_MATCH_MASK               =6,
      //--- enumeration borders
      RULE_FIRST                    =RULE_EQ,
      RULE_LAST                     =RULE_MATCH_MASK
     };
   //--- condition value type
   enum EnConditionType
     {
      TYPE_NONE                     =0,
      TYPE_STRING                   =1,
      TYPE_UINT                     =2,
      TYPE_DOUBLE                   =3,
      TYPE_COLOR                    =4,
      TYPE_MONEY                    =5,
      TYPE_VOLUME                   =6,
      TYPE_DATETIME                 =7,
      TYPE_LEVERAGE                 =8,
      TYPE_BOOL                     =9,
      TYPE_TIME                     =10,
      TYPE_DATE                     =11,
      TYPE_PERCENT                  =12,
      TYPE_LANGUAGE                 =13,
      TYPE_POSITION                 =14,
      TYPE_REASON                   =15,
      TYPE_ORDER                    =16,
      TYPE_ORDER_STATE              =17,
      TYPE_LOGIN                    =18,
      TYPE_DURATION                 =19,
      TYPE_GROUP                    =20,
      TYPE_SYMBOL                   =21,
      TYPE_WEEKDAY                  =22,
      TYPE_INT                      =23,
      TYPE_VOLUME_SIGNED            =24,
      TYPE_FILLING                  =25,
      //--- enumeration borders
      TYPE_FIRST                    =TYPE_NONE,
      TYPE_LAST                     =TYPE_FILLING
     };
   //--- common methods
   virtual void      Release(void)=0;
   virtual MTAPIRES  Assign(const IMTConUltRouteCondition* config)=0;
   virtual MTAPIRES  Clear(void)=0;
   //--- condition
   virtual uint32_t  Condition(void) const=0;
   virtual MTAPIRES  Condition(const uint32_t condition)=0;
   //--- comparison rule
   virtual uint32_t  Rule(void) const=0;
   virtual MTAPIRES  Rule(const uint32_t rule)=0;
   //--- value type
   virtual uint32_t  ValueType(void) const=0;
   //--- raw values
   virtual int64_t   ValueInt(void) const=0;
   virtual MTAPIRES  ValueInt(const int64_t value)=0;
   virtual uint64_t  ValueUInt(void) const=0;
   virtual MTAPIRES  ValueUInt(const uint64_t value)=0;
   virtual double    ValueDouble(void) const=0;
   virtual MTAPIRES  ValueDouble(const double value)=0;
   virtual LPCWSTR   ValueString(void) const=0;
   virtual MTAPIRES  ValueString(LPCWSTR value)=0;
   //--- typed values
   virtual COLORREF  ValueColor(void) const=0;
   virtual MTAPIRES  ValueColor(const COLORREF value)=0;
   virtual double    ValueMoney(void) const=0;
   virtual MTAPIRES  ValueMoney(const double value)=0;
   virtual uint64_t  ValueVolume(void) const=0;
   virtual MTAPIRES  ValueVolume(const uint64_t value)=0;
   virtual int64_t   ValueDatetime(void) const=0;
   virtual MTAPIRES  ValueDatetime(const int64_t value)=0;
   virtual int64_t   ValueLeverage(void) const=0;
   virtual MTAPIRES  ValueLeverage(const int64_t value)=0;
   virtual bool      ValueBool(void) const=0;
   virtual MTAPIRES  ValueBool(const bool value)=0;
   virtual uint32_t  ValueTime(void) const=0;
   virtual MTAPIRES  ValueTime(const uint32_t value)=0;
   virtual uint32_t  ValueWeekDay(void) const=0;
   virtual MTAPIRES  ValueWeekDay(const uint32_t value)=0;
   virtual uint64_t  ValueVolumeExt(void) const=0;
   virtual MTAPIRES  ValueVolumeExt(const uint64_t value)=0;
//--- explicit destructor is prohibited
protected:
                    ~IMTConUltRouteCondition(void) {}
  };
//+------------------------------------------------------------------+
//| Ultency routing configuration                                    |
//+------------------------------------------------------------------+
class IMTConUltRoute
  {
public:
   //--- action
   enum EnAction
     {
      ACTION_SYMBOL                 =1,
      ACTION_REJECT                 =2,
      //--- enumeration borders
      ACTION_FIRST                  =ACTION_SYMBOL,
      ACTION_LAST                   =ACTION_REJECT
     };
   //--- flags
   enum EnFlags
     {
      FLAG_NONE                     =0x00000000,
      FLAG_ENABLED                  =0x00000001,
      //--- enumeration borders
      FLAG_ALL                      =FLAG_ENABLED
     };
   //--- common methods
   virtual void      Release(void)=0;
   virtual MTAPIRES  Assign(const IMTConUltRoute* config)=0;
   virtual MTAPIRES  Clear(void)=0;
   //--- server
   virtual uint64_t  Server(void) const=0;
   virtual MTAPIRES  Server(const uint64_t server)=0;
   //--- name
   virtual LPCWSTR   Name(void) const=0;
   virtual MTAPIRES  Name(LPCWSTR name)=0;
   //--- flags EnFlags
   virtual uint64_t  Flags(void) const=0;
   virtual MTAPIRES  Flags(const uint64_t flags)=0;
   //--- action EnAction
   virtual uint32_t  Action(void) const=0;
   virtual MTAPIRES  Action(const uint32_t action)=0;
   //--- raw action parameters
   virtual int64_t   ParamInt(void) const=0;
   virtual MTAPIRES  ParamInt(const int64_t value)=0;
   virtual uint64_t  ParamUInt(void) const=0;
   virtual MTAPIRES  ParamUInt(const uint64_t value)=0;
   virtual double    ParamDouble(void) const=0;
   virtual MTAPIRES  ParamDouble(const double value)=0;
   virtual LPCWSTR   ParamString(void) const=0;
   virtual MTAPIRES  ParamString(LPCWSTR value)=0;
   //--- action symbol
   virtual LPCWSTR   Symbol(void) const=0;
   virtual MTAPIRES  Symbol(LPCWSTR symbol)=0;
   //--- coverage rate, from 0.0 to 1.0
   virtual double    Coverage(void) const=0;
   virtual MTAPIRES  Coverage(const double coverage)=0;
   //--- minimal coverage volume with extended accuracy
   virtual uint64_t  CoverageVolumeMin(void) const=0;
   virtual MTAPIRES  CoverageVolumeMin(const uint64_t volume)=0;
   //--- conditions
   virtual MTAPIRES  ConditionAdd(IMTConUltRouteCondition* condition)=0;
   virtual MTAPIRES  ConditionUpdate(const uint32_t pos,const IMTConUltRouteCondition* condition)=0;
   virtual MTAPIRES  ConditionDelete(const uint32_t pos)=0;
   virtual MTAPIRES  ConditionClear(void)=0;
   virtual MTAPIRES  ConditionShift(const uint32_t pos,const int32_t shift)=0;
   virtual uint32_t  ConditionTotal(void) const=0;
   virtual MTAPIRES  ConditionNext(const uint32_t pos,IMTConUltRouteCondition* condition) const=0;
//--- explicit destructor is prohibited
protected:
                    ~IMTConUltRoute(void) {}
  };
//+------------------------------------------------------------------+
//| Config events notification interface                             |
//+------------------------------------------------------------------+
class IMTConUltRouteSink
  {
public:
   virtual void      OnUltRouteAdd(const IMTConUltRoute*    /*config*/) {  }
   virtual void      OnUltRouteUpdate(const IMTConUltRoute* /*config*/) {  }
   virtual void      OnUltRouteDelete(const IMTConUltRoute* /*config*/) {  }
   virtual void      OnUltRouteSync(void)                               {  }
  };
//+------------------------------------------------------------------+
