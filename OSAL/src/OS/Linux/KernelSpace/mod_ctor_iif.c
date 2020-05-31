#include <linux/init.h>
#include <linux/module.h>
#include <ctor_iif_pub.h>
MODULE_LICENSE("Dual BSD/GPL");


EXPORT_SYMBOL(CtorIifCreateHandle);
EXPORT_SYMBOL(CtorIifDestroyHandle);

static int OsalIifContrInit(void)
{
  printk(KERN_ALERT "Hello, OSAL IIF CONTR\n");
  return 0;
}

static void OsalIifContrExit(void)
{
  printk(KERN_ALERT "Goodbye, OSAL IIF CONTR\n");
}

module_init(OsalIifContrInit);
module_exit(OsalIifContrExit);
