//+------------------------------------------------------------------+
//|                                                 MetaTrader 5 API |
//|                             Copyright 2000-2026, MetaQuotes Ltd. |
//|                                               www.metaquotes.net |
//+------------------------------------------------------------------+
#pragma once
//+------------------------------------------------------------------+
//| Class of memory block                                            |
//+------------------------------------------------------------------+
class CMTMemPack
  {
private:
   enum
     {
      REALLOC_STEP  =1024                  // buffer reallocation step
     };

private:
   char             *m_buffer=nullptr;     // data
   uint32_t          m_buffer_len=0;       // data length
   uint32_t          m_buffer_max=0;       // maximum number of bytes in buffer

public:
   CMTMemPack(void)
     {
     }

   ~CMTMemPack(void)
     {
      Shutdown();
     }

   void Clear(void)
     {
      m_buffer_len=0;
     }

   void Shutdown(void)
     {
      if(m_buffer)
        {
         delete[] m_buffer;
         m_buffer=nullptr;
        }
      m_buffer_max=0;
      m_buffer_len=0;
     }

   bool Reallocate(uint32_t growsize)
     {
      char *newbuf;
      //--- check sizes
      if(growsize<=m_buffer_max)
         return(true);
      //--- try to allocate block of greater size
      if((newbuf=new(std::nothrow) char[growsize])==nullptr)
         return(false);
      //--- copy values from old buffer
      if(m_buffer)
        {
         if(m_buffer_len>0)
            memcpy(newbuf,m_buffer,m_buffer_len);
         delete[] m_buffer;
        }
      m_buffer    =newbuf;
      m_buffer_max=growsize;
      //---
      return(true);
     }

   bool Add(const void *buf,const uint32_t len)
     {
      //--- check
      if(!buf)
         return(false);
      //--- check for exceeding buffer size
      if(!m_buffer || (len+m_buffer_len)>m_buffer_max)
         if(!Reallocate(len+m_buffer_len+REALLOC_STEP))
            return(false);
      //--- append data to buffer
      memcpy(&m_buffer[m_buffer_len],buf,len);
      m_buffer_len+=len;
      //---
      return(true);
     }

   void Swap(CMTMemPack &pack)
     {
      //--- check
      if(this==&pack)
         return;
      //--- swap, remember own buffer
      char    *buffer    =m_buffer;
      uint32_t buffer_len=m_buffer_len;
      uint32_t buffer_max=m_buffer_max;
      //--- replace buffer with received one
      m_buffer    =pack.m_buffer;
      m_buffer_len=pack.m_buffer_len;
      m_buffer_max=pack.m_buffer_max;
      //--- return own buffer
      pack.m_buffer    =buffer;
      pack.m_buffer_len=buffer_len;
      pack.m_buffer_max=buffer_max;
     }

   //--- buffer access
   char* Buffer(void)
     {
      return(m_buffer);
     }

   uint32_t Len(void) const
     {
      return(m_buffer_len);
     }

   void Len(const uint32_t val)
     {
      if(val<=m_buffer_max)
         m_buffer_len=val;
     }

   uint32_t Max(void) const
     {
      return(m_buffer_max);
     }
  };
//+------------------------------------------------------------------+
