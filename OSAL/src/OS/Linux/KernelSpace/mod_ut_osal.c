#include <linux/init.h>
#include <linux/module.h>
#include <ut_pub.h>

extern UtResult UtOsalWholeTest(void);
EXPORT_SYMBOL(UtOsalWholeTest);

MODULE_LICENSE("Dual BSD/GPL");

static int UtOsalInit(void)
{
  printk(KERN_ALERT "Hello, UtOsal\n");
  return 0;
}

static void UtOsalExit(void)
{
  printk(KERN_ALERT "Goodbye, UtOsal\n");
}

module_init(UtOsalInit);
module_exit(UtOsalExit);
