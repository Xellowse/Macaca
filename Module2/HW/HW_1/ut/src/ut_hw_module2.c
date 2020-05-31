#include <hw_module2_pub.h>
#include <hw_module2.h>
#include <ctor_hw_module2_pub.h>
#include <ut_pub.h>

//ut_hw_module2_version is used to embed the version information string into binary.
//sv# is the special term to let the user can use to search the version string
//in binary easier.
char *ut_hw_module2_version="sv#ut_hw_module2_ver:1.0.0+1";

#define CASE_NUM (7)

HwModule2S32 TestIsrCbMethod(void *handle, HwModule2S32 param1, HwModule2S32 param2){

  HwModule2PrivateData *hw_fd = (HwModule2PrivateData *)handle;

  hw_fd->OsalHandle->OsalPrint("[%s] param1:%d, param2:%d\n",__FUNCTION__,param1,param2);

  return HW_MODULE2_TRUE;
}

UtResult UtHwModule2WholeTest(void){

  HwModule2S32 ret=0;
  UtResult result={CASE_NUM,0};

  HwModule2S32 i=0;
  HwModule2Handle        *hw_handle;
  HwModule2Handle        *hw_handle2;
  HwModule2Handle        *hw_handle3;

  ret=CtorHwModule2CreateHandle(&hw_handle);
  ret=CtorHwModule2CreateHandle(&hw_handle2);
  ret=CtorHwModule2CreateHandle(&hw_handle3);

  for(i=0; i< CASE_NUM; i++){

      switch(i){

      case 0:
          if(hw_handle->HwModule2Init(hw_handle->fd) < 0)
            result.ng_num++;
          break;
      case 1:
          if(hw_handle->HwModule2Enable(hw_handle->fd) < 0)
            result.ng_num++;
          break;
      case 2:
          if(hw_handle->HwModule2Method1(hw_handle->fd, 6, 7) < 0)
            result.ng_num++;
          break;
      case 3:
          if(hw_handle->HwModule2RegisterISRCbMethod(hw_handle->fd, hw_handle2->fd, TestIsrCbMethod) < 0)
            result.ng_num++;
          break;
      case 4:
          if(hw_handle->HwModule2Disable(hw_handle->fd) < 0)
            result.ng_num++;
          break;
      case 5: //test for repeat register ISR CallBack function
          hw_handle->HwModule2Init(hw_handle3->fd);
          if(hw_handle->HwModule2RegisterISRCbMethod(hw_handle3->fd, hw_handle2->fd, TestIsrCbMethod) >= 0)
           result.ng_num++;
          hw_handle->HwModule2Deinit(hw_handle3->fd) ;
          break;
      case 6:
          if(hw_handle->HwModule2Deinit(hw_handle->fd) < 0)
            result.ng_num++;
          break;
      default:
          break;
      }
  }

  CtorHwModule2DestroyHandle(hw_handle);
  CtorHwModule2DestroyHandle(hw_handle2);
  CtorHwModule2DestroyHandle(hw_handle3);

  return result;
}
