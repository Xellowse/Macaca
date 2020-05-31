//
#ifndef MODDULE0_OSAL_CTOR_PUB_OSAL_PUB_H_
#define MODDULE0_OSAL_CTOR_PUB_OSAL_PUB_H_

#include <osal_pub.h>

#define OSAL_CTOR_LAYER_TRUE  (0)
#define OSAL_CTOR_LAYER_FALSE (-1)

typedef int CtorOsalS32;


CtorOsalS32 CtorOsalCreateHandle(OsalHandle **handle);
CtorOsalS32 CtorOsalDestroyHandle(OsalHandle *handle);

#endif // MODDULE0_OSAL_CTOR_PUB_OSAL_PUB_H_
