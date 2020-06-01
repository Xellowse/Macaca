/////////////////////////////////////////////////////////////////////////////////
//
// File name: Module/HW/HW_1/src/hw_module.c
// This file is for Hardware Layer. Implement your hardware related code here.
// HW Layer is the lower layer under HAL. Different generation's HW layer can be
// split to different folder and HAL should be able to link different HW layer.
//
/////////////////////////////////////////////////////////////////////////////////

#include <hw_module_pub.h>
#include <hw_module.h>

//hw_module_version is used to embed the version information string into binary.
//sv# is the special term to let the user can use to search the version string
//in binary easier.
char *hw_module_version="sv#hw_module_ver:1.0.1";

#define IRQ_NUM (56)

// Since there should be only one ISR serve particular IRQ. So there is no reason to use multi-instance based
// IRQ handling. So here use isr_handle as global variable assigned as ISR's self handle.
static HwModulePrivateData *isr_handle = 0;
// Using the global variable isr_occupied to limit only one user can register the ISR.
static HwModuleU8 isr_occupied = 0;

//----------------------------------------------------------------------------
//Function Name: HwModuleISR
//Description  : Implement your Hardware ISR here. isr_handle is used to be private
//               data for HW handle(instance).
//Param        :
//      1. none
//      2. none
//      3. none
//return value : none
//----------------------------------------------------------------------------
static void HwModuleISR(void){

  isr_handle->OsalHandle->OsalPrint("Module1's ISR triggerd\n",__FUNCTION__);

  if(isr_handle->ISRCbMethod != 0 && isr_handle->ISRCbMethodFd != 0){
    isr_handle->ISRCbMethod(isr_handle->ISRCbMethodFd, 6, 7);
  }

  return;
}

//----------------------------------------------------------------------------
//Function Name: HwModuleInit
//Description  : HW Layer software initialization. Any software related initialization
//               should deploy here such like variable initialization, memory allocation,
//               etc.
//Param        :
//      1. void *handle: HW Layer handle's private data.
//      2. none
//      3. none
//return value : True if HW Layer software initialized correctly or False if it's not.
//----------------------------------------------------------------------------
HwModuleS32 HwModuleInit(void *handle){

  HwModuleS32 ret = 0;
  HwModulePrivateData *hw_fd = (HwModulePrivateData *)handle;

  hw_fd->OsalHandle->OsalPrint("[%s]\n",__FUNCTION__);

  if(isr_occupied == 0){
    ret = hw_fd->OsalHandle->OsalRegisterIRQCallBackFnc(IRQ_NUM, HwModuleISR, 0, "HwModuleISR", (void *)hw_fd->OsalHandle);
    isr_occupied=1;
    isr_handle = hw_fd;

    hw_fd->OsalHandle->OsalPrint("------Module1 Register ISR ret=%d------\n",ret);
  }
  else
    hw_fd->OsalHandle->OsalPrint("------Module1's ISR is occupied------\n");


  return HW_MODULE_TRUE;
}

//----------------------------------------------------------------------------
//Function Name: HwModuleDeinit
//Description  : HW Layer software destruction. Any software related destruction
//               should deploy here such like variable clean to default, free the memory,
//               etc.
//Param        :
//      1. void *handle: HW Layer handle's private data.
//      2. none
//      3. none
//return value : True if HW Layer software is destroyed correctly or False if it's not.
//----------------------------------------------------------------------------
HwModuleS32 HwModuleDeinit(void *handle){

  HwModulePrivateData *hw_fd = (HwModulePrivateData *)handle;

  //hw_fd->OsalHandle->OsalPrint("[%s]\n",__FUNCTION__);

  if(isr_occupied != 0 && isr_handle == hw_fd){
    hw_fd->OsalHandle->OsalUnRegisterIRQCallBackFnc(IRQ_NUM,(void *)hw_fd->OsalHandle);
    isr_occupied=0;
    isr_handle->ISRCbMethod=0;
    isr_handle->ISRCbMethodFd=0;
    isr_handle=0;
  }

  return HW_MODULE_TRUE;
}

//----------------------------------------------------------------------------
//Function Name: HwModuleEnable
//Description  : HW Layer Hardware initialization. Any hardware related initialization
//               should deploy here such like hardware enable, interrupt enable, etc.
//Param        :
//      1. void *handle: HW handle's private data.
//      2. none
//      3. none
//return value : True if HW hardware initialized correctly or False if it's not.
//----------------------------------------------------------------------------
HwModuleS32 HwModuleEnable(void *handle){

  HwModulePrivateData *hw_fd = (HwModulePrivateData *)handle;

  hw_fd->OsalHandle->OsalPrint("[%s]\n",__FUNCTION__);

  return HW_MODULE_TRUE;
}

//----------------------------------------------------------------------------
//Function Name: HwModuleDisable
//Description  : HW Layer hardware disable. Any hardware related disable sequence
//               should deploy here such like hardware disable, interrupt disable,etc.
//Param        :
//      1. void *handle: HW handle's private data.
//      2. none
//      3. none
//return value : True if HW hardware disable correctly or False if it's not.
//----------------------------------------------------------------------------
HwModuleS32 HwModuleDisable(void *handle){

  HwModulePrivateData *hw_fd = (HwModulePrivateData *)handle;

  hw_fd->OsalHandle->OsalPrint("[%s]\n",__FUNCTION__);

  return HW_MODULE_TRUE;
}

//----------------------------------------------------------------------------
//Function Name: HwModuleMethod1
//Description  : One of the HW method. You can implement all HAL method in this file.
//               In this case. This method is a null function.
//Param        :
//      1. void *handle: HAL handle's private data.
//      2. none
//      3. none
//return value : True if Method is operate correctly or False if it's not.
//----------------------------------------------------------------------------
HwModuleS32 HwModuleMethod1(void *handle, HwModuleS32 param1, HwModuleS32 param2){

  return HW_MODULE_TRUE;
}

//----------------------------------------------------------------------------
//Function Name: HwModuleRegisterISRCbMethod
//Description  : This is a example for sharing ISR between Modules. Module2 call this
//               API to register call back function and let Module1 can call it. Module1
//               will call this call back in ISR.
//
//Param        :
//      1. void *handle: HW handle's private data.
//      2. void *CalleeHandle : Module2's private data(handle).
//      3. HwModuleS32 (*CbMethod)(void *handle, HwModuleS32 param1, HwModuleS32 param2) : Module2's call back function.
//return value : True if ISR call back function is registered correctly or False if it's not.
//----------------------------------------------------------------------------
HwModuleS32 HwModuleRegisterISRCbMethod(void *handle, void *CalleeHandle, HalModuleS32 (*CbMethod)(void *handle, HalModuleS32 param1, HalModuleS32 param2)){

  HwModulePrivateData *hw_fd = (HwModulePrivateData *)handle;

  hw_fd->OsalHandle->OsalPrint("[%s]\n",__FUNCTION__);

  if(isr_occupied != 0 && hw_fd == isr_handle){
    hw_fd->ISRCbMethodFd = CalleeHandle;
    hw_fd->ISRCbMethod = CbMethod;
  }
  else{
    hw_fd->OsalHandle->OsalPrint("------handle is not match!!------\n");
    return HW_MODULE_FALSE;
  }
  return HW_MODULE_TRUE;
}
