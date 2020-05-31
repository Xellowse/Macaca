/////////////////////////////////////////////////////////////////////////////////
//
// File name: Module2/CTOR/ctor_module2.c
// The CTOR (Constructor) is used to create/destroy Module's handle(instance).
// Because of the architecture stack of Module is constructed with upper layer HAL
// and lower layer HW layer, module CTOR is not only create HAL handle but also
// create HW handle as HAL's private data.
//
/////////////////////////////////////////////////////////////////////////////////

#include <hal_module2_pub.h>
#include <hal_module2.h>
#include <osal_pub.h>
#include <ctor_osal_pub.h>
#include <ctor_hal_module2_pub.h>
#include <ctor_hw_module2_pub.h>

//ctor_hal_module2_version is used to embed the version information string into binary.
//sv# is the special term to let the user can use to search the version string
//in binary easier.
char *ctor_hal_module2_version="sv#ctor_hal_module2_ver:1.0.0+1";

extern int HalModule2Init(void *handle);
extern int HalModule2Deinit(void *handle);
extern int HalModule2Enable(void *handle);
extern int HalModule2Disable(void *handle);
extern int HalModule2CbMethod(void *handle, HalModule2S32 param1, HalModule2S32 param2);
extern HalModule2S32 HalModule2ISRCbMethod(void *handle, HalModule2S32 param1, HalModule2S32 param2);

//----------------------------------------------------------------------------
//Function Name: CtorHalModule2CreateHandle
//Description  : Constructor of Module HAL's handle. HAL's handle is created by
//               this function. API assignment of HAL is implement in this function.
//               This function is also create HW Layer because of HW Layer is the
//               lower layer under HAL.
//Param        :
//      1. HalModule2Handle **handle: HAL Handle pointer which is declared by user.
//      2. none
//      3. none
//return value : True if HAL handle is created correctly or False if it's not.
//----------------------------------------------------------------------------
CtorHalModule2S32 CtorHalModule2CreateHandle(HalModule2Handle **handle){

  OsalHandle *osal_handle;
  HalModule2Handle *handle_out;
  HalModule2PrivateData *hal_fd;

  CtorOsalCreateHandle(&osal_handle);

  handle_out = (HalModule2Handle *)osal_handle->OsalMalloc(sizeof(HalModule2Handle));
  handle_out->fd = osal_handle->OsalMalloc(sizeof(HalModule2PrivateData));

  *handle = handle_out;
  hal_fd = (HalModule2PrivateData *)handle_out->fd;
  hal_fd->OsalHandle = osal_handle;

  handle_out->HalModule2Init = HalModule2Init;
  handle_out->HalModule2Deinit = HalModule2Deinit;
  handle_out->HalModule2Enable = HalModule2Enable;
  handle_out->HalModule2Disable = HalModule2Disable;
  handle_out->HalModule2CbMethod = HalModule2CbMethod;
  handle_out->HalModule2ISRCbMethod = HalModule2ISRCbMethod;

  CtorHwModule2CreateHandle(&(hal_fd->HwModule2Handle));

  return CTOR_HAL_MODULE2_TRUE;
}

//----------------------------------------------------------------------------
//Function Name: CtorHalModule2DestroyHandle
//Description  : Destructor of HAL's handle. User can use this function to remove
//               the HAL's handle. The HW Layer's handle will be also removed by
//               this function, because of HW Layer is the lower layer under HAL.
//Param        :
//      1. HalModule2Handle *handle: HAL handle's pointer which user declared.
//      2. none
//      3. none
//return value : True if HAL handle is removed correctly or False if it's not.
//----------------------------------------------------------------------------
CtorHalModule2S32 CtorHalModule2DestroyHandle(HalModule2Handle *handle){

  OsalHandle *osal_handle;
  HalModule2PrivateData *hal_fd = (HalModule2PrivateData *)handle->fd;

  //hal_fd->OsalHandle->OsalPrint("[%s]\n",__FUNCTION__);

  CtorHwModule2DestroyHandle(hal_fd->HwModule2Handle);

  CtorOsalCreateHandle(&osal_handle);
  osal_handle->OsalFree(handle->fd);
  osal_handle->OsalFree(handle);
  CtorOsalDestroyHandle(osal_handle);

  return CTOR_HAL_MODULE2_TRUE;
}
