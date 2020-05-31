#include <linux/init.h>
#include <linux/module.h>
#include <ut_pub.h>

extern UtResult UtHalModule2WholeTest(void);
EXPORT_SYMBOL(UtHalModule2WholeTest);

MODULE_LICENSE("Dual BSD/GPL");

static int UtHalModule2Init(void)
{
  printk(KERN_ALERT "Hello, UtHalModule2\n");
  return 0;
}

static void UtHalModule2Exit(void)
{
  printk(KERN_ALERT "Goodbye, UtHalModule2\n");
}

module_init(UtHalModule2Init);
module_exit(UtHalModule2Exit);
