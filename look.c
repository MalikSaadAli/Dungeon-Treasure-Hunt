// this is look.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "look.h"
#include "direction.h"
#include "main.h"
#include "typedefs.h"
extern int has_dagger;
extern int has_pistol;
extern int has_thorny_rose;
extern int has_ak_47;
extern int has_item;
extern int current_position;
extern int count;
extern Inventory current_item;
void look();

// if user enters look.This function handles it
void look()
{

    if (current_position == 0)
    {
        printf("There is a dagger.\n");
        command();
    }
    else if (current_position == 1)
    {
        printf("There is a pistol.\n");
        command();
    }
    else if (current_position == 2)
    {
        printf("There is nothing.\n");
        command();
    }
    else if (current_position == 3)
    {
        printf("There is a rose with big and fatal thorns.\n");
        command();
    }
    else if (current_position == 4)
    {
        printf("There is a Akm(AK-47) gun.\n");
        command();
    }
    else if (current_position == 5)
    {
        printf("There is a guardian proteting treasure.\n");
        command();
    }
}
