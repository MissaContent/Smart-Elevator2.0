//
// Created by Lucas Mrc on 14/12/2018.
//
#include <stdlib.h>
#include <stdio.h>
#include "Floor.h"
#include <fcntl.h>

int current_Floor;
int *pointerCF = &current_Floor;
int elevator_Floor = 5;
int *pointer_E_Floor;

void Choice_Position() {

    int res, valid = 0;

    do {
        do {
            printf("Specify which floor you are on\n\n");
            res = scanf("%d", &current_Floor);
            while (getchar() != '\n');
            if (res != 1) {
                printf("Input error, enter a number in the range\n\n");
            }
        } while (res != 1);

        if (current_Floor >= 1 && current_Floor <= 12) {
            printf("You are on the floor number %d\n", current_Floor);
            valid = 1;
        } else {
            printf("You entered an invalid floor\n");
        }
    } while (valid != 1);
}


void Choice_Call() {

    if (elevator_Floor == current_Floor) {
        printf("The elevator is already at the same floor as you\n");
    }

    if (elevator_Floor != current_Floor) {
        int press;
        int res;
        printf("To call the elevator, press 1\n");
        res = scanf("%d", &press);
        while (getchar() != '\n');
        if (res != 1) {
            printf("Invalid input, press 1 to call the elevator\n\n");
        }

        if (press == 1) {

            if (elevator_Floor < current_Floor) {
                printf("The elevator is coming...\n");
                while (elevator_Floor != current_Floor) {
                    elevator_Floor++;
                    printf("Floor number %d\t", elevator_Floor);
                }
                printf("The elevator is arrived\n");
            }

            if (elevator_Floor > current_Floor) {
                printf("The elevator is coming\n");
                while (elevator_Floor != current_Floor) {
                    elevator_Floor--;
                    printf("Floor number %d", elevator_Floor);
                }
                printf("The elevator is arrived\n");
            }

        }
    }
}


void Choice_Direction() {

    int direction;
    int *pointerDirection = &direction;
    int valid, res1, res2 = 0;

    do {
        do {
            printf("Would you like to go upstairs or downstairs ?\n 1 : Upstairs\n 2 : Downstairs\n\n");

            res1 = scanf("%d", &direction);
            while (getchar() != '\n');
            if (res1 != 1) {
                printf("Input error, enter a number in the range\n\n");
            }
        } while (res1 != 1);

        if (direction == 1) {
            do {
                int desired_Floor_Up = 0;
                do {
                    printf("Which floor do you want to go ?\n");
                    res2 = scanf("%d", &desired_Floor_Up);
                    while (getchar() != '\n');
                    if (res2 != 1) {
                        printf("Input error, enter a number in the range\n\n");
                    }
                } while (res2 != 1);

                if (desired_Floor_Up > current_Floor && desired_Floor_Up <= 12) {

                    while (current_Floor != desired_Floor_Up) {

                        current_Floor = current_Floor + 1;
                        printf("Floor number %d\n", current_Floor);
                    }
                    printf("\nYou are arrived !\n");
                    valid = 1;
                    exit(EXIT_SUCCESS);
                } else if (desired_Floor_Up < current_Floor || desired_Floor_Up > 12 || desired_Floor_Up <1 ) {

                    printf("Your desired floor is smaller than your current floor or you entered a floor to high\n\n");
                    valid = 0;
                }
            } while (valid != 1);
        }


        if (direction == 2) {
            do {
                int desired_Floor_Down;
                do {

                    printf("Which floor do you want to go ?\n");
                    res2 = scanf("%d", &desired_Floor_Down);
                    while (getchar() != '\n');
                    if (res2 != 1) {
                        printf("Input error, enter a number in the range\n\n");
                    }
                } while (res2 != 1);

                if (desired_Floor_Down < current_Floor && desired_Floor_Down >= 1) {

                    while (current_Floor != desired_Floor_Down) {

                        current_Floor = current_Floor - 1;
                        printf("Floor number %d\n", current_Floor);
                    }
                    printf("\nYou are arrived !\n");
                    valid = 1;
                    exit(EXIT_SUCCESS);
                } else if (desired_Floor_Down > current_Floor || desired_Floor_Down < 1 || desired_Floor_Down > 12) {

                    printf("Your desired floor is bigger than your current floor or you entered a floor to less\n\n");
                    valid = 0;
                }
            } while (valid != 1);
        } else {
            printf("Enter 1 to go upstairs or enter 2 to go downstairs\n\n");
        }
    } while (valid != 1);
}
