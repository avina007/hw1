#include <linux/init.h>
#include <linux/gcd.h>
#include <linux/jiffies.h>
#include <linux/timer.h>
#include <linux/kernel.h>
#include <linux/hash.h>
#include <linux/module.h>
unsigned long jin,hz,jout;
int simple_init(void){
	jin = jiffies;
	hz = HZ;
	printk("simple_init()\n");
	printk("init jiffies = %lu and HZ == %lu\n",jin,hz);
	printk( "Golden Ratio = %lu\n", GOLDEN_RATIO_PRIME);
	
	return 0;
}
void simple_exit(void){
	jout = jiffies;
	printk("simple_exit()\n");
	printk("exit jiffies = %lu\n",jout);
	printk("%lu\n",gcd(3300,24));
}
module_init(simple_init);
module_exit(simple_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Simple Module");
MODULE_AUTHOR("SGG");

