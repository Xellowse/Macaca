//
#ifndef MODDULE_HW_HW1_HW_PUB_MODULE_H_
#define MODDULE_HW_HW1_HW_PUB_MODULE_H_

#include <hal_module_pub.h>

#define HW_MODULE_TRUE  (0)
#define HW_MODULE_FALSE (-1)

typedef int HwModuleS32;
typedef unsigned char HwModuleU8;

typedef struct HwModuleHandle{

  //Private data
  void *fd;

  //Public methods
  HwModuleS32 (*HwModuleInit)(void *handle);
  HwModuleS32 (*HwModuleDeinit)(void *handle);
  HwModuleS32 (*HwModuleEnable)(void *handle);
  HwModuleS32 (*HwModuleDisable)(void *handle);
  HwModuleS32 (*HwModuleMethod1)(void *handle, HwModuleS32, HwModuleS32);
  HwModuleS32 (*HwModuleRegisterISRCbMethod)(void *handle, void *CalleeHandle, HalModuleS32 (*CbMethod)(void *handle, HalModuleS32 param1, HalModuleS32 param2));

  //Register for call back method

  //Self call back methods

}HwModuleHandle;

#endif // MODDULE_HW_HW1_HW_PUB_MODULE_H_
