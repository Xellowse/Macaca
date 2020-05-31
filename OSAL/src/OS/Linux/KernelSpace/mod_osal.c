#include <linux/init.h>
#include <linux/module.h>
MODULE_LICENSE("Dual BSD/GPL");

static int OsalInit(void)
{
  printk(KERN_ALERT "Hello, OSAL\n");
  return 0;
}

static void OsalExit(void)
{
  printk(KERN_ALERT "Goodbye, OSAL\n");
}

module_init(OsalInit);
module_exit(OsalExit);
