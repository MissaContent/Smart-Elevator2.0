//
// Created by Lucas Mrc on 11/12/2018.
//
#include <stdio.h>
#include <stdlib.h>
#include "Menu.h"
#include "Floor.h"
#include <fcntl.h>

void Choice_Menu() {

        int menu;
        printf("------MENU------\n\n");
        printf("1 : Define the floor where you are\n");
        printf("2 : Define the floor where you want to go\n");
        printf("3 : Call the elevator\n");
        printf("4 : Stop the program\n\n");
        scanf("%d", &menu);
        int valid = 1;
        int *pointer_Valid = &valid;

        switch (menu) {
            case 1:
                Choice_Position();
            case 2:
                Choice_Call();
            case 3:
                Choice_Direction();
                break;
            case 4:
                exit(EXIT_SUCCESS);
            default:
                printf("You entered an invalid input\n\n");
                exit(EXIT_SUCCESS);
        }
}