//+------------------------------------------------------------------+
//|                                                 MetaTrader 5 API |
//|                             Copyright 2000-2026, MetaQuotes Ltd. |
//|                                               www.metaquotes.net |
//+------------------------------------------------------------------+
#pragma once
#include "MT5APITime.h"
//+------------------------------------------------------------------+
//| Period management functions                                      |
//+------------------------------------------------------------------+
class SMTPeriod
  {
public:
   //--- period types
   enum EnHistoryPeriodTypes
     {
      HISTORY_PERIOD_TYPE_MINUTE=0,
      HISTORY_PERIOD_TYPE_HOUR  =1,
      HISTORY_PERIOD_TYPE_WEEK  =2,
      HISTORY_PERIOD_TYPE_MONTH =3
     };

   //--- predefined period constants
   static constexpr MTPERIOD MTPERIOD_M1 =1;
   static constexpr MTPERIOD MTPERIOD_M2 =2;
   static constexpr MTPERIOD MTPERIOD_M3 =3;
   static constexpr MTPERIOD MTPERIOD_M4 =4;
   static constexpr MTPERIOD MTPERIOD_M5 =5;
   static constexpr MTPERIOD MTPERIOD_M6 =6;
   static constexpr MTPERIOD MTPERIOD_M10=10;
   static constexpr MTPERIOD MTPERIOD_M12=12;
   static constexpr MTPERIOD MTPERIOD_M15=15;
   static constexpr MTPERIOD MTPERIOD_M20=20;
   static constexpr MTPERIOD MTPERIOD_M30=30;
   static constexpr MTPERIOD MTPERIOD_H1 =1 |(HISTORY_PERIOD_TYPE_HOUR <<14);
   static constexpr MTPERIOD MTPERIOD_H2 =2 |(HISTORY_PERIOD_TYPE_HOUR <<14);
   static constexpr MTPERIOD MTPERIOD_H3 =3 |(HISTORY_PERIOD_TYPE_HOUR <<14);
   static constexpr MTPERIOD MTPERIOD_H4 =4 |(HISTORY_PERIOD_TYPE_HOUR <<14);
   static constexpr MTPERIOD MTPERIOD_H6 =6 |(HISTORY_PERIOD_TYPE_HOUR <<14);
   static constexpr MTPERIOD MTPERIOD_H8 =8 |(HISTORY_PERIOD_TYPE_HOUR <<14);
   static constexpr MTPERIOD MTPERIOD_H12=12|(HISTORY_PERIOD_TYPE_HOUR <<14);
   static constexpr MTPERIOD MTPERIOD_D1 =24|(HISTORY_PERIOD_TYPE_HOUR <<14);
   static constexpr MTPERIOD MTPERIOD_W1 =1 |(HISTORY_PERIOD_TYPE_WEEK <<14);
   static constexpr MTPERIOD MTPERIOD_MON1=1|(HISTORY_PERIOD_TYPE_MONTH<<14);

   //--- period using masks
   static constexpr MTPERIOD MTPERIOD_TYPE_MASK=0xC000;
   static constexpr MTPERIOD MTPERIOD_SIZE_MASK=0x3FFF;

   //--- period type and size
   static constexpr EnHistoryPeriodTypes PeriodType(const MTPERIOD period) { return(EnHistoryPeriodTypes((period&MTPERIOD_TYPE_MASK)>>14)); }
   static constexpr uint16_t PeriodSize(const MTPERIOD period)             { return(period&MTPERIOD_SIZE_MASK); }

   //--- period duration in seconds
   static constexpr int64_t PeriodSeconds(MTPERIOD period);
   //--- period begin time
   static int64_t    PeriodBegin(MTPERIOD period,int64_t time_value);

private:
   //--- weekly period begin time
   static int64_t    PeriodWeekBegin(int64_t time_value);
   //--- monthly period begin time
   static int64_t    PeriodMonthBegin(int64_t time_value);
  };
//+------------------------------------------------------------------+
//| Period duration in seconds                                       |
//+------------------------------------------------------------------+
inline constexpr int64_t SMTPeriod::PeriodSeconds(const MTPERIOD period)
  {
//--- by period type
   switch(PeriodType(period))
     {
      case HISTORY_PERIOD_TYPE_MINUTE:
         return(SECONDS_IN_MINUTE*PeriodSize(period));

      case HISTORY_PERIOD_TYPE_HOUR:
         return(SECONDS_IN_HOUR*PeriodSize(period));

      case HISTORY_PERIOD_TYPE_WEEK:
         return(SECONDS_IN_WEEK*PeriodSize(period));

      case HISTORY_PERIOD_TYPE_MONTH:
         return(SECONDS_IN_MONTH*PeriodSize(period));
     }
//--- unknown period type
   return(0);
  }
//+------------------------------------------------------------------+
//| Period begin time                                                |
//+------------------------------------------------------------------+
inline int64_t SMTPeriod::PeriodBegin(const MTPERIOD period,const int64_t time_value)
  {
//--- by period type
   switch(PeriodType(period))
     {
      case HISTORY_PERIOD_TYPE_MINUTE:
      case HISTORY_PERIOD_TYPE_HOUR:
         return(time_value-time_value%PeriodSeconds(period));

      case HISTORY_PERIOD_TYPE_WEEK:
         return(PeriodWeekBegin(time_value));

      case HISTORY_PERIOD_TYPE_MONTH:
         return(PeriodMonthBegin(time_value));
     }
//--- unknown period type
   return(0);
  }
//+------------------------------------------------------------------+
//| Weekly period begin time                                         |
//+------------------------------------------------------------------+
inline int64_t SMTPeriod::PeriodWeekBegin(const int64_t time_value)
  {
   if(time_value<=0)
      return(0);
//--- calculate the time elapsed since the start of the week in seconds
   int64_t shift=time_value%SECONDS_IN_WEEK;
//--- adjust - three days back or four days forward
   shift+=(shift>=(3*SECONDS_IN_DAY))?(-3*SECONDS_IN_DAY):(4*SECONDS_IN_DAY);
//--- subtract the offset from the start of the week
   return(time_value-shift);
  }
//+------------------------------------------------------------------+
//| Monthly period begin time                                        |
//+------------------------------------------------------------------+
inline int64_t SMTPeriod::PeriodMonthBegin(const int64_t time_value)
  {
   if(time_value<=0)
      return(0);
//---
   tm ttm;
//--- parse time
   SMTTime::ParseTime(time_value,&ttm);
//--- period begin
   ttm.tm_mday =1;
   ttm.tm_hour =0;
   ttm.tm_min  =0;
   ttm.tm_sec  =0;
   ttm.tm_isdst=0;
//--- time in seconds
   return(SMTTime::MakeTime(&ttm));
  }
//+------------------------------------------------------------------+
