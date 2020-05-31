#include <linux/init.h>
#include <linux/module.h>
#include <ut_pub.h>

extern UtResult UtIifWholeTest(void);
EXPORT_SYMBOL(UtIifWholeTest);

MODULE_LICENSE("Dual BSD/GPL");

static int UtIifInit(void)
{
  printk(KERN_ALERT "Hello, Ut Iif\n");
  return 0;
}

static void UtIifExit(void)
{
  printk(KERN_ALERT "Goodbye, Ut Iif\n");
}

module_init(UtIifInit);
module_exit(UtIifExit);
