/////////////////////////////////////////////////////////////////////////////////
//
// File name: Module/CTOR/ctor_module.c
// The CTOR (Constructor) is used to create/destroy Module's handle(instance).
// Because of the architecture stack of Module is constructed with upper layer HAL
// and lower layer HW layer, module CTOR is not only create HAL handle but also
// create HW handle as HAL's private data.
//
/////////////////////////////////////////////////////////////////////////////////

#include <hw_module2.h>
#include <hw_module2_pub.h>
#include <osal_pub.h>
#include <ctor_osal_pub.h>
#include <ctor_hw_module2_pub.h>

//ctor_hw_module2_version is used to embed the version information string into binary.
//sv# is the special term to let the user can use to search the version string
//in binary easier.
char *ctor_hw_module2_version="sv#ctor_hw_module2_ver:1.0.0+1";

extern HwModule2S32 HwModule2Init(void *handle);
extern HwModule2S32 HwModule2Deinit(void *handle);
extern HwModule2S32 HwModule2Enable(void *handle);
extern HwModule2S32 HwModule2Disable(void *handle);
extern HwModule2S32 HwModule2Method1(void *handle, HwModule2S32, HwModule2S32);
extern HwModule2S32 HwModule2RegisterISRCbMethod(void *handle, void *CalleeHandle, HwModule2S32 (*CbMethod)(void *handle, HwModule2S32 param1, HwModule2S32 param2));

//----------------------------------------------------------------------------
//Function Name: CtorHwModule2CreateHandle
//Description  : Constructor of Module HW Layer's handle. HW Layer's handle is
//               created by this function. API assignment of HW Layer is implement
//               in this function. Modify this function when HW Layer's API is changed.
//Param        :
//      1. HwModule2Handle **handle: HW Layer Handle pointer which in HAL's private
//                                 data.
//      2. none
//      3. none
//return value : True if HW Layer handle is created correctly or False if it's not.
//----------------------------------------------------------------------------
CtorHwModule2S32 CtorHwModule2CreateHandle(HwModule2Handle **handle){

  OsalHandle *osal_handle;
  HwModule2Handle *handle_out;
  HwModule2PrivateData *hw_fd;

  CtorOsalCreateHandle(&osal_handle);

  handle_out = (HwModule2Handle *)osal_handle->OsalMalloc(sizeof(HwModule2Handle));
  handle_out->fd = osal_handle->OsalMalloc(sizeof(HwModule2PrivateData));

  *handle = handle_out;
  hw_fd = (HwModule2PrivateData *)handle_out->fd;
  hw_fd->OsalHandle = osal_handle;

  handle_out->HwModule2Init = HwModule2Init;
  handle_out->HwModule2Deinit = HwModule2Deinit;
  handle_out->HwModule2Enable = HwModule2Enable;
  handle_out->HwModule2Disable = HwModule2Disable;
  handle_out->HwModule2Method1= HwModule2Method1;
  handle_out->HwModule2RegisterISRCbMethod = HwModule2RegisterISRCbMethod;

  return CTOR_HW_MODULE2_TRUE;
}

//----------------------------------------------------------------------------
//Function Name: CtorHwModule2DestroyHandle
//Description  : Destructor of HW Layer's handle. User can use this function to remove
//               the HW Layer's handle.
//Param        :
//      1. HwModule2Handle *handle: HW Layer handle's pointer which in HAL's private data.
//      2. none
//      3. none
//return value : True if HW Layer handle is removed correctly or False if it's not.
//----------------------------------------------------------------------------
CtorHwModule2S32 CtorHwModule2DestroyHandle(HwModule2Handle *handle){

  OsalHandle *osal_handle;

  CtorOsalCreateHandle(&osal_handle);
  osal_handle->OsalFree(handle->fd);
  osal_handle->OsalFree(handle);
  CtorOsalDestroyHandle(osal_handle);

  return CTOR_HW_MODULE2_TRUE;
}
