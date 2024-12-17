// this is direction.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "direction.h"
#include "main.h"
#include "look.h"
#include "typedefs.h"
#include "attack.h"

static int floor = 0;
static int counter_up = 0;
static int counter_right = 0;
static int counter_left = 0;
static int current_floor = 0;
static int arr[3][3]; // arr[0][0] is starting point on ground floor and goes like that
extern int current_position;
Inventory current_item;
extern char file_name[15];
extern char menu_commands_variable[15];
char movement_check[15] = "";

char drop_item[15];

void up()
{
    if (counter_up == 1)
    {
        printf("You are in the hall on the 1st floor.\nThere is a balcony on right side.\nAnd a room on left side.\n ");
        floor = 1;
        current_floor = 1;
        current_position = 2;
        command();
    }
    if (counter_up == 2)
    {
        printf("You are in balcony on the top floor of the house.\n");
        printf("What a beautiful view from here.\n");
        floor = 2;
        current_floor = 2;
        current_position = 5;
        command();
    }
    if (counter_up > 2)
    {
        printf("It is not possible to go there.\n");
        floor = 2;
        current_floor = 2;
        command();
    }
}
// move down handling
void down()
{
    if (floor < 0)
    {
        printf("It is not possible to go down\n");
        counter_up = 0;
        current_floor = 0;
        command();
    }
    else
    {
        if (floor == 0)
        {
            printf("You are at starting point on the ground floor.\n");
            counter_up = 0;
            current_floor = 0;
            current_position = 0;
            command();
        }
        else if (floor == 1)
        {
            printf("You are in the centre of 1st floor.\nThere is a balcony on right side.\nAnd a room on left side.\n ");
            counter_up = 1;
            current_floor = 1;
            current_position = 2;
            command();
        }
    }
}
// move right
void right()
{

    if (current_floor == 0)
    {
        // this if control the movement of player in same room
        if (counter_right == 1)
        {
            printf("It is not possible to go right.\n");
            command();
        }
        else
        {
            printf("You are in room on the ground floor.\n");
            counter_right = 1;
            arr[0][1] = 1;
            current_position = 1;
            command();
        }
    }
    else if (current_floor == 1)
    {
        if (arr[1][2] == 1)
        {
            printf("You are in the hall on the 1st floor.\n");
            arr[1][2] = 0;
            current_position = 2;
            command();
        }

        if (counter_right == 1)
        {
            printf("It is not possible to go right.\n");
            command();
        }
        else
        {
            printf("You are in balcony on the 1st floor.\n");
            counter_right = 1;
            arr[1][1] = 1;
            current_position = 3;
            command();
        }
    }
    else if (current_floor == 2)
    {
        printf("It is not possible to go right.\n");
        command();
    }
}

// move left
void left()
{

    if (current_floor == 0)
    {
        if (arr[0][1] == 1)
        {
            printf("You are at starting point on the ground floor.\n");
            arr[0][1] = 0;
            current_position = 0;
            command();
        }
        else
        {
            printf("It is not possible to go left.\n");
            command();
        }
    }
    else if (current_floor == 1)
    {
        if (arr[1][1] == 1)
        {
            printf("You are in the hall on the 1st floor.\n");
            arr[1][1] = 0;
            current_position = 2;
            command();
        }
        if (counter_left == 1)
        {
            printf("It is not possible to go left.\n");
            command();
        }
        else
        {
            printf("You are in room on the 1st floor.\n");

            counter_left = 1;
            arr[1][2] = 1;
            current_position = 4;
            command();
        }
    }
    else if (current_floor == 2)
    {
        printf("It is not possible to go left.\n");
        command();
    }
}
// Command handler
void command()
{
    char user_input[15];
    fgets(user_input, sizeof(user_input), stdin);
    user_input[strcspn(user_input, "\n")] = 0;

    if (strcmp(user_input, "look") == 0)
    {
        look();
    }
    else if (strcmp(user_input, "attack") == 0)
    {
        attack();
    }
    else if (strcmp(user_input, "pickup") == 0)
    {
        if (current_position == 5 || current_position == 2)
        {
            printf("Nothing to pickup.\n");
            command();
        }
        else
        {
            pick_up();
        }
    }
    else if (strcmp(user_input, "move up") == 0)
    {

        counter_up++;
        counter_right = 0;
        counter_left = 0;
        up();
    }
    else if (strcmp(user_input, "move down") == 0)
    {
        floor--;
        counter_up--;
        counter_right = 0;
        counter_left = 0;
        down();
    }
    else if (strcmp(user_input, "move right") == 0)
    {
        counter_left = 0;
        right();
    }
    else if (strcmp(user_input, "move left") == 0)
    {
        counter_right = 0;
        left();
    }

    else if (strcmp(user_input, "exit") == 0)
    {
        printf("You exited successfully.Good Luck.\n");
        exit(0);
    }
    else if (strcmp(user_input, "inventory") == 0)
    {

        printf("Inventory : \n");
        printf("Item Name\tItem Quantity\n");
        printf("%s\t\t%d\n", current_item.item_names[0], current_item.item_quantity[0]);
        printf("%s\t\t%d\n", current_item.item_names[1], current_item.item_quantity[1]);
        printf("%s\t%d\n", current_item.item_names[2], current_item.item_quantity[2]);
        printf("%s\t\t%d\n", current_item.item_names[3], current_item.item_quantity[3]);
    }
    else if (strcmp(user_input, "drop") == 0)
    {
        printf("What do you want to drop.\n");
        fgets(drop_item, sizeof(drop_item), stdin);
        drop_item[strcspn(drop_item, "\n")] = 0;
        drop(drop_item);
    }
    else
    {
        printf("Invalid Command!!.Enter another command.\n");
        command();
    }
}
