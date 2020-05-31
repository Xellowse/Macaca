//
#ifndef MODDULE_IIF_PUB_H_
#define MODDULE_IIF_PUB_H_


#define IIF_TRUE  (0)
#define IIF_FALSE (-1)

typedef int IifS32;

typedef struct IifHandle{

  //Private data
  void *fd;

  //------------Single Module Mode APIs------------//

  //Public methods
  IifS32  (*IifInit)(void *handle);
  IifS32  (*IifDeinit)(void *handle);
  //IifS32  (*IifEnable)(void *handle);
  //IifS32  (*IifDisable)(void *handle);
  IifS32  (*IifMethod1)(void *handle);

  //Register for call back method

  //Self call back methods

  //------------Dual Module Mode APIs-------------//

  //Public methods
  IifS32  (*IifDualInit)(void *handle);
  IifS32  (*IifDualDeinit)(void *handle);
  //IifS32  (*IifDualEnable)(void *handle);
  //IifS32  (*IifDualDisable)(void *handle);
  IifS32  (*IifDualMethod1)(void *handle);

  //Register for call back method

  //Self call back methods

}IifHandle;

#endif // MODDULE_IIF_PUB_H_
