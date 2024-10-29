//+------------------------------------------------------------------+
//|                                                 MetaTrader 5 API |
//|                             Copyright 2000-2024, MetaQuotes Ltd. |
//|                                               www.metaquotes.net |
//+------------------------------------------------------------------+
#pragma once
//+------------------------------------------------------------------+
//| Account allocation agreement config                              |
//+------------------------------------------------------------------+
class IMTConAccountAgreement
  {
public:
   //--- caption type
   enum EnCaptionType
     {
      CAPTION_CUSTOM                              =0,
      CAPTION_CLIENT_AGREEMENT                    =1,
      CAPTION_RISK_DISCLOSURE                     =2,
      CAPTION_CLIENT_AGREEMENT_AND_RISK_DISCLOSURE=3,
      CAPTION_COMPLAINTS_HANDLING_PROCEDURE       =4,
      CAPTION_ORDER_EXECUTION_POLICY              =5,
      CAPTION_CLIENT_CATEGORISATION_NOTICE        =6,
      CAPTION_CONFLICTS_OF_INTEREST_POLICY        =7,
      CAPTION_DATA_PROTECTION_POLICY              =8,
      //--- enumeration borders
      CAPTION_FIRST                               =CAPTION_CUSTOM,
      CAPTION_LAST                                =CAPTION_DATA_PROTECTION_POLICY,
     };
   //--- flags
   enum EnFlags
     {
      AGREEMENT_FLAG_NONE                         =0x00000000,
      AGREEMENT_FLAG_MANDATORY                    =0x00000001,
      //--- enumeration borders
      AGREEMENT_FLAG_ALL                          =AGREEMENT_FLAG_MANDATORY
     };
public:
   //--- common methods
   virtual void      Release(void)=0;
   virtual MTAPIRES  Assign(const IMTConAccountAgreement* param)=0;
   virtual MTAPIRES  Clear(void)=0;
   //--- EnCaptionType
   virtual UINT      CaptionType(void) const=0;
   virtual MTAPIRES  CaptionType(const UINT type)=0;
   //--- Custom Caption Text
   virtual LPCWSTR   CaptionCustomText(void) const=0;
   virtual MTAPIRES  CaptionCustomText(LPCWSTR text)=0;
   //--- URL for full agreement text
   virtual LPCWSTR   URL(void) const=0;
   virtual MTAPIRES  URL(LPCWSTR url)=0;
   //--- flags
   virtual UINT      Flags(void) const=0;
   virtual MTAPIRES  Flags(const UINT flags)=0;
   //--- explicit destructor is prohibited
protected:
                    ~IMTConAccountAgreement(void) {}
  };
//+------------------------------------------------------------------+
//| Account allocation config                                        |
//+------------------------------------------------------------------+
class IMTConAccountAllocation
  {
public:
   //--- flags
   enum EnFlags
     {
      FLAG_NONE              =0x00000000,
      FLAG_DETAILED_FORM     =0x00000001,
      FLAG_REQUIRE_DOCS      =0x00000002,
      FLAG_CONFIRM_PHONE     =0x00000004,
      FLAG_CONFIRM_EMAIL     =0x00000008,
      FLAG_START_KYC         =0x00000010,
      //--- enumeration borders
      FLAG_ALL               =FLAG_NONE|FLAG_DETAILED_FORM|FLAG_REQUIRE_DOCS|FLAG_CONFIRM_PHONE|FLAG_CONFIRM_EMAIL|FLAG_START_KYC
     };
public:
   //--- common methods
   virtual void      Release(void)=0;
   virtual MTAPIRES  Assign(const IMTConAccountAllocation* param)=0;
   virtual MTAPIRES  Clear(void)=0;
   //--- group
   virtual LPCWSTR   Group(void) const=0;
   virtual MTAPIRES  Group(LPCWSTR group)=0;
   //--- description
   virtual LPCWSTR   Description(void) const=0;
   virtual MTAPIRES  Description(LPCWSTR description)=0;
   //--- flags
   virtual UINT      Flags(void) const=0;
   virtual MTAPIRES  Flags(const UINT flags)=0;
   //--- leverages
   virtual LPCWSTR   Leverages(void) const=0;
   virtual MTAPIRES  Leverages(LPCWSTR leverages)=0;
   //--- countries
   virtual LPCWSTR   Countries(void) const=0;
   virtual MTAPIRES  Countries(LPCWSTR countries)=0;
   //--- email
   virtual LPCWSTR   ConfirmationEmail(void) const=0;
   virtual MTAPIRES  ConfirmationEmail(LPCWSTR email)=0;
   //--- Account Allocations
   virtual MTAPIRES  AccountAgreementAdd(IMTConAccountAgreement* cfg)=0;
   virtual MTAPIRES  AccountAgreementUpdate(const UINT pos,const IMTConAccountAgreement* cfg)=0;
   virtual MTAPIRES  AccountAgreementDelete(const UINT pos)=0;
   virtual MTAPIRES  AccountAgreementClear(void)=0;
   virtual MTAPIRES  AccountAgreementShift(const UINT pos,const int shift)=0;
   virtual UINT      AccountAgreementTotal(void) const=0;
   virtual MTAPIRES  AccountAgreementNext(const UINT pos,IMTConAccountAgreement* cfg) const=0;
   //--- explicit destructor is prohibited
protected:
                    ~IMTConAccountAllocation(void) {}
  };
//+------------------------------------------------------------------+
//| Common MetaTrader 5 Platform config                              |
//+------------------------------------------------------------------+
class IMTConCommon
  {
public:
   //--- LiveUpdate modes
   enum EnUpdateMode
     {
      UPDATE_DISABLE    =0,  // disable LiveUpdate
      UPDATE_ENABLE     =1,  // enable LiveUpdate
      UPDATE_ENABLE_BETA=2,  // enable LiveUpdate, including beta releases
      //--- enumeration borders
      UPDATE_FIRST      =UPDATE_DISABLE,
      UPDATE_LAST       =UPDATE_ENABLE_BETA
     };
   //--- common methods
   virtual void      Release(void)=0;
   virtual MTAPIRES  Assign(const IMTConCommon* param)=0;
   virtual MTAPIRES  Clear(void)=0;
   //--- server name
   virtual LPCWSTR   Name(void) const=0;
   virtual MTAPIRES  Name(LPCWSTR name)=0;
   //--- server full name
   virtual LPCWSTR   NameFull(void) const=0;
   //--- owner full name (from license)
   virtual LPCWSTR   Owner(void) const=0;
   //--- owner short name (from license)
   virtual LPCWSTR   OwnerID(void) const=0;
   //--- owner host (from license)
   virtual LPCWSTR   OwnerHost(void) const=0;
   //--- owner email (from license)
   virtual LPCWSTR   OwnerEmail(void) const=0;
   //--- product full name (from license)
   virtual LPCWSTR   Product(void) const=0;
   //--- license expiration date
   virtual INT64     ExpirationLicense(void) const=0;
   //--- license support date
   virtual INT64     ExpirationSupport(void) const=0;
   //--- max. trade servers count (from license)
   virtual UINT      LimitTradeServers(void) const=0;
   //--- max. web servers count (from license)
   virtual UINT      LimitWebServers(void) const=0;
   //--- max. real accounts count (from license)
   virtual UINT      LimitAccounts(void) const=0;
   //--- max. trade deals count (from license)
   virtual UINT      LimitDeals(void) const=0;
   //--- max. client groups count (from license)
   virtual UINT      LimitGroups(void) const=0;
   //--- LiveUpdate mode
   virtual UINT      LiveUpdateMode(void) const=0;
   virtual MTAPIRES  LiveUpdateMode(const UINT mode)=0;
   //--- Total users
   virtual UINT      TotalUsers(void) const=0;
   //--- Total real users
   virtual UINT      TotalUsersReal(void) const=0;
   //--- Total deals
   virtual UINT      TotalDeals(void) const=0;
   //--- Total orders
   virtual UINT      TotalOrders(void) const=0;
   //--- Total history orders
   virtual UINT      TotalOrdersHistory(void) const=0;
   //--- Total positions
   virtual UINT      TotalPositions(void) const=0;
   //--- max. symbols count (from license)
   virtual UINT      LimitSymbols(void) const=0;
   //--- Account Allocation URL
   virtual LPCWSTR   AccountURL(void) const=0;
   virtual MTAPIRES  AccountURL(LPCWSTR url)=0;
   //--- Account Deposit URL
   virtual LPCWSTR   AccountDepositURL(void) const=0;
   virtual MTAPIRES  AccountDepositURL(LPCWSTR url)=0;
   //--- Account Withdrawal URL
   virtual LPCWSTR   AccountWithdrawalURL(void) const=0;
   virtual MTAPIRES  AccountWithdrawalURL(LPCWSTR url)=0;
   //--- Account Allocations
   virtual MTAPIRES  AccountAllocationAdd(IMTConAccountAllocation* cfg)=0;
   virtual MTAPIRES  AccountAllocationUpdate(const UINT pos,const IMTConAccountAllocation* cfg)=0;
   virtual MTAPIRES  AccountAllocationDelete(const UINT pos)=0;
   virtual MTAPIRES  AccountAllocationClear(void)=0;
   virtual MTAPIRES  AccountAllocationShift(const UINT pos,const int shift)=0;
   virtual UINT      AccountAllocationTotal(void) const=0;
   virtual MTAPIRES  AccountAllocationNext(const UINT pos,IMTConAccountAllocation* cfg) const=0;
   //--- explicit destructor is prohibited
protected:
                    ~IMTConCommon(void) {}
  };
//+------------------------------------------------------------------+
//| Common config events notification interface                      |
//+------------------------------------------------------------------+
class IMTConCommonSink
  {
public:
   virtual void      OnCommonUpdate(const IMTConCommon* /*config*/) {  }
   virtual void      OnCommonSync(void)                             {  }
  };
//+------------------------------------------------------------------+
