/////////////////////////////////////////////////////////////////////////////////
//
// File name: OSAL/src/ctor_osal.c
// The OSAL CTOR (Operating System Abstraction Layer Constructor) is used to
// create/destroy OSAL handle(instance). OSAL is used to abstract OS related API
// to achieve cross-platform. OS related API like printf, printk, irq_request,malloc,
// etc. should implement under OSAL.
//
/////////////////////////////////////////////////////////////////////////////////

#include <osal_pub.h>
#include <osal.h>

//ctor_osal_version is used to embed the version information string into binary.
//sv# is the special term to let the user can use to search the version string
//in binary easier.
char *ctor_osal_version="sv#ctor_osal_ver:1.0.0+1";

extern OsalS32 OsalOpen(void);
extern OsalS32 OsalClose(void);
extern OsalS32 OsalPrint ( const char * format, ... );
extern void* OsalMalloc(OsalS32);
extern OsalS32 OsalRegisterIRQCallBackFnc(OsalS32 IrqNum, void* IrqHandler, OsalS32 IrqFlag, const char* IrqName, void* handle);
extern void OsalUnRegisterIRQCallBackFnc(OsalS32 IrqNum, void* handle);
extern void OsalFree(void *addr);
extern OsalS32 OsalMsleep(OsalS32 msec);

//----------------------------------------------------------------------------
//Function Name: CtorOsalCreateHandle
//Description  : Constructor of OSAL handle. OSAL handle is created by this function.
//               API assignment of OSAL is implement in this function. Modify this
//               function when OSAL API is changed.
//Param        :
//      1. OsalHandle **handle: OSAL Layer Handle pointer which user have declared.
//      2. none
//      3. none
//return value : True if OSAL handle is created correctly or False if it's not.
//----------------------------------------------------------------------------
OsalS32 CtorOsalCreateHandle(OsalHandle **handle){

  OsalHandle *handle_out;

  *handle = (OsalHandle *)OsalMalloc(sizeof(OsalHandle));
  handle_out = *handle;
  handle_out->fd = OsalMalloc(sizeof(OsalPrivateData));

  handle_out->OsalOpen = OsalOpen;
  handle_out->OsalClose = OsalClose;
  handle_out->OsalPrint = OsalPrint;
  handle_out->OsalMalloc = OsalMalloc;
  handle_out->OsalRegisterIRQCallBackFnc = OsalRegisterIRQCallBackFnc;
  handle_out->OsalUnRegisterIRQCallBackFnc = OsalUnRegisterIRQCallBackFnc;
  handle_out->OsalFree = OsalFree;
  handle_out->OsalMsleep = OsalMsleep;

  return OSAL_LAYER_TRUE;
}

//----------------------------------------------------------------------------
//Function Name: CtorOsalDestroyHandle
//Description  : Destructor of OSAL Layer's handle. User can use this function to remove
//               the OSAL handle.
//Param        :
//      1. OsalHandle *handle: OSAL handle's pointer which user have declared.
//      2. none
//      3. none
//return value : True if OSAL handle is removed correctly or False if it's not.
//----------------------------------------------------------------------------
OsalS32 CtorOsalDestroyHandle(OsalHandle *handle){

  OsalFree(handle->fd);
  OsalFree(handle);

  return OSAL_LAYER_TRUE;
}
