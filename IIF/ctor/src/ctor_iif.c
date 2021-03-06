/////////////////////////////////////////////////////////////////////////////////
//
// File name: IIF/ctor_iif.c
// As the IIF CTOR(Integration Interface Constructor), it's used to create/destroy
// IIF handle(instance). IIF CTOR is only used to call module CTORs to create the
// handles so that IIF handle is able to do the operation of them.
//
/////////////////////////////////////////////////////////////////////////////////


#include <ctor_iif_pub.h>
#include <iif_pub.h>
#include <iif.h>
#include <ctor_osal_pub.h>
#include <ctor_hal_module_pub.h>
#include <ctor_hal_module2_pub.h>

//ctor_iif_version is used to embed the version information string into binary.
//sv# is the special term to let the user can use to search the version string
//in binary easier.
char *ctor_iif_version="sv#ctor_iif_ver:1.0.0+mm2";

extern IifS32 IifInit(void *handle);
extern IifS32 IifDeinit(void *handle);
extern IifS32 IifMethod1(void *handle);
extern IifS32 IifDualInit(void *handle);
extern IifS32 IifDualDeinit(void *handle);
extern IifS32 IifDualMethod1(void *handle);
extern CtorHalModuleS32 CtorHalModuleCreateHandle(HalModuleHandle **handle);
extern CtorHalModule2S32 CtorHalModule2CreateHandle(HalModule2Handle **handle);
extern CtorHalModuleS32 CtorHalModuleDestroyHandle(HalModuleHandle *handle);
extern CtorHalModule2S32 CtorHalModule2DestroyHandle(HalModule2Handle *handle);

//----------------------------------------------------------------------------
//Function Name: CtorIifCreateHandle
//Description  : Constructor of IIF handle. User can declare a handle pointer
//               and it will point to IIF handle which created by this function.
//Param        :
//      1. IifHandle **handle: IIF pointer which user declare.
//      2. none
//      3. none
//return value : True if IIF handle is created correctly or False if it's not.
//----------------------------------------------------------------------------
IifCtorS32 CtorIifCreateHandle(IifHandle **handle){

  OsalHandle *osal_handle;
  IifHandle *handle_out;
  IifPrivateData *iif_fd;

  CtorOsalCreateHandle(&osal_handle);

  handle_out = (IifHandle *)osal_handle->OsalMalloc(sizeof(IifHandle));
  handle_out->fd = osal_handle->OsalMalloc(sizeof(IifPrivateData));

  *handle = handle_out;
  iif_fd = (IifPrivateData *)handle_out->fd;
  iif_fd->OsalHandle = osal_handle;

  handle_out->IifInit = IifInit;
  handle_out->IifDeinit = IifDeinit;
  //handle_out->IifEnable= IifEnable;
  //handle_out->IifDisable = IifDisable;
  handle_out->IifMethod1 = IifMethod1;
  handle_out->IifDualInit = IifDualInit;
  handle_out->IifDualDeinit = IifDualDeinit;
  //handle_out->IifDualEnable= IifDualEnable;
  //handle_out->IifDualDisable = IifDualDisable;
  handle_out->IifDualMethod1 = IifDualMethod1;

  CtorHalModuleCreateHandle(&(iif_fd->hal_module1_handle));
  CtorHalModule2CreateHandle(&(iif_fd->hal_module2_handle));

  return IIF_CONSTR_TRUE;
}

//----------------------------------------------------------------------------
//Function Name: CtorIifDestroyHandle
//Description  : Destructor of IIF handle. User can use this function to remove
//               the IIF handle.
//Param        :
//      1. IifHandle **handle: IIF handle's pointer which user created.
//      2. none
//      3. none
//return value : True if IIF handle is removed correctly or False if it's not.
//----------------------------------------------------------------------------
IifCtorS32 CtorIifDestroyHandle(IifHandle *handle){

  OsalHandle *osal_handle;
  IifPrivateData *iif_fd = (IifPrivateData *)handle->fd;

  //iif_fd->OsalHandle->OsalPrint("[%s]\n",__FUNCTION__);

  CtorHalModuleDestroyHandle(iif_fd->hal_module1_handle);
  CtorHalModule2DestroyHandle(iif_fd->hal_module2_handle);

  CtorOsalCreateHandle(&osal_handle);
  osal_handle->OsalFree(handle->fd);
  osal_handle->OsalFree(handle);
  CtorOsalDestroyHandle(osal_handle);


  return IIF_CONSTR_TRUE;
}
