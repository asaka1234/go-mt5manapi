//+------------------------------------------------------------------+
//|                                                 MetaTrader 5 API |
//|                             Copyright 2000-2026, MetaQuotes Ltd. |
//|                                               www.metaquotes.net |
//+------------------------------------------------------------------+
#pragma once
//+------------------------------------------------------------------+
//| Liquidity Symbol config                                          |
//+------------------------------------------------------------------+
class IMTConUltLiquiditySymbol
  {
public:
   //--- flags
   enum EnFlags
     {
      FLAGS_NONE                    =0x0000000,
      FLAGS_QUOTES_ENABLED          =0x0000001,
      FLAGS_TRADE_ENABLED           =0x0000002,
      //--- enumeration borders
      FLAGS_FIRST                   =FLAGS_NONE,
      FLAGS_ALL                     =FLAGS_QUOTES_ENABLED|FLAGS_TRADE_ENABLED,
     };
   //--- allowed filling modes flags
   enum EnTradeFillFlags
     {
      TRADE_FILL_FLAGS_NONE         =0x0000000, // none
      TRADE_FILL_FLAGS_FOK          =0x0000001, // allowed FOK
      TRADE_FILL_FLAGS_IOC          =0x0000002, // allowed IOC
      TRADE_FILL_FLAGS_BOC          =0x0000004, // book or cancel
      //--- enumeration borders
      TRADE_FILL_FLAGS_FIRST        =TRADE_FILL_FLAGS_NONE,
      TRADE_FILL_FLAGS_ALL          =TRADE_FILL_FLAGS_FOK|TRADE_FILL_FLAGS_IOC|TRADE_FILL_FLAGS_BOC
     };
   //--- allowed order time modes flags
   enum EnTradeTimeFlags
     {
      TRADE_TIME_FLAGS_NONE         =0x0000000, // none
      TRADE_TIME_FLAGS_GTC          =0x0000001, // allowed Good Till Cancel
      TRADE_TIME_FLAGS_DAY          =0x0000002, // allowed Good Till Day
      TRADE_TIME_FLAGS_SPECIFIED    =0x0000004, // allowed specified expiration date
      TRADE_TIME_FLAGS_SPECIFIED_DAY=0x0000008, // allowed specified expiration date as day
      //--- enumeration borders
      TRADE_TIME_FLAGS_FIRST        =TRADE_TIME_FLAGS_GTC,
      TRADE_TIME_FLAGS_ALL          =TRADE_TIME_FLAGS_GTC|TRADE_TIME_FLAGS_DAY|TRADE_TIME_FLAGS_SPECIFIED|TRADE_TIME_FLAGS_SPECIFIED_DAY
     };
   //--- allowed order flags
   enum EnTradeOrderFlags
     {
      TRADE_ORDER_FLAGS_NONE        =0,  // none
      TRADE_ORDER_FLAGS_MARKET      =1,  // market orders
      TRADE_ORDER_FLAGS_LIMIT       =2,  // limit orders
      TRADE_ORDER_FLAGS_STOP        =4,  // stop orders
      TRADE_ORDER_FLAGS_STOP_LIMIT  =8,  // stop limit orders
      TRADE_ORDER_FLAGS_SL          =16, // sl orders
      TRADE_ORDER_FLAGS_TP          =32, // tp orders
      TRADE_ORDER_FLAGS_CLOSEBY     =64, // close-by orders
      //--- flags borders
      TRADE_ORDER_FLAGS_FIRST       =TRADE_ORDER_FLAGS_MARKET,
      TRADE_ORDER_FLAGS_ALL         =TRADE_ORDER_FLAGS_MARKET|TRADE_ORDER_FLAGS_LIMIT|TRADE_ORDER_FLAGS_STOP|TRADE_ORDER_FLAGS_STOP_LIMIT|
      TRADE_ORDER_FLAGS_SL|TRADE_ORDER_FLAGS_TP|TRADE_ORDER_FLAGS_CLOSEBY
     };
   //--- order execution modes
   enum EnTradeExecution
     {
      EXECUTION_REQUEST            =0,
      EXECUTION_INSTANT            =1,
      EXECUTION_MARKET             =2,
      EXECUTION_EXCHANGE           =3,
      //--- enumeration borders
      EXECUTION_FIRST              =EXECUTION_REQUEST,
      EXECUTION_LAST               =EXECUTION_EXCHANGE
     };
   //--- profit and margin calculation modes
   enum EnCalcMode
     {
      //--- market maker modes
      CALC_MODE_FOREX               =0,
      CALC_MODE_FUTURES             =1,
      CALC_MODE_CFD                 =2,
      CALC_MODE_CFDINDEX            =3,
      CALC_MODE_CFDLEVERAGE         =4,
      CALC_MODE_FOREX_NO_LEVERAGE   =5,
      //--- exchange modes
      CALC_MODE_EXCH_STOCKS         =32,
      CALC_MODE_EXCH_FUTURES        =33,
      CALC_MODE_EXCH_FUTURES_FORTS  =34,
      CALC_MODE_EXCH_OPTIONS        =35,
      CALC_MODE_EXCH_OPTIONS_MARGIN =36,
      CALC_MODE_EXCH_BONDS          =37,
      CALC_MODE_EXCH_STOCKS_MOEX    =38,
      CALC_MODE_EXCH_BONDS_MOEX     =39,
      //--- enumeration borders
      CALC_MODE_FIRST               =CALC_MODE_FOREX,
      CALC_MODE_LAST                =CALC_MODE_EXCH_BONDS_MOEX
     };
   //--- margin check flags
   enum EnMarginFlags
     {
      MARGIN_FLAGS_NONE             =0x0000000, // none
      MARGIN_FLAGS_HEDGE_LARGE_LEG  =0x0000001, // check margin for hedged positions using large leg
      MARGIN_FLAGS_EXCLUDE_PL       =0x0000002, // exclude buy positions PL from free margin and margin level calculation
      MARGIN_FLAGS_RECALC_RATES     =0x0000004, // recalculate margin exchange rate on the End of Day
      //--- enumeration borders
      MARGIN_FLAGS_ALL              =MARGIN_FLAGS_HEDGE_LARGE_LEG|MARGIN_FLAGS_EXCLUDE_PL|MARGIN_FLAGS_RECALC_RATES
     };
   //--- swaps calculation modes
   enum EnSwapMode
     {
      SWAP_DISABLED                 =0,
      SWAP_BY_POINTS                =1,
      SWAP_BY_SYMBOL_CURRENCY       =2,
      SWAP_BY_MARGIN_CURRENCY       =3,
      SWAP_BY_GROUP_CURRENCY        =4,
      SWAP_BY_INTEREST_CURRENT      =5,
      SWAP_BY_INTEREST_OPEN         =6,
      SWAP_REOPEN_BY_CLOSE_PRICE    =7,
      SWAP_REOPEN_BY_BID            =8,
      SWAP_BY_PROFIT_CURRENCY       =9,
      //--- enumeration borders
      SWAP_FIRST                    =SWAP_DISABLED,
      SWAP_LAST                     =SWAP_BY_PROFIT_CURRENCY
     };
   //--- swap flags
   enum EnSwapFlags
     {
      SWAP_FLAGS_NONE                =0x00000000,
      SWAP_FLAGS_CONSIDER_HOLIDAYS   =0x00000001,
      //--- enumeration borders
      SWAP_FLAGS_DEFAULT             =SWAP_FLAGS_NONE,
      SWAP_FLAGS_ALL                 =SWAP_FLAGS_CONSIDER_HOLIDAYS
     };

   //--- common methods
   virtual void      Release(void)=0;
   virtual MTAPIRES  Assign(const IMTConUltLiquiditySymbol* symbol)=0;
   virtual MTAPIRES  Clear(void)=0;
   //--- id
   virtual uint32_t  ID(void) const=0;
   virtual MTAPIRES  ID(const uint32_t id)=0;
   //--- liquiduty id
   virtual uint32_t  LiquidityID(void) const=0;
   virtual MTAPIRES  LiquidityID(const uint32_t id)=0;
   //--- name
   virtual LPCWSTR   Symbol(void) const=0;
   virtual MTAPIRES  Symbol(LPCWSTR symbol)=0;
   //--- source symbol name
   virtual LPCWSTR   Source(void) const=0;
   virtual MTAPIRES  Source(LPCWSTR source)=0;
   //--- hierarchical symbol path (including symbol name)
   virtual LPCWSTR   Path(void) const=0;
   virtual MTAPIRES  Path(LPCWSTR path)=0;
   //--- coverage symbol name
   virtual LPCWSTR   Coverage(void) const=0;
   virtual MTAPIRES  Coverage(LPCWSTR coverage)=0;
   //--- local description
   virtual LPCWSTR   Description(void) const=0;
   virtual MTAPIRES  Description(LPCWSTR descr)=0;
   //--- symbol base currency
   virtual LPCWSTR   CurrencyBase(void) const=0;
   virtual MTAPIRES  CurrencyBase(LPCWSTR currency)=0;
   virtual uint32_t  CurrencyBaseDigits(void) const=0;
   virtual MTAPIRES  CurrencyBaseDigits(const uint32_t digits)=0;
   //--- symbol profit currency
   virtual LPCWSTR   CurrencyProfit(void) const=0;
   virtual MTAPIRES  CurrencyProfit(LPCWSTR currency)=0;
   virtual uint32_t  CurrencyProfitDigits(void) const=0;
   virtual MTAPIRES  CurrencyProfitDigits(const uint32_t digits)=0;
   //--- symbol margin currency
   virtual LPCWSTR   CurrencyMargin(void) const=0;
   virtual MTAPIRES  CurrencyMargin(LPCWSTR currency)=0;
   virtual uint32_t  CurrencyMarginDigits(void) const=0;
   virtual MTAPIRES  CurrencyMarginDigits(const uint32_t digits)=0;
   //--- symbol digits
   virtual uint32_t  QuotesDigits(void) const=0;
   virtual MTAPIRES  QuotesDigits(const uint32_t digits)=0;
   //--- book depth
   virtual uint32_t  QuotesDepth(void) const=0;
   virtual MTAPIRES  QuotesDepth(const uint32_t depth)=0;
   //--- bid markup
   virtual int32_t   QuotesMarkupBid(void) const=0;
   virtual MTAPIRES  QuotesMarkupBid(const int32_t markup)=0;
   //--- ask markup
   virtual int32_t   QuotesMarkupAsk(void) const=0;
   virtual MTAPIRES  QuotesMarkupAsk(const int32_t markup)=0;
   //--- filtration deviation level
   virtual uint32_t  QuotesFilterDeviation(void) const=0;
   virtual MTAPIRES  QuotesFilterDeviation(const uint32_t filter)=0;
   //--- filtration MA period
   virtual uint32_t  QuotesFilterMA(void) const=0;
   virtual MTAPIRES  QuotesFilterMA(const uint32_t period)=0;
   //--- parameters
   virtual MTAPIRES  QuotesFilterLPAdd(const uint64_t lp)=0;
   virtual MTAPIRES  QuotesFilterLPUpdate(const uint32_t pos,const uint64_t lp)=0;
   virtual MTAPIRES  QuotesFilterLPDelete(const uint32_t pos)=0;
   virtual MTAPIRES  QuotesFilterLPClear(void)=0;
   virtual MTAPIRES  QuotesFilterLPShift(const uint32_t pos,const int32_t shift)=0;
   virtual uint32_t  QuotesFilterLPTotal(void) const=0;
   virtual MTAPIRES  QuotesFilterLPNext(const uint32_t pos,uint64_t& lp) const=0;
   //--- price limit max
   virtual double    TradePriceLimitMax(void) const=0;
   virtual MTAPIRES  TradePriceLimitMax(const double price)=0;
   //--- price limit min
   virtual double    TradePriceLimitMin(void) const=0;
   virtual MTAPIRES  TradePriceLimitMin(const double price)=0;
   //--- EnTradeFillFlags
   virtual uint32_t  TradeFillFlags(void) const=0;
   virtual MTAPIRES  TradeFillFlags(const uint32_t flags)=0;
   //--- EnTradeTimeFlags
   virtual uint32_t  TradeTimeFlags(void) const=0;
   virtual MTAPIRES  TradeTimeFlags(const uint32_t flags)=0;
   //--- EnTradeOrderFlags
   virtual uint32_t  TradeOrderFlags(void) const=0;
   virtual MTAPIRES  TradeOrderFlags(const uint32_t flags)=0;
   //--- minimal volume
   virtual uint64_t  TradeVolumeMin(void) const=0;
   virtual MTAPIRES  TradeVolumeMin(const uint64_t volume)=0;
   //--- maximal volume
   virtual uint64_t  TradeVolumeMax(void) const=0;
   virtual MTAPIRES  TradeVolumeMax(const uint64_t volume)=0;
   //--- volume step
   virtual uint64_t  TradeVolumeStep(void) const=0;
   virtual MTAPIRES  TradeVolumeStep(const uint64_t volume)=0;
   //--- cumulative positions and orders limit
   virtual uint64_t  TradeVolumeLimit(void) const=0;
   virtual MTAPIRES  TradeVolumeLimit(const uint64_t volume)=0;
   //--- EnExecutionMode
   virtual uint32_t  TradeExecMode(void) const=0;
   virtual MTAPIRES  TradeExecMode(const uint32_t mode)=0;
   //--- EnCalcMode
   virtual uint32_t  CalcMode(void) const=0;
   virtual MTAPIRES  CalcMode(const uint32_t mode)=0;
   //--- name
   virtual LPCWSTR   CalcBasis(void) const=0;
   virtual MTAPIRES  CalcBasis(LPCWSTR basis)=0;
   //--- contract size
   virtual double    CalcContractSize(void) const=0;
   virtual MTAPIRES  CalcContractSize(const double size)=0;
   //--- tick value
   virtual double    CalcTickValue(void) const=0;
   virtual MTAPIRES  CalcTickValue(const double value)=0;
   //--- tick size
   virtual double    CalcTickSize(void) const=0;
   virtual MTAPIRES  CalcTickSize(const double size)=0;
   //--- settle price (for futures)
   virtual double    CalcPriceSettle(void) const=0;
   virtual MTAPIRES  CalcPriceSettle(const double price)=0;
   //--- bond face value
   virtual double    CalcFaceValue(void) const=0;
   virtual MTAPIRES  CalcFaceValue(const double value)=0;
   //--- bond accrued interest
   virtual double    CalcAccruedInterest(void) const=0;
   virtual MTAPIRES  CalcAccruedInterest(const double interest)=0;
   //--- EnMarginFlags
   virtual uint32_t  MarginFlags(void) const=0;
   virtual MTAPIRES  MarginFlags(const uint32_t mode)=0;
   //--- initial margin
   virtual double    MarginInitial(void) const=0;
   virtual MTAPIRES  MarginInitial(const double margin)=0;
   //--- maintenance margin
   virtual double    MarginMaintenance(void) const=0;
   virtual MTAPIRES  MarginMaintenance(const double margin)=0;
   //--- hedged positions margin rate
   virtual double    MarginHedged(void) const=0;
   virtual MTAPIRES  MarginHedged(const double margin)=0;
   //--- liquidity rate
   virtual double    MarginRateLiquidity(void) const=0;
   virtual MTAPIRES  MarginRateLiquidity(const double margin_rate)=0;
   //--- currency rate
   virtual double    MarginRateCurrency(void) const=0;
   virtual MTAPIRES  MarginRateCurrency(const double margin_rate)=0;
   //--- orders and positions margin rates
   virtual double    MarginRateInitial(const uint32_t type) const=0;
   virtual MTAPIRES  MarginRateInitial(const uint32_t type,const double margin_rate)=0;
   //--- orders and positions margin rates
   virtual double    MarginRateMaintenance(const uint32_t type) const=0;
   virtual MTAPIRES  MarginRateMaintenance(const uint32_t type,const double margin_rate)=0;
   //--- EnSwapMode
   virtual uint32_t  SwapMode(void) const=0;
   virtual MTAPIRES  SwapMode(const uint32_t mode)=0;
   //--- long positions swaps rate
   virtual double    SwapLong(void) const=0;
   virtual MTAPIRES  SwapLong(const double swap)=0;
   //--- short positions swaps rate
   virtual double    SwapShort(void) const=0;
   virtual MTAPIRES  SwapShort(const double swap)=0;
   //--- Days in year
   virtual uint32_t  SwapYearDays(void) const=0;
   virtual MTAPIRES  SwapYearDays(const uint32_t days)=0;
   //--- swap flags
   virtual uint32_t  SwapFlags(void) const=0;
   virtual MTAPIRES  SwapFlags(const uint32_t flags)=0;
   //--- swap rate for Sunday
   virtual double    SwapRateSunday(void) const=0;
   virtual MTAPIRES  SwapRateSunday(const double rate)=0;
   //--- swap rate for Monday
   virtual double    SwapRateMonday(void) const=0;
   virtual MTAPIRES  SwapRateMonday(const double rate)=0;
   //--- swap rate for Tuesday
   virtual double    SwapRateTuesday(void) const=0;
   virtual MTAPIRES  SwapRateTuesday(const double rate)=0;
   //--- swap rate for Wednesday
   virtual double    SwapRateWednesday(void) const=0;
   virtual MTAPIRES  SwapRateWednesday(const double rate)=0;
   //--- swap rate for Thursday
   virtual double    SwapRateThursday(void) const=0;
   virtual MTAPIRES  SwapRateThursday(const double rate)=0;
   //--- swap rate for Friday
   virtual double    SwapRateFriday(void) const=0;
   virtual MTAPIRES  SwapRateFriday(const double rate)=0;
   //--- swap rate for Saturday
   virtual double    SwapRateSaturday(void) const=0;
   virtual MTAPIRES  SwapRateSaturday(const double rate)=0;
   //--- trade start date
   virtual int64_t   TimeStart(void) const=0;
   virtual MTAPIRES  TimeStart(const int64_t start)=0;
   //--- trade end date
   virtual int64_t   TimeExpiration(void) const=0;
   virtual MTAPIRES  TimeExpiration(const int64_t expiration)=0;
   //--- quote sessions
   virtual MTAPIRES  SessionQuoteAdd(const uint32_t wday,IMTConSymbolSession* symbol)=0;
   virtual MTAPIRES  SessionQuoteUpdate(const uint32_t wday,const uint32_t pos,const IMTConSymbolSession* session)=0;
   virtual MTAPIRES  SessionQuoteDelete(const uint32_t wday,const uint32_t pos)=0;
   virtual MTAPIRES  SessionQuoteClear(const uint32_t wday)=0;
   virtual MTAPIRES  SessionQuoteShift(const uint32_t wday,const uint32_t pos,const int32_t shift)=0;
   virtual uint32_t  SessionQuoteTotal(const uint32_t wday) const=0;
   virtual MTAPIRES  SessionQuoteNext(const uint32_t wday,const uint32_t pos,IMTConSymbolSession* session) const=0;
   //--- trade sessions
   virtual MTAPIRES  SessionTradeAdd(const uint32_t wday,IMTConSymbolSession* symbol)=0;
   virtual MTAPIRES  SessionTradeUpdate(const uint32_t wday,const uint32_t pos,const IMTConSymbolSession* session)=0;
   virtual MTAPIRES  SessionTradeDelete(const uint32_t wday,const uint32_t pos)=0;
   virtual MTAPIRES  SessionTradeClear(const uint32_t wday)=0;
   virtual MTAPIRES  SessionTradeShift(const uint32_t wday,const uint32_t pos,const int32_t shift)=0;
   virtual uint32_t  SessionTradeTotal(const uint32_t wday) const=0;
   virtual MTAPIRES  SessionTradeNext(const uint32_t wday,const uint32_t pos,IMTConSymbolSession* session) const=0;
   //--- server id
   virtual uint64_t  Server(void) const=0;
   virtual MTAPIRES  Server(const uint64_t server)=0;
   //--- explicit destructor is prohibited
protected:
                    ~IMTConUltLiquiditySymbol(void) {}
  };
//+------------------------------------------------------------------+
//| Symbol  configuration array interface                            |
//+------------------------------------------------------------------+
class IMTConUltLiquiditySymbolArray
  {
public:
   //--- common methods
   virtual void      Release(void)=0;
   virtual MTAPIRES  Assign(const IMTConUltLiquiditySymbolArray* array)=0;
   virtual MTAPIRES  Clear(void)=0;
   //--- add
   virtual MTAPIRES  Add(IMTConUltLiquiditySymbol* record)=0;
   virtual MTAPIRES  AddCopy(const IMTConUltLiquiditySymbol* record)=0;
   virtual MTAPIRES  Add(IMTConUltLiquiditySymbolArray* array)=0;
   virtual MTAPIRES  AddCopy(const IMTConUltLiquiditySymbolArray* array)=0;
   //--- delete & detach
   virtual MTAPIRES  Delete(const uint32_t pos)=0;
   virtual IMTConUltLiquiditySymbol* Detach(const uint32_t pos)=0;
   //--- update
   virtual MTAPIRES  Update(const uint32_t pos,IMTConUltLiquiditySymbol* record)=0;
   virtual MTAPIRES  UpdateCopy(const uint32_t pos,const IMTConUltLiquiditySymbol* record)=0;
   virtual MTAPIRES  Shift(const uint32_t pos,const int32_t shift)=0;
   //--- data access
   virtual uint32_t  Total(void) const=0;
   virtual IMTConUltLiquiditySymbol*  Next(const uint32_t index) const=0;
   //--- sorting and search
   virtual MTAPIRES  Sort(MTSortFunctionPtr sort_function)=0;
   virtual int32_t   Search(const void *key,MTSortFunctionPtr sort_function) const=0;
   virtual int32_t   SearchGreatOrEq(const void *key,MTSortFunctionPtr sort_function) const=0;
   virtual int32_t   SearchGreater(const void *key,MTSortFunctionPtr sort_function) const=0;
   virtual int32_t   SearchLessOrEq(const void *key,MTSortFunctionPtr sort_function) const=0;
   virtual int32_t   SearchLess(const void *key,MTSortFunctionPtr sort_function) const=0;
   virtual int32_t   SearchLeft(const void *key,MTSortFunctionPtr sort_function) const=0;
   virtual int32_t   SearchRight(const void *key,MTSortFunctionPtr sort_function) const=0;
   //--- explicit destructor is prohibited
protected:
                    ~IMTConUltLiquiditySymbolArray(void) {}
  };
//+------------------------------------------------------------------+
//| Config events notification interface                             |
//+------------------------------------------------------------------+
class IMTConUltLiquiditySymbolSink
  {
public:
   virtual void      OnUltLiquiditySymbolAdd(const IMTConUltLiquiditySymbol*    /*config*/) {  }
   virtual void      OnUltLiquiditySymbolUpdate(const IMTConUltLiquiditySymbol* /*config*/) {  }
   virtual void      OnUltLiquiditySymbolDelete(const IMTConUltLiquiditySymbol* /*config*/) {  }
   virtual void      OnUltLiquiditySymbolSync(void)                                          {  }
  };
//+------------------------------------------------------------------+
