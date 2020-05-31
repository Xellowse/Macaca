#include <linux/init.h>
#include <linux/module.h>
#include <hw_module_pub.h>
#include <ctor_hw_module_pub.h>
MODULE_LICENSE("Dual BSD/GPL");


EXPORT_SYMBOL(CtorHwModuleCreateHandle);
EXPORT_SYMBOL(CtorHwModuleDestroyHandle);

static int OsalCtorHwModuleInit(void)
{
  printk(KERN_ALERT "Hello, OSAL CTOR HW Module\n");
  return 0;
}

static void OsalCtorHwModuleExit(void)
{
  printk(KERN_ALERT "Goodbye, CTOR HW Module\n");
}

module_init(OsalCtorHwModuleInit);
module_exit(OsalCtorHwModuleExit);
