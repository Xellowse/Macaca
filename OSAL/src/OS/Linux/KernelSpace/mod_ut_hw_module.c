#include <linux/init.h>
#include <linux/module.h>
#include <ut_pub.h>

extern UtResult UtHwModuleWholeTest(void);
EXPORT_SYMBOL(UtHwModuleWholeTest);

MODULE_LICENSE("Dual BSD/GPL");

static int UtHwModuleInit(void)
{
  printk(KERN_ALERT "Hello, UtHwModule\n");
  return 0;
}

static void UtHwModuleExit(void)
{
  printk(KERN_ALERT "Goodbye, UtHwModule\n");
}

module_init(UtHwModuleInit);
module_exit(UtHwModuleExit);
