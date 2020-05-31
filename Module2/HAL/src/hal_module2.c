/////////////////////////////////////////////////////////////////////////////////
//
// File name: Module2/HAL/src/hal_module2.c
// The HAL is Hardware Abstraction Layer. HAL is the upper layer of the module.
// HW Layer is the lower layer under HAL. You should put the none hardware related
// code into HAL and design it as a virtualized hardware.
//
/////////////////////////////////////////////////////////////////////////////////

#include <hal_module2_pub.h>
#include <hal_module2.h>

//hal_module2_version is used to embed the version information string into binary.
//sv# is the special term to let the user can use to search the version string
//in binary easier.
char *hal_module2_version="sv#hal_module2_ver:1.0.0";

//----------------------------------------------------------------------------
//Function Name: HalModule2Init
//Description  : HAL software initialization. Any software related initialization
//               should deploy here such like variable initialization, memory
//               allocation and lower layer's software initialization,etc.
//Param        :
//      1. void *handle: HAL handle's private data.
//      2. none
//      3. none
//return value : True if HAL software initialized correctly or False if it's not.
//----------------------------------------------------------------------------
HalModule2S32 HalModule2Init(void *handle){

  HalModule2PrivateData *hal_fd = (HalModule2PrivateData *)handle;

  hal_fd->OsalHandle->OsalPrint("[%s]\n",__FUNCTION__);
  hal_fd->OsalHandle->OsalPrint("------Module2 initialization------\n",__FUNCTION__);
  hal_fd->HwModule2Handle->HwModule2Init(hal_fd->HwModule2Handle->fd);

  return HAL_MODULE2_TRUE;
}

//----------------------------------------------------------------------------
//Function Name: HalModule2Deinit
//Description  : HAL software destruction. Any software related destruction
//               should deploy here such like variable clean to default, free the memory
//               and lower layer's software destruction,etc.
//Param        :
//      1. void *handle: HAL handle's private data.
//      2. none
//      3. none
//return value : True if HAL software is destroyed correctly or False if it's not.
//----------------------------------------------------------------------------
HalModule2S32 HalModule2Deinit(void *handle){

  HalModule2PrivateData *hal_fd = (HalModule2PrivateData *)handle;

  hal_fd->OsalHandle->OsalPrint("[%s]\n",__FUNCTION__);
  hal_fd->HwModule2Handle->HwModule2Deinit(hal_fd->HwModule2Handle->fd);

  return HAL_MODULE2_TRUE;
}

//----------------------------------------------------------------------------
//Function Name: HalModule2Enable
//Description  : HAL hardware initialization. Any hardware related initialization
//               should deploy here such like hardware enable, interrupt enable,etc.
//               HwModuleEnable should also be called here.
//Param        :
//      1. void *handle: HAL handle's private data.
//      2. none
//      3. none
//return value : True if HAL hardware initialized correctly or False if it's not.
//----------------------------------------------------------------------------
HalModule2S32 HalModule2Enable(void *handle){

  HalModule2PrivateData *hal_fd = (HalModule2PrivateData *)handle;

  hal_fd->OsalHandle->OsalPrint("[%s]\n",__FUNCTION__);

  return HAL_MODULE2_TRUE;
}

//----------------------------------------------------------------------------
//Function Name: HalModule2Disable
//Description  : HAL hardware disable. Any hardware related disable sequence
//               should deploy here such like hardware disable, interrupt disable,etc.
//               HwModuleDisableshould also be called here.
//Param        :
//      1. void *handle: HAL handle's private data.
//      2. none
//      3. none
//return value : True if HAL hardware initialized correctly or False if it's not.
//----------------------------------------------------------------------------
HalModule2S32 HalModule2Disable(void *handle){

  return HAL_MODULE2_TRUE;
}

//----------------------------------------------------------------------------
//Function Name: HalModule2CbMethod
//Description  : This method is a example of interaction between 2
//               different modules. Register this function to Module1. Module1
//               will call it itself.
//Param        :
//      1. void *handle: HAL handle's private data.
//      2. HalModule2S32 param1 : Used to print out to test param is pass correct or not.
//      3. HalModule2S32 param2 : Used to print out to test param is pass correct or not.
//return value : True if Method is operate correctly or False if it's not.
//----------------------------------------------------------------------------
HalModule2S32 HalModule2CbMethod(void *handle, HalModule2S32 param1, HalModule2S32 param2){

  HalModule2PrivateData *hal_fd = (HalModule2PrivateData *)handle;

  hal_fd->OsalHandle->OsalPrint("[%s]\n",__FUNCTION__);
  hal_fd->OsalHandle->OsalPrint("------Module2's call back is called!! param1:%d, param2:%d------\n",param1,param2);


  return HAL_MODULE2_TRUE;
}

//----------------------------------------------------------------------------
//Function Name: HalModule2ISRCbMethod
//Description  : This is a example for sharing IRQ between Modules. Register this
//               function to Module1. Module1 will call this call back in Module1's ISR.
//
//Param        :
//      1. void *handle: HAL handle's private data.
//      2. HalModule2S32 param1 : Used to print out to test param is pass correct or not.
//      3. HalModule2S32 param2 : Used to print out to test param is pass correct or not.
//return value : True if ISR call back function is operate correctly or False if it's not.
//----------------------------------------------------------------------------
HalModule2S32 HalModule2ISRCbMethod(void *handle, HalModule2S32 param1, HalModule2S32 param2){

  HalModule2PrivateData *hal_fd = (HalModule2PrivateData *)handle;

  hal_fd->OsalHandle->OsalPrint("------Module2's ISR call back is called!! param1:%d, param2:%d------\n",param1,param2);

  return HAL_MODULE2_TRUE;
}
