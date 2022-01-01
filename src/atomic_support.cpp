// DMT proprietary 2021
#ifdef NRF51  // Cortex M0
extern "C" {
extern void vPortEnterCritical(void);
extern void vPortExitCritical(void);
extern unsigned int __atomic_fetch_add_4(volatile void*, unsigned int, int);
}

unsigned int __atomic_fetch_add_4(volatile void *p, unsigned int v, int) {
	vPortEnterCritical();
	unsigned int t = *(volatile unsigned int *)p;
	*(volatile unsigned int *)p = t + v;
	vPortExitCritical();
	return t;
}
#endif
