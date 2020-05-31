//
#ifndef MODDULE2_CTOR_PUB_HW_MODULE2_H_
#define MODDULE2_CTOR_PUB_HW_MODULE2_H_

#define CTOR_HW_MODULE2_TRUE  (0)
#define CTOR_HW_MODULE2_FALSE (-1)

typedef int CtorHwModule2S32;

CtorHwModule2S32 CtorHwModule2CreateHandle(HwModule2Handle **handle);
CtorHwModule2S32 CtorHwModule2DestroyHandle(HwModule2Handle *handle);

#endif //MODDULE2_CTOR_PUB_HW_MODULE2_H_
