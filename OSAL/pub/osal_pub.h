//
#ifndef MODDULE0_OSAL_PUB_OSAL_PUB_H_
#define MODDULE0_OSAL_PUB_OSAL_PUB_H_

#define OSAL_LAYER_TRUE  (0)
#define OSAL_LAYER_FALSE (-1)

typedef int  OsalS32;
typedef unsigned char OsalU8;

typedef struct OsalHandle{

  void *fd;

  OsalS32  (*OsalOpen)(void);
  OsalS32  (*OsalClose)(void);
  OsalS32 (*OsalPrint)(const char *,...);
  void* (*OsalMalloc)(OsalS32 size);
  OsalS32 (*OsalRegisterIRQCallBackFnc)(OsalS32 IrqNum, void* IrqHandler, OsalS32 IrqFlag, const char* IrqName, void* handle);
  void (*OsalUnRegisterIRQCallBackFnc)(OsalS32 IrqNum, void* handle);
  void (*OsalFree)(void *addr);
  OsalS32 (*OsalMsleep)(OsalS32 msec);

}OsalHandle;

#endif // MODDULE0_OSAL_PUB_OSAL_PUB_H_
