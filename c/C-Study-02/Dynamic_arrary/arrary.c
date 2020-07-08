#include "arrary.h"

static int capacity;

int ReallocArrary(void ***p_ptr_arrary, int length) {
  capacity += 10;
  void **arrary_new = malloc(sizeof(void *) * capacity);
  if (arrary_new == NULL) {
    return -1;
  }

  printf("[Realloc]  address old = %p, address new = %p\n", *p_ptr_arrary, arrary_new);

  /*move the data from the old array to the new array*/
  memcpy(arrary_new, *p_ptr_arrary, sizeof(void *) * length);

  free(*p_ptr_arrary);
  *p_ptr_arrary = arrary_new;

  return 0;
}

int CheckArraryAvailableLength(struct dynamicArrary *arrary) {
  if (arrary->length == capacity) {
    int flag = ReallocArrary(&arrary->ptr_arrary, arrary->length);
    if (!flag) {
      printf("[Realloc complete]  struct address = %p, arrary adderss = %p\n",
             arrary,
             arrary->ptr_arrary);
    }
  }

  return 0;
}

struct dynamicArrary *InitDynamicArrary(int m_capacity) {
  if (m_capacity <= 0) {
    return NULL;
  }

  capacity = m_capacity;

  struct dynamicArrary *arrary = malloc(sizeof(struct dynamicArrary));
  if (arrary == NULL) {
    return NULL;
  }
  memset(arrary, 0, sizeof(struct dynamicArrary));

  arrary->ptr_arrary = malloc(sizeof(void *) * m_capacity);
  if (arrary->ptr_arrary == NULL) {
    return NULL;
  }
  memset(arrary->ptr_arrary, 0, sizeof(void *) * m_capacity);

  printf("[Init dynamic arrary]  struct address = %p, arrary adderss = %p\n",
         arrary,
         arrary->ptr_arrary);

  return arrary;
}

int Insert(struct dynamicArrary *arrary, int index, void *value) {
  if (index < 0) {
    return -1;
  }
  if (CheckArraryAvailableLength(arrary)) {
    return -1;
  }
  if (index >= arrary->length) {
    index = arrary->length;
  }

  for (int i = arrary->length - 1; i >= index; i--) {
    memcpy(arrary->ptr_arrary + i + 1, arrary->ptr_arrary + i, sizeof(void *));
  }

  /*insert*/
  memcpy(arrary->ptr_arrary + index, &value, sizeof(void *));

  arrary->length++;
  return 0;
}

int Add(struct dynamicArrary *arrary, void *value) {
  if (CheckArraryAvailableLength(arrary)) {
    return -1;
  }

  printf("[Add]  arrary address = %p, value address = %p, arrary length = %d\n",
         arrary->ptr_arrary + arrary->length,
         value,
         arrary->length + 1);
  memcpy(arrary->ptr_arrary + arrary->length, &value, sizeof(void *));
  arrary->length++;
  return 0;
}

int RemoveByPostion(struct dynamicArrary *arrary, int index) {
  if (index < 0) {
    return -1;
  }
  if (index >= arrary->length) {
    index = arrary->length;
  }

  printf("[Remove]  address = %p\n", *(arrary->ptr_arrary + index));
  free(*(arrary->ptr_arrary + index));

  for (int i = index + 1; i < arrary->length; i++) {
    printf("[Exchange]  address_exchanged = %p, address_exchanger = %p\n",
           arrary->ptr_arrary + i - 1,
           arrary->ptr_arrary + i);
    *(arrary->ptr_arrary + i - 1) = *(arrary->ptr_arrary + i);
    *(arrary->ptr_arrary + i) = NULL;
  }

  arrary->length--;

  return 0;
}

int RemoveByValue(struct dynamicArrary *arrary, void *value, int (*invoker)(void *data_source, void *data_compare)) {
  if (arrary == NULL || invoker == NULL) {
    return -1;
  }

  for (int i = 0; i < arrary->length; i++) {
    if (invoker(*(arrary->ptr_arrary + i), value)) {
      RemoveByPostion(arrary, i);
      break;
    }
  }

  return 0;
}

int DestoryArrary(struct dynamicArrary *arrary) {
  if (arrary == NULL) {
    return -1;
  }

  printf("are you sure destory arrary? [yes/no]\n");

  char str_CustomerInput[8] = { 0 };
  fgets(str_CustomerInput, sizeof(str_CustomerInput), stdin);

  if (strcmp(str_CustomerInput, "yes\n")) {
    return -1;
  }

  for (int i = 0; i < arrary->length; i++) {
    printf("[free]  element address = %p\n", *(arrary->ptr_arrary + i));
    free(*(arrary->ptr_arrary + i));
  }

  printf("[free]  arrary address = %p\n", arrary->ptr_arrary);
  free(arrary->ptr_arrary);

  printf("[free]  struct address = %p\n", arrary);
  free(arrary);

  capacity = 0;

  return 0;
}
