//+------------------------------------------------------------------+
//|                                                 MetaTrader 5 API |
//|                             Copyright 2000-2026, MetaQuotes Ltd. |
//|                                               www.metaquotes.net |
//+------------------------------------------------------------------+
#pragma once
//+------------------------------------------------------------------+
//| Passkey credential interface                                     |
//+------------------------------------------------------------------+
class IMTPasskey
  {
public:
   //--- additional flags
   enum EnFlags
     {
      FLAG_NONE             =0x0000000000000000,  // none
      FLAG_CONFIRMED        =0x0000000000000001,  // confirmed by manager for user/client
      //--- enumeration borders
      FLAG_ALL              =FLAG_CONFIRMED
     };
   //--- common methods
   virtual void      Release(void)=0;
   virtual MTAPIRES  Assign(const IMTPasskey *passkey)=0;
   virtual MTAPIRES  Clear(void)=0;
   //--- unique id in credentials base
   virtual uint64_t  ID(void) const=0;
   //--- flags
   virtual uint32_t  Flags(void) const=0;
   //--- login
   virtual uint64_t  Login(void) const=0;
   //--- password type login
   virtual uint32_t  PasswordType(void) const=0;
   //--- creation time
   virtual int64_t   TimeCreated(void) const=0;
   //--- device name
   virtual MTAPIRES  DeviceName(MTAPISTR& name) const=0;
   //--- Domain
   virtual MTAPIRES  Domain(MTAPISTR& domain) const=0;
   //--- Algorithm
   virtual uint32_t  Algorithm(void) const=0;
   //--- explicit destructor is prohibited
protected:
                    ~IMTPasskey(void) {}
  };
//+------------------------------------------------------------------+
//| Passkey credential array interface                               |
//+------------------------------------------------------------------+
class IMTPasskeyArray
  {
public:
   //--- common methods
   virtual void      Release(void)=0;
   virtual MTAPIRES  Assign(const IMTPasskeyArray* array)=0;
   virtual MTAPIRES  Clear(void)=0;
   //--- add
   virtual MTAPIRES  Add(IMTPasskey* passkey)=0;
   virtual MTAPIRES  AddCopy(const IMTPasskey* passkey)=0;
   virtual MTAPIRES  Add(IMTPasskeyArray* array)=0;
   virtual MTAPIRES  AddCopy(const IMTPasskeyArray* passkey)=0;
   //--- delete & detach
   virtual MTAPIRES  Delete(const uint32_t pos)=0;
   virtual IMTPasskey* Detach(const uint32_t pos)=0;
   //--- update
   virtual MTAPIRES  Update(const uint32_t pos,IMTPasskey* passkey)=0;
   virtual MTAPIRES  UpdateCopy(const uint32_t pos,const IMTPasskey* passkey)=0;
   virtual MTAPIRES  Shift(const uint32_t pos,const int32_t shift)=0;
   //--- data access
   virtual uint32_t  Total(void) const=0;
   virtual IMTPasskey* Next(const uint32_t index) const=0;
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
                    ~IMTPasskeyArray(void) {}
  };
//+------------------------------------------------------------------+