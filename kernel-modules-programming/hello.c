#include <linux/init.h>
#include <linux/module.h>
// NOT CHECKED: without such a declaration, the kernel complains when the module is loaded
MODULE_LICENSE("Dual BSD/GPL"); 

static int hello_init(void)
{   
	// PRIORITY STRING: KERN_ALERT
	printk(KERN_ALERT "starting hello\n");
    return 0;
}

static void hello_exit(void)
{   printk(KERN_ALERT "Exiting hello\n");
}

module_init(hello_init);
module_exit(hello_exit);