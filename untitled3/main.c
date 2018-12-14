#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fcntl.h>

#include "Menu.h"
#include "RandomFloor.h"
#include "Floor.h"


int main() {

    int current_Floor;
    int *pointerCF = &current_Floor;
    int elevator1, elevatoe2 = 0;

    srand(time(NULL));
    RandomFloor (&elevator1, &elevatoe2);


    Choice_Menu();





    return 0;

}
