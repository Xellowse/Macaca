#include <hw_module_pub.h>
#include <hal_module_pub.h>
#include <hw_module.h>
#include <ctor_hw_module_pub.h>
#include <ut_pub.h>

#define CASE_NUM (7)

//ut_hw_module_version is used to embed the version information string into binary.
//sv# is the special term to let the user can use to search the version string
//in binary easier.
char *ut_hw_module_version="sv#ut_hw_module_ver:1.0.0+1";

HalModuleS32 TestIsrCbMethod(void *handle, HalModuleS32 param1, HalModuleS32 param2){

  HwModulePrivateData *hw_fd = (HwModulePrivateData *)handle;

  hw_fd->OsalHandle->OsalPrint("[%s] param1:%d, param2:%d\n",__FUNCTION__,param1,param2);

  return HW_MODULE_TRUE;
}

UtResult UtHwModuleWholeTest(void){

  HwModuleS32 ret=0;
  UtResult result={CASE_NUM,0};

  HwModuleS32 i=0;
  HwModuleHandle        *hw_handle;
  HwModuleHandle        *hw_handle2;
  HwModuleHandle        *hw_handle3;

  ret=CtorHwModuleCreateHandle(&hw_handle);
  ret=CtorHwModuleCreateHandle(&hw_handle2);
  ret=CtorHwModuleCreateHandle(&hw_handle3);

  for(i=0; i< CASE_NUM; i++){

      switch(i){

      case 0:
          if(hw_handle->HwModuleInit(hw_handle->fd) < 0)
            result.ng_num++;
          break;
      case 1:
          if(hw_handle->HwModuleEnable(hw_handle->fd) < 0)
            result.ng_num++;
          break;
      case 2:
          if(hw_handle->HwModuleMethod1(hw_handle->fd, 6, 7) < 0)
            result.ng_num++;
          break;
      case 3:
          if(hw_handle->HwModuleRegisterISRCbMethod(hw_handle->fd, hw_handle2->fd, TestIsrCbMethod) < 0)
            result.ng_num++;
          break;
      case 4:
          if(hw_handle->HwModuleDisable(hw_handle->fd) < 0)
            result.ng_num++;
          break;
      case 5: //test for repeat register ISR CallBack function
          hw_handle->HwModuleInit(hw_handle3->fd);
          if(hw_handle->HwModuleRegisterISRCbMethod(hw_handle3->fd, hw_handle2->fd, TestIsrCbMethod) >= 0)
           result.ng_num++;
          hw_handle->HwModuleDeinit(hw_handle3->fd) ;
          break;
      case 6:
          if(hw_handle->HwModuleDeinit(hw_handle->fd) < 0)
            result.ng_num++;
          break;
      default:
          break;
      }
  }

  CtorHwModuleDestroyHandle(hw_handle);
  CtorHwModuleDestroyHandle(hw_handle2);
  CtorHwModuleDestroyHandle(hw_handle3);

  return result;
}
