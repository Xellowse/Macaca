#ifndef MODDULE_HW_MODULE2_H_
#define MODDULE_HW_MODULE2_H_

#include <hw_module2_pub.h>
#include <osal_pub.h>

typedef struct HwModule2PrivateData{

  HwModule2S32 data1;
  HwModule2S32 data2;
  OsalHandle *OsalHandle;
  void *CbMethodFd;
  HwModule2S32 (*CbMethod)(void *handle, HwModule2S32 param1, HwModule2S32 param2);
  void *ISRCbMethodFd;
  HwModule2S32 (*ISRCbMethod)(void *handle, HwModule2S32 param1, HwModule2S32 param2);
  //void method1();
  //void method2();

}HwModule2PrivateData;


#endif // MODDULE_HW_MODULE2_H_
