// this is Attack.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "direction.h"
#include "typedefs.h"
#include "look.h"
#include "attack.h"
#include "main.h"
extern char name[15];
Character player;
Character creature;
char menu_commands_variable[15];
extern int current_position;
void menu_commands();
void player_attack(Character *player, Character *creature)
{
  int damage = (rand() % player->strength) + 10;
  creature->health -= damage;
  printf("%s hits %s with %d damage.\n", player->name, creature->name, damage);
  printf("%s's health is now %d.\n", creature->name, creature->health);
}
void creature_attack(Character *creature, Character *player)
{
  int damage = (rand() % creature->strength) + 10;
  player->health -= damage;
  printf("%s hits %s with %d damage.\n", creature->name, player->name, damage);
  printf("%s's health is now %d.\n", player->name, player->health);
}

int is_defeated(Character *character)
{
  return character->health <= 0;
}

void attack()
{

  strcpy(player.name, name);
  player.health = 100;
  player.strength = 10;

  strcpy(creature.name, "Guardian");
  creature.health = 100;
  creature.strength = 8;

  if (current_position == 5)
  {
    printf("A battle has begun.\n");
    printf("%s fighting with %s.\n", player.name, creature.name);

    while (!is_defeated(&player) && !is_defeated(&creature))
    {

      // Player starts battle
      player_attack(&player, &creature);
      if (is_defeated(&creature))
      {
        printf("Congratulations.%s has been defeated.You win.\n", creature.name);
        printf("You have got the treasure.\n");
        printf("You have became rich and powerful.\n");
        printf("Game ends here.\n");
        exit(0);
      }

      // Guardians turn
      creature_attack(&creature, &player);
      if (is_defeated(&player))
      {
        printf("You have been defeated by %s.\n", creature.name);
        printf("Game ends here.\n");
        exit(0);
      }
    }
  }
  else
  {
    printf("There isn't any guardian to attack.\n");
    command();
  }
}