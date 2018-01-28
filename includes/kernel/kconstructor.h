#ifndef KERNEL_KCONSTRUCTOR_H
#define KERNEL_KCONSTRUCTOR_H



#define _KCONSTUCTOR_NAME(name) __kconstructor_ ## name
#define KCONSTRUCTOR_PTRS "kconstructor_pointers"
#define KCONSTRUCTOR_CODE "kconstructor_code"

typedef int (*kconstructor_t)(void);

extern kconstructor_t *kconstructor_first, *kconstructor_last;

#define define_module_constructor(name, ...) \
	static void __attribute__ ((__section__ (KCONSTRUCTOR_CODE))) _KCONSTUCTOR_NAME(name)(void) \
	{ \
		__VA_ARGS__; \
	} \
	static kconstructor_t _KCONSTUCTOR_NAME(name) ## ptr __attribute__ ((unused,__section__ (KCONSTRUCTOR_PTRS))) = _KCONSTUCTOR_NAME(name);

#endif
