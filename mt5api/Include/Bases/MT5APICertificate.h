//+------------------------------------------------------------------+
//|                                                 MetaTrader 5 API |
//|                             Copyright 2000-2026, MetaQuotes Ltd. |
//|                                               www.metaquotes.net |
//+------------------------------------------------------------------+
#pragma once
//+------------------------------------------------------------------+
//| SSL certificate interface                                        |
//+------------------------------------------------------------------+
class IMTCertificate
  {
public:
   //--- additional flags for credentials base
   enum EnCredentialFlags
     {
      CREDENTIAL_FLAG_NONE             =0x0000000000000000,  // none
      CREDENTIAL_FLAG_CONFIRMED        =0x0000000000000001,  // certificate confirmed by manager for user/client
      //--- enumeration borders
      CREDENTIAL_FLAG_ALL              =CREDENTIAL_FLAG_CONFIRMED
     };
   //--- common methods
   virtual void      Release(void)=0;
   virtual MTAPIRES  Assign(const IMTCertificate *certificate)=0;
   virtual MTAPIRES  Clear(void)=0;
   //--- certificate open/save/close/raw access
   virtual MTAPIRES  Open(LPCWSTR filename)=0;
   virtual MTAPIRES  OpenMemory(const void *data,const uint32_t size)=0;
   virtual MTAPIRES  Save(LPCWSTR filename) const=0;
   virtual MTAPIRES  Close(void)=0;
   virtual LPCVOID   Raw(void) const=0;
   virtual uint32_t  RawSize(void) const=0;
   virtual MTAPIRES  CommonReserved1(void)=0;
   virtual MTAPIRES  CommonReserved2(void)=0;
   virtual MTAPIRES  CommonReserved3(void)=0;
   virtual MTAPIRES  CommonReserved4(void)=0;
   virtual MTAPIRES  CommonReserved5(void)=0;
   //--- certificate properties
   virtual bool      IsOpened(void) const=0;
   virtual bool      IsRoot(void) const=0;
   virtual bool      IsCA(void) const=0;
   virtual bool      IsEqual(const IMTCertificate *certificate)=0;
   virtual bool      IsReserved1(void)=0;
   virtual bool      IsReserved2(void)=0;
   virtual bool      IsReserved3(void)=0;
   virtual bool      IsReserved4(void)=0;
   virtual bool      IsReserved5(void)=0;
   //--- certificate number and fields
   virtual uint64_t  SerialNumber(void) const=0;
   virtual int64_t   ValidFrom(void) const=0;
   virtual int64_t   ValidTo(void) const=0;
   virtual MTAPIRES  NameCommon(MTAPISTR& name) const=0;
   virtual MTAPIRES  NameIssuer(MTAPISTR& name) const=0;
   virtual MTAPIRES  NameOrganization(MTAPISTR& name) const=0;
   virtual MTAPIRES  NameOrganizationUnit(MTAPISTR& name) const=0;
   virtual MTAPIRES  NameGiven(MTAPISTR& name) const=0;
   virtual MTAPIRES  NameReserved1(void) const=0;
   virtual MTAPIRES  NameReserved2(void) const=0;
   virtual MTAPIRES  NameReserved3(void) const=0;
   virtual MTAPIRES  NameReserved4(void) const=0;
   virtual MTAPIRES  NameReserved5(void) const=0;
   //--- explicit destructor is prohibited
protected:
                    ~IMTCertificate(void) {}
  };
//+------------------------------------------------------------------+