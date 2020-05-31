#ifndef MODDULE_HW_MODULE_H_
#define MODDULE_HW_MODULE_H_

#include <hw_module_pub.h>
#include <hal_module_pub.h>
#include <osal_pub.h>

typedef struct HwModulePrivateData{

  HwModuleS32 data1;
  HwModuleS32 data2;
  OsalHandle *OsalHandle;
  void *CbMethodFd;
  HwModuleS32 (*CbMethod)(void *handle, HwModuleS32 param1, HwModuleS32 param2);
  void *ISRCbMethodFd;
  HalModuleS32 (*ISRCbMethod)(void *handle, HalModuleS32 param1, HalModuleS32 param2);
  //void method1();
  //void method2();

}HwModulePrivateData;


#endif // MODDULE_HW_MODULE_H_
