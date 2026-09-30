//+------------------------------------------------------------------+
//|                                                 MetaTrader 5 API |
//|                             Copyright 2000-2026, MetaQuotes Ltd. |
//|                                               www.metaquotes.net |
//+------------------------------------------------------------------+
#pragma once
//+------------------------------------------------------------------+
//| Ultency symbol group configuration                               |
//+------------------------------------------------------------------+
class IMTConUltSymbolGroup
  {
public:
   //--- common methods
   virtual void      Release(void)=0;
   virtual MTAPIRES  Assign(const IMTConUltSymbolGroup* config)=0;
   virtual MTAPIRES  Clear(void)=0;
   //--- server
   virtual uint64_t  Server(void) const=0;
   virtual MTAPIRES  Server(const uint64_t server)=0;
   //--- name
   virtual LPCWSTR   Name(void) const=0;
   virtual MTAPIRES  Name(LPCWSTR name)=0;
//--- explicit destructor is prohibited
protected:
                    ~IMTConUltSymbolGroup(void) {}
  };
//+------------------------------------------------------------------+
//| Config events notification interface                             |
//+------------------------------------------------------------------+
class IMTConUltSymbolGroupSink
  {
public:
   virtual void      OnUltSymbolGroupAdd(const IMTConUltSymbolGroup*    /*config*/) {  }
   virtual void      OnUltSymbolGroupUpdate(const IMTConUltSymbolGroup* /*config*/) {  }
   virtual void      OnUltSymbolGroupDelete(const IMTConUltSymbolGroup* /*config*/) {  }
   virtual void      OnUltSymbolGroupSync(void)                                      {  }
  };
//+------------------------------------------------------------------+
