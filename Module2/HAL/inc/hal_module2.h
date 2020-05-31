#ifndef MODDULE_HAL_MODULE_H_
#define MODDULE_HAL_MODULE_H_

#include <osal_pub.h>
#include <hal_module2_pub.h>
#include <hw_module2_pub.h>

typedef struct HalModule2PrivateData{

  HalModule2Handle data1;
  HalModule2Handle data2;
  OsalHandle *OsalHandle;
  HwModule2Handle *HwModule2Handle;
  //void method1();
  //void method2();

}HalModule2PrivateData;

#endif // MODDULE_HAL_MODULE_H_
