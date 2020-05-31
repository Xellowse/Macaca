#include <linux/init.h>
#include <linux/module.h>
#include <iif_pub.h>

extern IifS32 IifInit(void *handle);
extern IifS32 IifDeinit(void *handle);
extern IifS32 IifMethod1(void *handle);
extern IifS32 IifDualInit(void *handle);
extern IifS32 IifDualDeinit(void *handle);
extern IifS32 IifDualMethod1(void *handle);

MODULE_LICENSE("Dual BSD/GPL");

EXPORT_SYMBOL(IifInit);
EXPORT_SYMBOL(IifDeinit);
EXPORT_SYMBOL(IifMethod1);
EXPORT_SYMBOL(IifDualInit);
EXPORT_SYMBOL(IifDualDeinit);
EXPORT_SYMBOL(IifDualMethod1);


static int OsalIifInit(void)
{
  printk(KERN_ALERT "Hello, OSAL IIF\n");
  return 0;
}

static void OsalIifExit(void)
{
  printk(KERN_ALERT "Goodbye, OSAL IIF\n");
}

module_init(OsalIifInit);
module_exit(OsalIifExit);
