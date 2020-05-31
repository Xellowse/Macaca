#include <osal_pub.h>
#include <ctor_osal_pub.h>
#include <ut_pub.h>

//ut_osal_version is used to embed the version information string into binary.
//sv# is the special term to let the user can use to search the version string
//in binary easier.
char *ut_osal_version="sv#ut_osal_ver:1.0.0+1";

#define CASE_NUM (7)
#define IRQ_NUM (56)

// Since there should be only one ISR serve particular IRQ, here use global
//variable to do some isr work instead of using multi-instance.
OsalHandle *osal_isr_handle;
OsalU8 isr_triggered=0;

void UtISR(void)
{

  osal_isr_handle->OsalPrint("UT ISR Test\n");
  isr_triggered=1;
  return;
}

OsalS32 UtMemTest(void *ut_mem_test_buf)
{
  OsalS32 i=0;
  OsalU8 *test_buf;

  test_buf = ut_mem_test_buf;

  for(i=0;i<40;i++){

    *(test_buf+i)=6;

  }

  for(i=0;i<40;i++){

    osal_isr_handle->OsalPrint("%d:%d,",i,(int)*(test_buf+i));

    if(*(test_buf+i) != 6)
      return -1;
  }

  return 0;
}

UtResult UtOsalWholeTest(void){

  OsalS32 ret=0;
  UtResult result={CASE_NUM,0};
  void *ut_mem_test_buf=0;

  OsalS32 i=0;
  OsalHandle        *osal_handle;

  ret=CtorOsalCreateHandle(&osal_handle);
  ret=CtorOsalCreateHandle(&osal_isr_handle);

  for(i=0; i< CASE_NUM; i++){

      switch(i){

      case 0:
          if(osal_handle->OsalOpen() < 0){
            osal_handle->OsalPrint("osal : open test fail\n");
            result.ng_num++;
          }
          break;
      case 1:
          if(osal_handle->OsalPrint("Printf Test num=%d\n",6) < 0){
            osal_handle->OsalPrint("osal : Print test fail\n");
            result.ng_num++;
          }
          break;
      case 2:
          ut_mem_test_buf = osal_handle->OsalMalloc(40);
          if(ut_mem_test_buf < 0){
            osal_handle->OsalPrint("osal : memory allocate test fail\n");
            result.ng_num++;
            break;
          }

          if(UtMemTest(ut_mem_test_buf) < 0){
            osal_handle->OsalPrint("osal : memory content test fail\n");
            result.ng_num++;
          }

          break;
      case 3:
          if(osal_handle->OsalRegisterIRQCallBackFnc(IRQ_NUM,UtISR,0, "UtISR", (void *)osal_isr_handle) < 0){
            osal_handle->OsalPrint("\nosal : ISR registration test fail\n");
            result.ng_num++;
          }
          osal_handle->OsalMsleep(2000);
          if(isr_triggered == 0)
            result.ng_num++;

          break;
      case 4:
          osal_handle->OsalUnRegisterIRQCallBackFnc(IRQ_NUM,(void *)osal_isr_handle);
          break;
      case 5:
          osal_handle->OsalFree((void *)ut_mem_test_buf);
          break;
      case 6:
          if(osal_handle->OsalClose() < 0){
            osal_handle->OsalPrint("osal : close test fail\n");
            result.ng_num++;
          }
          break;
      default:
          break;
      }
  }

  CtorOsalDestroyHandle(osal_handle);

  return result;
}
