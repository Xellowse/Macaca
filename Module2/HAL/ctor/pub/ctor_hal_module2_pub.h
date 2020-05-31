//
#ifndef MODDULE2_CTOR_PUB_HAL_MODULE2_H_
#define MODDULE2_CTOR_PUB_HAL_MODULE2_H_

#define CTOR_HAL_MODULE2_TRUE  (0)
#define CTOR_HAL_MODULE2_FALSE (-1)

typedef int CtorHalModule2S32;

CtorHalModule2S32 CtorHalModule2CreateHandle(HalModule2Handle **handle);
CtorHalModule2S32 CtorHalModule2DestroyHandle(HalModule2Handle *handle);

#endif //MODDULE2_CTOR_PUB_HAL_MODULE2_H_
