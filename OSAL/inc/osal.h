#ifndef MODDULE0_OSAL_INC_OSAL_H_
#define MODDULE0_OSAL_INC_OSAL_H_

#include <osal_pub.h>

typedef struct OsalPrivateData{

  OsalS32 data1;
  OsalS32 data2;
  void *IsrHandleFd;
  void (*IsrMethod)(void); //For multi-platform compatible reason. ISR keep simple (no return value, no argument).
  //void method1();
  //void method2();

}OsalPrivateData;


#endif // MODDULE0_OSAL_INC_OSAL_H_
