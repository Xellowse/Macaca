//
#ifndef MODDULE_CTOR_PUB_HAL_MODULE_H_
#define MODDULE_CTOR_PUB_HAL_MODULE_H_

#define CTOR_HAL_MODULE_TRUE  (0)
#define CTOR_HAL_MODULE_FALSE (-1)

typedef int CtorHalModuleS32;

CtorHalModuleS32 CtorHalModuleCreateHandle(HalModuleHandle **handle);
CtorHalModuleS32 CtorHalModuleDestroyHandle(HalModuleHandle *handle);

#endif //MODDULE_CTOR_PUB_HAL_MODULE_H_
