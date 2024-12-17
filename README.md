GAME LOGIC : 
Name of the game is Dungeon Treasure Hunt.Where in order to complete the game player has to claim the treasure.
This game has a house.A house which has total 2 floors.This house is very famous in Pubg mobile game.So it is named as Squad House.It has Ground floor , 1st floor and 2nd floor.There are totally 6 points(locations) where player can be.

Ground floor has two points(locations where player can be).0 point which is considered as starting point.0th point is a hall on ground floor.Ground floor also has a room which is right side of the hall.This room is considered as 1st  point.
1st floor has three points.2nd , 3rd and 4th point.2nd point is a hall on 1st floor.This hall leades to a balcony which is right side of it.This balcony’s point is 3.And a room which is left side of it.This room’s point is 4.
2nd floor has only 1 point.Which is also a kind of balcony.The treasure is here but a guardian is protecting it.So player has to fight with it by attack command.

Game works with move <direction> (up,down,right,left), attack , pickup , inventory(whey player enters inventory it shows the weapons and their quantity) , and last one look(by entering this player can know the item which are there in players position).
If users enter invalid direction it says “It is not possible to go <direction>”.If user enters any other invalid command it says”Invalid command!Enter another command”.


CODE STRUCTURE :

Code consists of 5 files.main.c , attack.c , direction.c , look.c and typedefs.h.Below i will tell what each file does.
1.	main.c : Code starts running from here.main.c has 2 functions except main function which are pick_up() and drop().pick_up() functions handles the pickup situation.And drop() handles situation when user wants to drop weapon.
2.	attack.c : As we can understand from the name.attack.c got functions which are aimed to handle the attack keyword from user.And attack continues until one side is defeated.
3.	direction.c : This file controls the navigation of user during game.
4.	look.c : This file handles look keyword.When user enters look it shows the weapon in room if there is any.
5.	typedefs.h : It contains two typedefs 1st one is named as Inventory.2nd one is named as Character.Inventory contains weapon names and their quantities.Character can contain stats of user and guardian of treasure(creature).


EXAMPLE GAMEPLAY : 

Welcome to the Dungeon Treasure Hunt Game.
Please enter your name
> Malik Saad Ali
Welcome, Malik Saad Ali.You adventure begins here.
Press (S) or (s) to start playing.
Press (E) or (e) to exit.
> s
You are at starting point.
> look
There is a dagger.
> pickup
Picked.
> move right
You are in room on the ground floor.
> look
There is a pistol.
> pickup
Picked.
> move up
You are in the hall on the 1st floor.
There is a balcony on right side.
And a room on left side.
> look
There is nothing.
> pickup
Nothing to pickup.
> move right
You are in balcony on the 1st floor.
> look
There is a rose with big and fatal thorns.
> pickup
Back Pack is full.
> drop
What do you want to drop.
> drop dagger
Dropped successfully.
> pickup
Picked.
> move left
You are in the hall on the 1st floor.
> move left
You are in room on the 1st floor.
> look
There is a Akm(AK-47) gun.
> pickup
Back Pack is full.
> inventory
Inventory : 
Item Name       Item Quantity
Dagger          0
Pistol          1
Thorny Rose     1
Ak-47           0
> move up
You are in balcony on the top floor of the house.
What a beautiful view from here.
> wrong command
Invalid Command!!.Enter another command.
> look
There is a guardian proteting treasure.
> attack
A battle has begun.
Malik Saad Ali fighting with Guardian.
Malik Saad Ali hits Guardian with 12 damage.
Guardian's health is now 88.
Guardian hits Malik Saad Ali with 12 damage.
Malik Saad Ali's health is now 88.
Malik Saad Ali hits Guardian with 15 damage.
Guardian's health is now 73.
Guardian hits Malik Saad Ali with 16 damage.
Malik Saad Ali's health is now 72.
Malik Saad Ali hits Guardian with 18 damage.
Guardian's health is now 55.
Guardian hits Malik Saad Ali with 12 damage.
Malik Saad Ali's health is now 60.
Malik Saad Ali hits Guardian with 12 damage.
Guardian's health is now 43.
Guardian hits Malik Saad Ali with 10 damage.
Malik Saad Ali's health is now 50.
Malik Saad Ali hits Guardian with 10 damage.
Guardian's health is now 33.
Guardian hits Malik Saad Ali with 10 damage.
Malik Saad Ali's health is now 40.
Malik Saad Ali hits Guardian with 13 damage.
Guardian's health is now 20.
Guardian hits Malik Saad Ali with 15 damage.
Malik Saad Ali's health is now 25.
Malik Saad Ali hits Guardian with 19 damage.
Guardian's health is now 1.
Guardian hits Malik Saad Ali with 15 damage.
Malik Saad Ali's health is now 10.
Malik Saad Ali hits Guardian with 13 damage.
Guardian's health is now -12.
Congratulations.Guardian has been defeated.You win.
You have got the treasure.
You have became rich and powerful.
Game ends here.


HOW TO COMPILE : 

There are two steps to compile and run.
1. Enter make to compile the code.
2. Enter .\run to run the code. 


DEVELOPER : MALIK SAAD ALI
STUDENT NO : 22050141023