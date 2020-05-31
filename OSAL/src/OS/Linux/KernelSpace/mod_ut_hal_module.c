#include <linux/init.h>
#include <linux/module.h>
#include <ut_pub.h>

extern UtResult UtHalModuleWholeTest(void);
EXPORT_SYMBOL(UtHalModuleWholeTest);

MODULE_LICENSE("Dual BSD/GPL");

static int UtHalModuleInit(void)
{
  printk(KERN_ALERT "Hello, UtHalModule\n");
  return 0;
}

static void UtHalModuleExit(void)
{
  printk(KERN_ALERT "Goodbye, UtHalModule\n");
}

module_init(UtHalModuleInit);
module_exit(UtHalModuleExit);
