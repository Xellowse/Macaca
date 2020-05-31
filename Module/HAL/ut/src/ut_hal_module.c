#include <hal_module_pub.h>
#include <hal_module.h>
#include <ctor_hal_module_pub.h>
#include <ut_pub.h>

//ut_hal_module_version is used to embed the version information string into binary.
//sv# is the special term to let the user can use to search the version string
//in binary easier.
char *ut_hal_module_version="sv#ut_hal_module_ver:1.0.0+1";

#define CASE_NUM (7)

HalModuleS32 TestCbMethod(void *handle, HalModuleS32 param1, HalModuleS32 param2){

  HalModulePrivateData *hal_fd = (HalModulePrivateData *)handle;

  hal_fd->OsalHandle->OsalPrint("[%s] param1:%d, param2:%d\n",__FUNCTION__,param1,param2);

  return HAL_MODULE_TRUE;
}

HalModuleS32 TestIsrCbMethod(void *handle, HalModuleS32 param1, HalModuleS32 param2){

  HalModulePrivateData *hal_fd = (HalModulePrivateData *)handle;

  hal_fd->OsalHandle->OsalPrint("[%s] param1:%d, param2:%d\n",__FUNCTION__,param1,param2);

  return HAL_MODULE_TRUE;
}

UtResult UtHalModuleWholeTest(void){

  HalModuleS32 ret=0;
  UtResult result={CASE_NUM,0};

  HalModuleS32 i=0;
  HalModuleHandle        *hal_handle;
  HalModuleHandle        *hal_handle2;

  ret=CtorHalModuleCreateHandle(&hal_handle);
  ret=CtorHalModuleCreateHandle(&hal_handle2);

  for(i=0; i< CASE_NUM; i++){

      switch(i){

      case 0:
          if(hal_handle->HalModuleInit(hal_handle->fd) < 0)
            result.ng_num++;
          break;
      case 1:
          if(hal_handle->HalModuleEnable(hal_handle->fd) < 0)
            result.ng_num++;
          break;
      case 2:
          if(hal_handle->HalModuleRegisterHalCbMethod1(hal_handle->fd, hal_handle2->fd, TestCbMethod) < 0)
            result.ng_num++;
          break;
      case 3:
          if(hal_handle->HalModuleRegisterISRCbMethod(hal_handle->fd, hal_handle2->fd, TestIsrCbMethod) < 0)
            result.ng_num++;
          break;
      case 4:
          if(hal_handle->HalModuleMethod1(hal_handle->fd) < 0)
            result.ng_num++;
          break;
      case 5:
          if(hal_handle->HalModuleDisable(hal_handle->fd) < 0)
            result.ng_num++;
          break;
      case 6:
          if(hal_handle->HalModuleDeinit(hal_handle->fd) < 0)
            result.ng_num++;
          break;
      default:
          break;
      }
  }

  CtorHalModuleDestroyHandle(hal_handle);
  CtorHalModuleDestroyHandle(hal_handle2);

  return result;
}
