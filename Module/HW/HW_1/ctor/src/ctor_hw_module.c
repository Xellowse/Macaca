/////////////////////////////////////////////////////////////////////////////////
//
// File name: Module/CTOR/ctor_module.c
// The CTOR (Constructor) is used to create/destroy Module's handle(instance).
// Because of the architecture stack of Module is constructed with upper layer HAL
// and lower layer HW layer, module CTOR is not only create HAL handle but also
// create HW handle as HAL's private data.
//
/////////////////////////////////////////////////////////////////////////////////

#include <hw_module.h>
#include <hw_module_pub.h>
#include <osal_pub.h>
#include <ctor_osal_pub.h>
#include <ctor_hw_module_pub.h>

//ctor_hw_module_version is used to embed the version information string into binary.
//sv# is the special term to let the user can use to search the version string
//in binary easier.
char *ctor_hw_module_version="sv#ctor_hw_module_ver:1.0.0+1";

extern HwModuleS32 HwModuleInit(void *handle);
extern HwModuleS32 HwModuleDeinit(void *handle);
extern HwModuleS32 HwModuleEnable(void *handle);
extern HwModuleS32 HwModuleDisable(void *handle);
extern HwModuleS32 HwModuleMethod1(void *handle, HwModuleS32, HwModuleS32);
extern HwModuleS32 HwModuleRegisterISRCbMethod(void *handle, void *CalleeHandle, HalModuleS32 (*CbMethod)(void *handle, HalModuleS32 param1, HalModuleS32 param2));

//----------------------------------------------------------------------------
//Function Name: CtorHwModuleCreateHandle
//Description  : Constructor of Module HW Layer's handle. HW Layer's handle is
//               created by this function. API assignment of HW Layer is implement
//               in this function. Modify this function when HW Layer's API is changed.
//Param        :
//      1. HwModuleHandle **handle: HW Layer Handle pointer which in HAL's private
//                                 data.
//      2. none
//      3. none
//return value : True if HW Layer handle is created correctly or False if it's not.
//----------------------------------------------------------------------------
CtorHwModuleS32 CtorHwModuleCreateHandle(HwModuleHandle **handle){

  OsalHandle *osal_handle;
  HwModuleHandle *handle_out;
  HwModulePrivateData *hw_fd;

  CtorOsalCreateHandle(&osal_handle);

  handle_out = (HwModuleHandle *)osal_handle->OsalMalloc(sizeof(HwModuleHandle));
  handle_out->fd = osal_handle->OsalMalloc(sizeof(HwModulePrivateData));

  *handle = handle_out;
  hw_fd = (HwModulePrivateData *)handle_out->fd;
  hw_fd->OsalHandle = osal_handle;

  handle_out->HwModuleInit = HwModuleInit;
  handle_out->HwModuleDeinit = HwModuleDeinit;
  handle_out->HwModuleEnable = HwModuleEnable;
  handle_out->HwModuleDisable = HwModuleDisable;
  handle_out->HwModuleMethod1= HwModuleMethod1;
  handle_out->HwModuleRegisterISRCbMethod = HwModuleRegisterISRCbMethod;

  return CTOR_HW_MODULE_TRUE;
}

//----------------------------------------------------------------------------
//Function Name: CtorHwModuleDestroyHandle
//Description  : Destructor of HW Layer's handle. User can use this function to remove
//               the HW Layer's handle.
//Param        :
//      1. HwModuleHandle *handle: HW Layer handle's pointer which in HAL's private data.
//      2. none
//      3. none
//return value : True if HW Layer handle is removed correctly or False if it's not.
//----------------------------------------------------------------------------
CtorHwModuleS32 CtorHwModuleDestroyHandle(HwModuleHandle *handle){

  OsalHandle *osal_handle;

  CtorOsalCreateHandle(&osal_handle);
  osal_handle->OsalFree(handle->fd);
  osal_handle->OsalFree(handle);
  CtorOsalDestroyHandle(osal_handle);

  return CTOR_HW_MODULE_TRUE;
}
