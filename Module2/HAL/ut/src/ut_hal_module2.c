#include <hal_module2_pub.h>
#include <hal_module2.h>
#include <ctor_hal_module2_pub.h>
#include <ut_pub.h>

//ut_hal_module2_version is used to embed the version information string into binary.
//sv# is the special term to let the user can use to search the version string
//in binary easier.
char *ut_hal_module2_version="sv#ut_hal_module2_ver:1.0.0+1";

#define CASE_NUM (6)

UtResult UtHalModule2WholeTest(void){

  HalModule2S32 ret=0;
  UtResult result={CASE_NUM,0};

  HalModule2S32 i=0;
  HalModule2Handle        *hal_handle;


  ret=CtorHalModule2CreateHandle(&hal_handle);

  for(i=0; i< CASE_NUM; i++){

      switch(i){

      case 0:
          if(hal_handle->HalModule2Init(hal_handle->fd) < 0)
            result.ng_num++;
          break;
      case 1:
          if(hal_handle->HalModule2Enable(hal_handle->fd) < 0)
            result.ng_num++;
          break;
      case 2:
          if(hal_handle->HalModule2CbMethod(hal_handle->fd,6,7) < 0)
            result.ng_num++;
          break;
      case 3:
          if(hal_handle->HalModule2ISRCbMethod(hal_handle->fd,8,9) < 0)
            result.ng_num++;
          break;
      case 4:
          if(hal_handle->HalModule2Disable(hal_handle->fd) < 0)
            result.ng_num++;
          break;
      case 5:
          if(hal_handle->HalModule2Deinit(hal_handle->fd) < 0)
            result.ng_num++;
          break;
      default:
          break;
      }
  }

  CtorHalModule2DestroyHandle(hal_handle);

  return result;
}
