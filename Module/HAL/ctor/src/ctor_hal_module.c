/////////////////////////////////////////////////////////////////////////////////
//
// File name: Module/CTOR/ctor_module.c
// The CTOR (Constructor) is used to create/destroy Module's handle(instance).
// Because of the HW Layer is the lower layer under HAL, HAL Module CTOR is not only
// create HAL handle but also create HW handle as HAL's private data.
//
/////////////////////////////////////////////////////////////////////////////////

#include <hal_module_pub.h>
#include <hal_module.h>
#include <osal_pub.h>
#include <ctor_osal_pub.h>
#include <ctor_hal_module_pub.h>
#include <ctor_hw_module_pub.h>

//ctor_hal_module_version is used to embed the version information string into binary.
//sv# is the special term to let the user can use to search the version string
//in binary easier.
char *ctor_hal_module_version="sv#ctor_hal_module_ver:1.0.0+1";

extern int HalModuleInit(void *handle);
extern int HalModuleDeinit(void *handle);
extern int HalModuleEnable(void *handle);
extern int HalModuleDisable(void *handle);
extern int HalModuleRegisterHalCbMethod1(void *handle, void *CbMethodHandle,int (*CbMethod)(void *handle, HalModuleS32 param1, HalModuleS32 param2));
extern int HalModuleMethod1(void *handle);
extern HalModuleS32 HalModuleRegisterISRCbMethod(void *handle, void *CalleeCB, HalModuleS32 (*CbMethod)(void *handle, HalModuleS32 param1, HalModuleS32 param2));

//----------------------------------------------------------------------------
//Function Name: CtorHalModuleCreateHandle
//Description  : Constructor of Module HAL's handle. HAL's handle is created by
//               this function. API assignment of HAL is implement in this function.
//               This function is also create HW Layer because of HW Layer is the
//               lower layer under HAL.
//Param        :
//      1. HwModuleHandle **handle: HAL Handle pointer which is declared by user.
//      2. none
//      3. none
//return value : True if HAL handle is created correctly or False if it's not.
//----------------------------------------------------------------------------
CtorHalModuleS32 CtorHalModuleCreateHandle(HalModuleHandle **handle){

  OsalHandle *osal_handle;
  HalModuleHandle *handle_out;
  HalModulePrivateData *hal_fd;

  CtorOsalCreateHandle(&osal_handle);

  handle_out = (HalModuleHandle *)osal_handle->OsalMalloc(sizeof(HalModuleHandle));
  handle_out->fd = osal_handle->OsalMalloc(sizeof(HalModulePrivateData));

  *handle = handle_out;
  hal_fd = (HalModulePrivateData *)handle_out->fd;
  hal_fd->OsalHandle = osal_handle;

  handle_out->HalModuleInit = HalModuleInit;
  handle_out->HalModuleDeinit = HalModuleDeinit;
  handle_out->HalModuleEnable = HalModuleEnable;
  handle_out->HalModuleDisable = HalModuleDisable;
  handle_out->HalModuleRegisterHalCbMethod1= HalModuleRegisterHalCbMethod1;
  handle_out->HalModuleMethod1 = HalModuleMethod1;
  handle_out->HalModuleRegisterISRCbMethod = HalModuleRegisterISRCbMethod;

  CtorHwModuleCreateHandle(&(hal_fd->HwModuleHandle));


  return CTOR_HAL_MODULE_TRUE;
}

//----------------------------------------------------------------------------
//Function Name: CtorHalModuleDestroyHandle
//Description  : Destructor of HAL's handle. User can use this function to remove
//               the HAL's handle. The HW Layer's handle will be also removed by
//               this function, because of HW Layer is the lower layer under HAL.
//Param        :
//      1. HalModuleHandle *handle: HAL handle's pointer which user declared.
//      2. none
//      3. none
//return value : True if HAL handle is removed correctly or False if it's not.
//----------------------------------------------------------------------------
CtorHalModuleS32 CtorHalModuleDestroyHandle(HalModuleHandle *handle){

  OsalHandle *osal_handle;
  HalModulePrivateData *hal_fd = (HalModulePrivateData *)handle->fd;

  //hal_fd->OsalHandle->OsalPrint("[%s]\n",__FUNCTION__);

  CtorHwModuleDestroyHandle(hal_fd->HwModuleHandle);

  CtorOsalCreateHandle(&osal_handle);
  osal_handle->OsalFree(handle->fd);
  osal_handle->OsalFree(handle);
  CtorOsalDestroyHandle(osal_handle);


  return CTOR_HAL_MODULE_TRUE;
}
