//
// Created by Lucas Mrc on 12/12/2018.
//

#include "RandomFloor.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void RandomFloor (int *pointer_E1_Floor, int *pointer_E2_Floor) {

   int elevator1, elevator2;

   const int MIN = 1, MAX = 12;

   elevator1 = (rand() % (MAX - MIN + 1)) + MIN;
   printf("\nThe first elevator is at floor number %d\n", elevator1);

   elevator2 = (rand() % (MAX - MIN + 1)) + MIN;
   printf("The second elevator is at floor bumber %d\n\n", elevator2);

   *pointer_E1_Floor = elevator1;
   *pointer_E2_Floor = elevator2;

}