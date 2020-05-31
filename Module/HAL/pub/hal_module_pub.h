//
#ifndef MODDULE_HAL_PUB_MODULE_H_
#define MODDULE_HAL_PUB_MODULE_H_


#define HAL_MODULE_TRUE  (0)
#define HAL_MODULE_FALSE (-1)

typedef int HalModuleS32;

typedef struct HalModuleHandle{

  //Private data
  void *fd;

  //Public methods
  HalModuleS32  (*HalModuleInit)(void *handle);
  HalModuleS32  (*HalModuleDeinit)(void *handle);
  HalModuleS32  (*HalModuleEnable)(void *handle);
  HalModuleS32  (*HalModuleDisable)(void *handle);
  HalModuleS32  (*HalModuleMethod1)(void *handle);
  void (*HalModuleMethod2)(void *handle, HalModuleS32);

  //Register for call back method
  HalModuleS32  (*HalModuleRegisterHalCbMethod1)(void *handle, void *CbMethodHandle, HalModuleS32 (*CbMethod)(void *handle, HalModuleS32 param1, HalModuleS32 param2));
  HalModuleS32 (*HalModuleRegisterISRCbMethod)(void *handle, void *CalleeHandle, HalModuleS32 (*CbMethod)(void *handle, HalModuleS32 param1, HalModuleS32 param2));
  //Self call back methods

}HalModuleHandle;

#endif // MODDULE_HAL_PUB_MODULE_H_
