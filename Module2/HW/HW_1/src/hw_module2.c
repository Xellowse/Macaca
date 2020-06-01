/////////////////////////////////////////////////////////////////////////////////
//
// File name: Module/HW/HW_2/src/hw_module2.c
// This file is for Hardware Layer. Implement your hardware related code here.
// HW Layer is the lower layer under HAL. Different generation's HW layer can be
// split to different folder and HAL should be able to link different HW layer.
//
/////////////////////////////////////////////////////////////////////////////////

#include <hw_module2_pub.h>
#include <hw_module2.h>

//hw_module2_version is used to embed the version information string into binary.
//sv# is the special term to let the user can use to search the version string
//in binary easier.
char *hw_module2_version="sv#hw_module2_ver:1.0.1";

#define IRQ_NUM (1)

// Since there should be only one ISR serve particular IRQ. So there is no reason to use multi-instance based
// IRQ handling. So here use isr_handle as global variable assigned as ISR's self handle.
static HwModule2PrivateData *isr_handle = 0;
// Using the global variable isr_occupied to limit only one user can register the ISR.
static HwModule2U8 isr_occupied = 0;
//----------------------------------------------------------------------------
//Function Name: HwModule2ISR
//Description  : Implement your Hardware ISR here. isr_handle is used to be private
//               data for HW handle(instance).
//Param        :
//      1. none
//      2. none
//      3. none
//return value : none
//----------------------------------------------------------------------------
static void HwModule2ISR(void){

  static char cnt=0;

  if(cnt == 0){
      isr_handle->OsalHandle->OsalPrint("Module2's ISR triggerd\n",__FUNCTION__);
  }

  if(isr_handle->ISRCbMethod != 0 && isr_handle->ISRCbMethodFd != 0){
    isr_handle->ISRCbMethod(isr_handle->ISRCbMethodFd, 6, 7);
  }

  cnt++;

  if(cnt >= 100)
    cnt=0;

  return;
}

//----------------------------------------------------------------------------
//Function Name: HwModule2Init
//Description  : HW Layer software initialization. Any software related initialization
//               should deploy here such like variable initialization, memory allocation,
//               etc.
//Param        :
//      1. void *handle: HW Layer handle's private data.
//      2. none
//      3. none
//return value : True if HW Layer software initialized correctly or False if it's not.
//----------------------------------------------------------------------------
HwModule2S32 HwModule2Init(void *handle){

  HwModule2S32 ret = 0;
  HwModule2PrivateData *hw_fd = (HwModule2PrivateData *)handle;

  hw_fd->OsalHandle->OsalPrint("[%s]\n",__FUNCTION__);

  if(isr_occupied == 0){
    ret = hw_fd->OsalHandle->OsalRegisterIRQCallBackFnc(IRQ_NUM, HwModule2ISR, 0, "HwModule2ISR", (void *)hw_fd->OsalHandle);
    isr_occupied=1;
    isr_handle = hw_fd;

    hw_fd->OsalHandle->OsalPrint("------Module2 Register ISR ret=%d------\n",ret);
  }
  else
    hw_fd->OsalHandle->OsalPrint("------Module2's ISR is occupied------\n");

  return HW_MODULE2_TRUE;
}

//----------------------------------------------------------------------------
//Function Name: HwModule2Deinit
//Description  : HW Layer software destruction. Any software related destruction
//               should deploy here such like variable clean to default, free the memory,
//               etc.
//Param        :
//      1. void *handle: HW Layer handle's private data.
//      2. none
//      3. none
//return value : True if HW Layer software is destroyed correctly or False if it's not.
//----------------------------------------------------------------------------
HwModule2S32 HwModule2Deinit(void *handle){

  HwModule2PrivateData *hw_fd = (HwModule2PrivateData *)handle;

  //hw_fd->OsalHandle->OsalPrint("[%s]\n",__FUNCTION__);

  if(isr_occupied != 0 && isr_handle == hw_fd){
    hw_fd->OsalHandle->OsalUnRegisterIRQCallBackFnc(IRQ_NUM,(void *)hw_fd->OsalHandle);
    isr_occupied=0;
    isr_handle->ISRCbMethod=0;
    isr_handle->ISRCbMethodFd=0;
    isr_handle=0;
  }

  return HW_MODULE2_TRUE;
}

//----------------------------------------------------------------------------
//Function Name: HwModule2Enable
//Description  : HW Layer Hardware initialization. Any hardware related initialization
//               should deploy here such like hardware enable, interrupt enable, etc.
//Param        :
//      1. void *handle: HW handle's private data.
//      2. none
//      3. none
//return value : True if HW hardware initialized correctly or False if it's not.
//----------------------------------------------------------------------------
HwModule2S32 HwModule2Enable(void *handle){

  HwModule2PrivateData *hw_fd = (HwModule2PrivateData *)handle;

  hw_fd->OsalHandle->OsalPrint("[%s]\n",__FUNCTION__);

  return HW_MODULE2_TRUE;
}

//----------------------------------------------------------------------------
//Function Name: HwModule2Disable
//Description  : HW Layer hardware disable. Any hardware related disable sequence
//               should deploy here such like hardware disable, interrupt disable,etc.
//Param        :
//      1. void *handle: HW handle's private data.
//      2. none
//      3. none
//return value : True if HW hardware disable correctly or False if it's not.
//----------------------------------------------------------------------------
HwModule2S32 HwModule2Disable(void *handle){

  HwModule2PrivateData *hw_fd = (HwModule2PrivateData *)handle;

  hw_fd->OsalHandle->OsalPrint("[%s]\n",__FUNCTION__);

  return HW_MODULE2_TRUE;
}

//----------------------------------------------------------------------------
//Function Name: HwModule2Method1
//Description  : One of the HW method. You can implement all HAL method in this file.
//               In this case. This method is a null function.
//Param        :
//      1. void *handle: HW handle's private data.
//      2. none
//      3. none
//return value : True if Method is operate correctly or False if it's not.
//----------------------------------------------------------------------------
HwModule2S32 HwModule2Method1(void *handle, HwModule2S32 param1, HwModule2S32 param2){

  return HW_MODULE2_TRUE;
}

//----------------------------------------------------------------------------
//Function Name: HwModule2RegisterISRCbMethod
//Description  : This is a example for sharing ISR between Modules. Module1 call this
//               API to register call back function and let Module2 can call it. Module2
//               will call this call back in ISR.
//
//Param        :
//      1. void *handle: HW handle's private data.
//      2. void *CalleeHandle : Module1's private data(handle).
//      3. HwModule2S32 (*CbMethod)(void *handle, HwModule2S32 param1, HwModule2S32 param2) : Module1's call back function.
//return value : True if ISR call back function is registered correctly or False if it's not.
//----------------------------------------------------------------------------
HwModule2S32 HwModule2RegisterISRCbMethod(void *handle, void *CalleeHandle, HwModule2S32 (*CbMethod)(void *handle, HwModule2S32 param1, HwModule2S32 param2)){

  HwModule2PrivateData *hw_fd = (HwModule2PrivateData *)handle;

  hw_fd->OsalHandle->OsalPrint("[%s]\n",__FUNCTION__);

  if(isr_occupied != 0 && hw_fd == isr_handle){
    hw_fd->ISRCbMethodFd = CalleeHandle;
    hw_fd->ISRCbMethod = CbMethod;
  }
  else{
    hw_fd->OsalHandle->OsalPrint("------handle is not match!!------\n");
    return HW_MODULE2_FALSE;
  }

  return HW_MODULE2_TRUE;
}
