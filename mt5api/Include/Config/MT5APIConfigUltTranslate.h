//+------------------------------------------------------------------+
//|                                                 MetaTrader 5 API |
//|                             Copyright 2000-2026, MetaQuotes Ltd. |
//|                                               www.metaquotes.net |
//+------------------------------------------------------------------+
#pragma once
#include "MT5APIConfigParam.h"
//+------------------------------------------------------------------+
//| Liquidity Symbol translations                                    |
//+------------------------------------------------------------------+
class IMTConUltTranslate
  {
public:
   //--- mode
   enum EnMode
     {
      TRANSLATE_DISABLED   =0,
      TRANSLATE_ENABLED    =1,
      //--- enumeration borders
      TRANSLATE_FIRST      =TRANSLATE_DISABLED,
      TRANSLATE_LAST       =TRANSLATE_ENABLED,
     };
   //--- common methods
   virtual void      Release(void)=0;
   virtual MTAPIRES  Assign(const IMTConUltTranslate* param)=0;
   virtual MTAPIRES  Clear(void)=0;
   //--- id
   virtual uint32_t  ID(void) const=0;
   virtual MTAPIRES  ID(const uint32_t id)=0;
   //--- server
   virtual uint64_t  Server(void) const=0;
   virtual MTAPIRES  Server(const uint64_t server)=0;
   //--- EnMode
   virtual uint32_t  Mode(void) const=0;
   virtual MTAPIRES  Mode(const uint32_t mode)=0;
   //--- source
   virtual LPCWSTR   SourcePath(void) const=0;
   virtual MTAPIRES  SourcePath(LPCWSTR path)=0;
   //--- source
   virtual LPCWSTR   Source(void) const=0;
   virtual MTAPIRES  Source(LPCWSTR path)=0;
   //--- mt5 symbol
   virtual LPCWSTR   SymbolPath(void) const=0;
   virtual MTAPIRES  SymbolPath(LPCWSTR path)=0;
   //--- mt5 symbol
   virtual LPCWSTR   Symbol(void) const=0;
   virtual MTAPIRES  Symbol(LPCWSTR path)=0;
   //--- markup
   virtual int32_t   MarkupBid(void) const=0;
   virtual MTAPIRES  MarkupBid(const int32_t markup)=0;
   //--- markup
   virtual int32_t   MarkupAsk(void) const=0;
   virtual MTAPIRES  MarkupAsk(const int32_t markup)=0;
protected:
                    ~IMTConUltTranslate(void) {}
  };
//+------------------------------------------------------------------+
//| Config events notification interface                             |
//+------------------------------------------------------------------+
class IMTConUltTranslateSink
  {
public:
   virtual void      OnUltTranslateAdd(const IMTConUltTranslate*    /*config*/) {  }
   virtual void      OnUltTranslateUpdate(const IMTConUltTranslate* /*config*/) {  }
   virtual void      OnUltTranslateDelete(const IMTConUltTranslate* /*config*/) {  }
   virtual void      OnUltTranslateSync(void)                                  {  }
  };
//+------------------------------------------------------------------+
