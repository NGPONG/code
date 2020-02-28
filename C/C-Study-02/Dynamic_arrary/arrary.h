#ifndef __ARRARY_H__
#define __ARRARY_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct dynamicArrary {

	void **ptr_arrary;
	int length;
};

struct dynamicArrary *InitDynamicArrary(int m_capacity);
int Add(struct dynamicArrary *arrary, void *value);
int Insert(struct dynamicArrary *arrary, int index, void *value);
int RemoveByPostion(struct dynamicArrary *arrary, int index);
int RemoveByValue(struct dynamicArrary *arrary, void *value, int (*invoker)(void *data_source, void *data_compare));
int DestoryArrary(struct dynamicArrary *arrary);

#endif // !__ARRARY_H__
