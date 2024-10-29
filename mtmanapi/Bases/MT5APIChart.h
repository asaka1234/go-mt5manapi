//+------------------------------------------------------------------+
//|                                                 MetaTrader 5 API |
//|                             Copyright 2000-2024, MetaQuotes Ltd. |
//|                                               www.metaquotes.net |
//+------------------------------------------------------------------+
#pragma once
//+------------------------------------------------------------------+
//| History split rounding methods                                   |
//+------------------------------------------------------------------+
enum EnSplitRounding
  {
   SPLIT_ROUNDING_STANDARD=0,  // standard mathematical rounding
   SPLIT_ROUNDING_DOWN    =1,  // round half up
   SPLIT_ROUNDING_UP      =2,  // round half down
//--- enumeration borders
   SPLIT_ROUNDING_FIRST   =SPLIT_ROUNDING_STANDARD,
   SPLIT_ROUNDING_LAST    =SPLIT_ROUNDING_UP
  };
//+------------------------------------------------------------------+
//| History bar description                                          |
//+------------------------------------------------------------------+
#pragma pack(push,1)
struct MTChartBar
  {
   INT64             datetime;          // datetime
   //--- prices
   double            open;              // open price
   double            high;              // high price
   double            low;               // low price
   double            close;             // close price
   //--- volumes
   UINT64            tick_volume;       // tick volume
   INT32             spread;            // spread
   UINT64            volume;            // volume
  };
#pragma pack(pop)
//+------------------------------------------------------------------+
//| Chart events notification interface                              |
//+------------------------------------------------------------------+
class IMTChartSink
  {
public:
   //--- split
   virtual void      OnChartSplit(LPCWSTR symbol,const double new_shares,const double old_shares,const UINT rounding_rule,const INT64 datetime_from,const INT64 datetime_to)   {}
   virtual MTAPIRES  HookChartSplit(LPCWSTR symbol,const double new_shares,const double old_shares,const UINT rounding_rule,const INT64 datetime_from,const INT64 datetime_to) { return(MT_RET_OK); }
  };
//+------------------------------------------------------------------+

