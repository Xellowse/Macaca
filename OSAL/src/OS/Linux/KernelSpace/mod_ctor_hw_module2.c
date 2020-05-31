#include <linux/init.h>
#include <linux/module.h>
#include <hw_module2_pub.h>
#include <ctor_hw_module2_pub.h>
MODULE_LICENSE("Dual BSD/GPL");


EXPORT_SYMBOL(CtorHwModule2CreateHandle);
EXPORT_SYMBOL(CtorHwModule2DestroyHandle);

static int OsalCtorHwModule2Init(void)
{
  printk(KERN_ALERT "Hello, CTOR HW Module2\n");
  return 0;
}

static void OsalCtorHwModule2Exit(void)
{
  printk(KERN_ALERT "Goodbye, CTOR HW Module2\n");
}

module_init(OsalCtorHwModule2Init);
module_exit(OsalCtorHwModule2Exit);
