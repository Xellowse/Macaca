#include <linux/init.h>
#include <linux/module.h>
#include <ut_pub.h>

extern UtResult UtHwModule2WholeTest(void);
EXPORT_SYMBOL(UtHwModule2WholeTest);

MODULE_LICENSE("Dual BSD/GPL");

static int UtHwModule2Init(void)
{
  printk(KERN_ALERT "Hello, UtHwModule2\n");
  return 0;
}

static void UtHwModule2Exit(void)
{
  printk(KERN_ALERT "Goodbye, UtHwModule2\n");
}

module_init(UtHwModule2Init);
module_exit(UtHwModule2Exit);
