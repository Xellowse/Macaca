//
#ifndef MODDULE_CTOR_PUB_HW_MODULE_H_
#define MODDULE_CTOR_PUB_HW_MODULE_H_

#define CTOR_HW_MODULE_TRUE  (0)
#define CTOR_HW_MODULE_FALSE (-1)

typedef int CtorHwModuleS32;

CtorHwModuleS32 CtorHwModuleCreateHandle(HwModuleHandle **handle);
CtorHwModuleS32 CtorHwModuleDestroyHandle(HwModuleHandle *handle);

#endif //MODDULE_CTOR_PUB_HW_MODULE_H_
