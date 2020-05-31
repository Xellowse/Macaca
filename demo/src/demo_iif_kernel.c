/////////////////////////////////////////////////////////////////////////////////
//
// File name: Macaca/demo/demo_iif_kernel.c
// This demo is the demonstration of how IIF work. It's linux kernel space version
// more information please reference to Macaca/demo/demo_iif.c
//////////////////////////////////////////////////////////////////////////////////

#include <linux/init.h>
#include <linux/module.h>
#include <ctor_iif_pub.h>
#include <ctor_osal_pub.h>
#include <iif_pub.h>

extern IifCtorS32 CtorIifCreateHandle(IifHandle **handle);
extern IifCtorS32 CtorIifDestroyHandle(IifHandle *handle);

MODULE_LICENSE("Dual BSD/GPL");

IifHandle   *iif_handle;
OsalHandle  *osal_handle;

static int DemoIifInit(void)
{
  printk(KERN_ALERT "Hello, Demo iif\n");

  CtorOsalCreateHandle(&osal_handle);
  CtorIifCreateHandle(&iif_handle);

  //------------ dual mode's APIs ------------------//
  if(iif_handle->IifDualInit(iif_handle->fd))
    osal_handle->OsalPrint("API not supported\n");
  if(iif_handle->IifDualMethod1(iif_handle->fd))
    osal_handle->OsalPrint("API not supported\n");

  //------------ single mode's APIs ------------------//
  if(iif_handle->IifInit(iif_handle->fd))
    osal_handle->OsalPrint("API not supported\n");
  if(iif_handle->IifMethod1(iif_handle->fd))
    osal_handle->OsalPrint("API not supported\n");

  return 0;
}

static void DemoIifExit(void)
{
  printk(KERN_ALERT "Goodbye, Demo iif\n");

  if(iif_handle->IifDeinit(iif_handle->fd))
    osal_handle->OsalPrint("API not supported\n");
  if(iif_handle->IifDualDeinit(iif_handle->fd))
    osal_handle->OsalPrint("API not supported\n");

  CtorOsalDestroyHandle(osal_handle);
  CtorIifDestroyHandle(iif_handle);
}

module_init(DemoIifInit);
module_exit(DemoIifExit);
