#include <linux/init.h>
#include <linux/module.h>
#include <ctor_osal_pub.h>

MODULE_LICENSE("Dual BSD/GPL");


EXPORT_SYMBOL(CtorOsalCreateHandle);
EXPORT_SYMBOL(CtorOsalDestroyHandle);

static int OsalCtorInit(void)
{
  printk(KERN_ALERT "Hello, OSAL Ctor\n");
  return 0;
}

static void OsalCtorExit(void)
{
  printk(KERN_ALERT "Goodbye, OSAL Ctor\n");
}

module_init(OsalCtorInit);
module_exit(OsalCtorExit);
