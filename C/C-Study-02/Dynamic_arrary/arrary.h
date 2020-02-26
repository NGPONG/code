#ifndef __ARRARY_H__
#define __ARRARY_H__

#include <stdio.h>
#include <corecrt_malloc.h>

struct dynamicArrary {

	void **ptr_arrary;
	int length;
	int (*init_dynamic_arrary)(int);
};



#endif // !__ARRARY_H__
