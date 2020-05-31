#ifndef MODDULE_HAL_MODULE_H_
#define MODDULE_HAL_MODULE_H_

#include <osal_pub.h>
#include <hal_module_pub.h>
#include <hw_module_pub.h>

typedef struct HalModulePrivateData{

  HalModuleS32 data1;
  HalModuleS32 data2;
  OsalHandle *OsalHandle;
  HwModuleHandle *HwModuleHandle;
  void *CbMethodFd;
  int (*CbMethod)(void *handle, HalModuleS32 param1, HalModuleS32 param2);
  //void method1();
  //void method2();

}HalModulePrivateData;


#endif // MODDULE_HAL_MODULE_H_
