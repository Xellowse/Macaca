/////////////////////////////////////////////////////////////////////////////////
//
// File name: Module/HAL/src/hal_module.c
// The HAL is Hardware Abstraction Layer. HAL is the upper layer of the module.
// HW Layer is the lower layer under HAL. You should put the none hardware related
// code into HAL and design it as a virtualized hardware.
//
/////////////////////////////////////////////////////////////////////////////////

#include <hal_module_pub.h>
#include <hal_module.h>

//hal_module_version is used to embed the version information string into binary.
//sv# is the special term to let the user can use to search the version string
//in binary easier.
char *hal_module_version="sv#hal_module_ver:1.0.0";

//----------------------------------------------------------------------------
//Function Name: HalModuleInit
//Description  : HAL software initialization. Any software related initialization
//               should deploy here such like variable initialization, memory
//               allocation and lower layer's software initialization,etc.
//Param        :
//      1. void *handle: HAL handle's private data.
//      2. none
//      3. none
//return value : True if HAL software initialized correctly or False if it's not.
//----------------------------------------------------------------------------
HalModuleS32 HalModuleInit(void *handle){

  HalModulePrivateData *hal_fd = (HalModulePrivateData *)handle;

  hal_fd->OsalHandle->OsalPrint("[%s]\n",__FUNCTION__);
  hal_fd->OsalHandle->OsalPrint("------Module1 initialization------\n",__FUNCTION__);
  hal_fd->HwModuleHandle->HwModuleInit(hal_fd->HwModuleHandle->fd);

  return HAL_MODULE_TRUE;
}

//----------------------------------------------------------------------------
//Function Name: HalModuleDeinit
//Description  : HAL software destruction. Any software related destruction
//               should deploy here such like variable clean to default, free the memory
//               and lower layer's software destruction,etc.
//Param        :
//      1. void *handle: HAL handle's private data.
//      2. none
//      3. none
//return value : True if HAL software is destroyed correctly or False if it's not.
//----------------------------------------------------------------------------
HalModuleS32 HalModuleDeinit(void *handle){

  HalModulePrivateData *hal_fd = (HalModulePrivateData *)handle;

  hal_fd->OsalHandle->OsalPrint("[%s]\n",__FUNCTION__);
  hal_fd->HwModuleHandle->HwModuleDeinit(hal_fd->HwModuleHandle->fd);

  return HAL_MODULE_TRUE;
}

//----------------------------------------------------------------------------
//Function Name: HalModuleEnable
//Description  : HAL hardware initialization. Any hardware related initialization
//               should deploy here such like hardware enable, interrupt enable,etc.
//               HwModuleEnable should also be called here.
//Param        :
//      1. void *handle: HAL handle's private data.
//      2. none
//      3. none
//return value : True if HAL hardware initialized correctly or False if it's not.
//----------------------------------------------------------------------------
HalModuleS32 HalModuleEnable(void *handle){

  HalModulePrivateData *hal_fd = (HalModulePrivateData *)handle;

  hal_fd->OsalHandle->OsalPrint("[%s]\n",__FUNCTION__);

  return HAL_MODULE_TRUE;
}

//----------------------------------------------------------------------------
//Function Name: HalModuleDisable
//Description  : HAL hardware disable. Any hardware related disable sequence
//               should deploy here such like hardware disable, interrupt disable,etc.
//               HwModuleDisableshould also be called here.
//Param        :
//      1. void *handle: HAL handle's private data.
//      2. none
//      3. none
//return value : True if HAL hardware initialized correctly or False if it's not.
//----------------------------------------------------------------------------
HalModuleS32 HalModuleDisable(void *handle){

  HalModulePrivateData *hal_fd = (HalModulePrivateData *)handle;

  hal_fd->OsalHandle->OsalPrint("[%s]\n",__FUNCTION__);

  return HAL_MODULE_TRUE;
}

//----------------------------------------------------------------------------
//Function Name: HalModuleMethod1
//Description  : One of the HAL method. You can implement all HAL method in this file.
//               In this case. This method is a example of interaction between 2
//               different modules. This function will call the call back function
//               which module2 is registered. It achieve module's independent by using
//               call back like this case. Because if using direct function call, it
//               will have dependency between 2 module.
//Param        :
//      1. void *handle: HAL handle's private data.
//      2. none
//      3. none
//return value : True if Method is operate correctly or False if it's not.
//----------------------------------------------------------------------------
HalModuleS32 HalModuleMethod1(void *handle){

  HalModulePrivateData *hal_fd = (HalModulePrivateData *)handle;

  hal_fd->OsalHandle->OsalPrint("[%s]\n",__FUNCTION__);
  hal_fd->OsalHandle->OsalPrint("------Module1's method function is called------\n");
  hal_fd->OsalHandle->OsalPrint("------Module2's call back return : ret=%d------\n", hal_fd->CbMethod(hal_fd->CbMethodFd,1,2));

  return HAL_MODULE_TRUE;
}

//----------------------------------------------------------------------------
//Function Name: HalModuleRegisterHalCbMethod1
//Description  : Module2 can use this API to register call back function let Module1
//               can call it. Module1 will call this call back when HalModuleMethod1
//               is called.
//Param        :
//      1. void *handle: HAL handle's private data.
//      2. void *CbMethodHandle : Module2's private data(handle).
//      3. int (*CbMethod)(void *handle, HalModuleS32 param1, HalModuleS32 param2) : Module2's call back function.
//return value : True if Call back function is registered correctly or False if it's not.
//----------------------------------------------------------------------------
HalModuleS32 HalModuleRegisterHalCbMethod1(void *handle, void *CbMethodHandle,int (*CbMethod)(void *handle, HalModuleS32 param1, HalModuleS32 param2)){

  HalModulePrivateData *hal_fd = (HalModulePrivateData *)handle;

  //hal_fd->OsalHandle->OsalPrint("[%s]\n",__FUNCTION__);

  hal_fd->CbMethod = CbMethod;
  hal_fd->CbMethodFd = CbMethodHandle;

  return HAL_MODULE_TRUE;
}

//----------------------------------------------------------------------------
//Function Name: HalModuleRegisterISRCbMethod
//Description  : This is a example for sharing IRQ between Modules. Module2 can
//               use this API to register call back function let Module1 can call it.
//               Module1 will call this call back in ISR.
//
//Param        :
//      1. void *handle: HAL handle's private data.
//      2. void *CalleeCB : Module2's private data(handle).
//      3. void *CalleeCB, HalModuleS32 (*CbMethod)(void *handle, HalModuleS32 param1, HalModuleS32 param2) : Module2's call back function.
//return value : True if ISR call back function is registered correctly or False if it's not.
//----------------------------------------------------------------------------
HalModuleS32 HalModuleRegisterISRCbMethod(void *handle, void *CalleeCB, HalModuleS32 (*CbMethod)(void *handle, HalModuleS32 param1, HalModuleS32 param2)){

  HalModulePrivateData *hal_fd = (HalModulePrivateData *)handle;

  //hal_fd->OsalHandle->OsalPrint("[%s]\n",__FUNCTION__);
  hal_fd->HwModuleHandle->HwModuleRegisterISRCbMethod(hal_fd->HwModuleHandle->fd, CalleeCB, CbMethod);

  return HAL_MODULE_TRUE;
}
