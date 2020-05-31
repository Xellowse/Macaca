#ifndef MODDULE_IIF_H_
#define MODDULE_IIF_H_

#include <osal_pub.h>
#include <hal_module_pub.h>
#include <hal_module2_pub.h>

typedef struct IifPrivateData{

  HalModuleS32 data1;
  HalModuleS32 data2;
  OsalHandle *OsalHandle;
  HalModuleHandle  *hal_module1_handle;
  HalModule2Handle *hal_module2_handle;
  //void method1();
  //void method2();

}IifPrivateData;


#endif // MODDULE_IIF_H_
