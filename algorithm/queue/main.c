#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <Windows.h>

#include "queue.h"

int main(void) {
  Queue *q = CreateQueue();

  AddQ(q, 1);
  PrintQueue(q);

  DeleteQ(q);
  PrintQueue(q);

  AddQ(q, 2);
  AddQ(q, 3);
  AddQ(q, 4);
  PrintQueue(q);

  DeleteQ(q);
  DeleteQ(q);
  PrintQueue(q);

  AddQ(q, 5);
  AddQ(q, 6);
  PrintQueue(q);


  system("pause");
  return EXIT_SUCCESS;
}