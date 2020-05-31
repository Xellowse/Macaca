#include <linux/init.h>
#include <linux/module.h>
#include <ut_pub.h>

extern UtU32 UtUTAll(void);

MODULE_LICENSE("Dual BSD/GPL");

static int UtAllInit(void)
{
  printk(KERN_ALERT "Hello, UT All\n");

  return UtUTAll();
}

static void UtAllExit(void)
{
  printk(KERN_ALERT "Goodbye, UT All\n");
}

module_init(UtAllInit);
module_exit(UtAllExit);
