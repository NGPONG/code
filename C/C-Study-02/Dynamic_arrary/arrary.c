#include "arrary.h"

static int capacity;

struct dynamicArrary *init_dynamic_arrary(int m_capacity) {

	if (capacity <= 0) {

		printf("invalid argument capacity");
		return NULL;
	}

	capacity = m_capacity;

	struct dynamicArrary *arrary = malloc(sizeof(struct dynamicArrary));
	if (arrary == NULL) {
	
		printf("create heap space error");
		return NULL;
	}
	arrary->length = 0;
	arrary->ptr_arrary = malloc(sizeof(void *) * m_capacity);
	if (arrary->ptr_arrary == NULL) {
	
		printf("create heap space error");
		return NULL;
	}

	return arrary;
}

struct dynamicArrary *insert(struct dynamicArrary *arrary,int index, void *value) {

	if (index < 0) {
	
		printf("invalid argument index");
		return NULL;
	}

	/*Always insert in tail element*/
	if (index > arrary->length) {
	
		index = arrary->length;
	}


}