//
#ifndef MODDULE_IIF_PUB_CONSTR_H_
#define MODDULE_IIF_PUB_CONSTR_H_

#include <iif_pub.h>

#define IIF_CONSTR_TRUE  (0)
#define IIF_CONSTR_FALSE (-1)

typedef int IifCtorS32;

IifCtorS32 CtorIifCreateHandle(IifHandle **handle);
IifCtorS32 CtorIifDestroyHandle(IifHandle *handle);

#endif //MODDULE_IIF_PUB_CONSTR_H_
