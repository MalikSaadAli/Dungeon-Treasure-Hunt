// This is a command-line text based game.
// this is main.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "direction.h"
#include "typedefs.h"
#include "look.h"
#include "attack.h"

int current_position;
// PROTOTYPE OF FUNCTIONS
void pick_up();
void drop();
void clear_stdin();

char name[15];
Inventory current_item;
int has_item = 0;
int has_dagger = 0;
int has_pistol = 0;
int has_thorny_rose = 0;
int has_ak_47 = 0;
int count = 0;

void clear_stdin()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

void pick_up()
{

    if (count < 2)
    {
        if (current_position == 0)
        {

            //   strcpy(current_item.item_names[0] , "Dagger");
            current_item.item_quantity[0]++;
            has_dagger++;
            count++;
            printf("Picked.\n");
            command();
        }
        else if (current_position == 1)
        {
            //  strcpy(current_item.item_names[1] , "Pistol");
            current_item.item_quantity[1]++;
            has_pistol++;
            count++;
            printf("Picked.\n");
            command();
        }
        else if (current_position == 2)
        {

            printf("There is nothing to pickup.\n");
            command();
        }
        else if (current_position == 3)
        {
            current_item.item_quantity[2]++;
            has_item++;
            has_thorny_rose++;
            count++;
            printf("Picked.\n");
            command();
        }
        else if (current_position == 4)
        {
            current_item.item_quantity[3]++;
            has_item++;
            has_ak_47++;
            count++;
            printf("Picked.\n");
            command();
        }

        else if (current_position == 5)
        {
            printf("Nothing to  pickup.\n");
        }
    }

    else
    {
        printf("Back Pack is full.\n");
        command();
    }
}

void drop(char drop_item[15])
{

    if (count > 0)
    {
        if (strcmp(drop_item, "drop dagger") == 0)
        {
            current_item.item_quantity[0]--;

            if (has_dagger > 0)
            {
                printf("Dropped successfully.\n");
                has_dagger--;
                count--;
                command();
            }
            else
            {
                printf("There isn't any dagger to drop.\n");
                command();
            }
        }
        else if (strcmp(drop_item, "drop pistol") == 0)
        {
            current_item.item_quantity[1]--;
            if (has_pistol > 0)
            {
                printf("Dropped successfully.\n");
                has_pistol--;
                count--;
                command();
            }
            else
            {
                printf("There isn't any pistol to drop.\n");
                command();
            }
        }
        else if (strcmp(drop_item, "drop thorny rose") == 0)
        {
            current_item.item_quantity[2]--;

            if (has_thorny_rose > 0)
            {
                printf("Dropped successfully.\n");
                has_thorny_rose--;
                count--;
                command();
            }
            else
            {
                printf("There isn't any thorny rose to drop.\n");
                command();
            }
        }
        else if (strcmp(drop_item, "drop akm") == 0)
        {
            current_item.item_quantity[0]--;
            count--;
            if (has_ak_47 > 0)
            {
                printf("Dropped successfully.\n");
                has_ak_47--;
                command();
            }
            else
            {
                printf("There isn't any akm gun to drop.\n");
                command();
            }
        }
    }
    else
    {
        printf("No item to drop.\n");
        command();
    }
}

int file_name_handler = 0;

extern char name[15];
Character player;
Character creature;
char menu_commands_variable[15];
extern int current_position;

int main()
{

    current_position = 0;

    strcpy(current_item.item_names[0], "Dagger");
    strcpy(current_item.item_names[1], "Pistol");
    strcpy(current_item.item_names[2], "Thorny Rose");
    strcpy(current_item.item_names[3], "Ak-47");
    current_item.item_quantity[0] = 0;
    current_item.item_quantity[1] = 0;
    current_item.item_quantity[2] = 0;
    current_item.item_quantity[3] = 0;
    current_position = 0;

    srand(time(NULL));
    printf("Welcome to the Dungeon Treasure Hunt Game.\n");
    printf("Please enter your user name \n");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0;

    if (fgets(name, 15, stdin))
    {

        if (strchr(name, '\n') == NULL)
        {

            clear_stdin();
        }
    }

    printf("Welcome, %s.You adventure begins here.\n", name);
    printf("Press (S) or (s) to start playing.\n");
    printf("Press (E) or (e) to exit.\n");
    char starter;
    scanf(" %c", &starter);
    getchar();
    if (starter == 's' || starter == 'S')
    {
        printf("You are at starting point.\n");
        // printf("There is a sofa , bed , and table.\n");
        while (1 < 2)
        {
            command();
        }
    }
    else if (starter == 'e' || starter == 'E')
    {
        printf("Exited successfully.\n");
        exit(0);
    }
    else
    {
        printf("Invalid command.Exiting...");
        exit(0);
    }

    return 0;
}
