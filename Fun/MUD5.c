/*
 This program is called MUD.c
 Created by CoderDojo
 Last Updated: 20 April 16
 */

// Libraries
#include <stdio.h>
#include <stdlib.h>

// Global Variables
int xGridSize = -1;
int yGridSize = -1;
int xCoord = -1;
int yCoord = -1;

int LoadGame (int);
int Play();
int Fight(int);

// Main Function
int main()
{
    //Local Variables
    int gameMode = -1; //declaration
    
    //Print Welcome
    printf("Welcome...Would you like to play a game? (use 0 - 9))\n");
    
    //Select Game mode
    while (gameMode != 0)
    {
        //Input Game to play
        scanf("%d",&gameMode);
        if(gameMode != 0){
            
            printf("There is only 1 game right now... Please type 0 to play the game...\n\n");
            
        }
    }
    
    //Load Game
    LoadGame(gameMode);
    
    //Begin Playing
    Play();
    
    return 0;
    
}
/***********************************************************************************************/
// Supporting Functions
int LoadGame(int gameMode)
{
    if (gameMode == 0) //operator
    {
        //then do this
        /* Visual Game Grid
         5 |-----|
         4 |-----|
         3 |-----|
         2 |-X---|
         1 |o----|
         12345
         
         o = start
         5 up/down
         5 left/right
         */
        xGridSize = 5; // variable to set Game Grid X axis Size
        yGridSize = 5; // variable to set Game Grid Y axis Size
        
        xCoord = 1; // variable for player position on X axis
        yCoord = 1; // variable for player position on Y axis
        
        printf("Game Loaded successfully... Play On!!\n\n");
        printf("-------------------------------------\n\n");
        
    }
    // DELETE
    /*	else if(condition == b )
     {
     //then do this
     
     
     }
     */
    else //anything else, including potential errors
    {
        
        //then do this
        
    }
    
    return 0;
    
}
/***********************************************************************************************/
// Player is pizza, encounters ninjas and wizards to gain points... points = levels, different levels mean different points needed to progress
int Play()
{
    int xBossCoord = 2;
    int yBossCoord = 2;
    
    //Local Variables
    /************************************************************************/
    // DELETE
    //	int pizza = 0;   // player
    //	int ninja = 0;   // bad guy
    //	int wizards = 0; // bad guy
    /************************************************************************/
    char direction;  		// player input for direction to go next
    int escape = 0;  		//escape character
    int randEncounter = -1;	//Chance that an Encounter with a Ninja Happens
    
    printf("Welcome to Pizza Ninja Wizards.... you can move north or east from your present location...\n");
    // DELETE
    //	printf("Welcome to Battle Cats.... you can move north or east from your present location...\n");
    
    while(escape == 0){
        
        if ((xCoord > 0 && xCoord < 6) && (yCoord > 0 && yCoord < 6)){ // user is between bottom and top as well as left and right )
            
            printf("You are at location %d,%d.\n", xCoord, yCoord);
            printf("Where do you want to go? (W=North,A=West,S=South,D=East, Q to Quit)\n");
            scanf("%s",&direction);
            
            switch (direction){
                case 'W' : case 'w' : yCoord += 1 ; break;
                case 'A' : case 'a' : xCoord -= 1; break;
                case 'S' : case 's' : yCoord -= 1 ; break;
                case 'D' : case 'd' : xCoord += 1 ; break;
                case 'Q' : case 'q' : escape = 1 ; break;
                default : printf("I do not understand what you are talking about\n\n") ; break;
                    
            }
            
            // DELETE
            //		printf("Where do you want to go? (W=North,A=West,S=South,D=East)\n");
            //		scanf("%c",&direction);
            
        }
        
        else if (xCoord <= 0 || xCoord >= 6 || yCoord <= 0 || yCoord >= 6) // player has moved out of bounds
        {
            
            //bring the player back in bounds, present feedback to the player that they are at the edge of the map
            
            switch(xCoord){
                case 0 : xCoord = 1 ; printf("You are too far west. You can not go further that way.\n") ; break;
                case 6 : xCoord = 5 ; printf("You are too far east. You can not go further that way.\n") ; break;
            }
            
            switch(yCoord){
                case 0 : yCoord = 1 ; printf("You are too far south. You can not go further that way.\n") ; break;
                case 6 : yCoord = 5 ; printf("You are too far north. You can not go further that way.\n") ; break;
            }
            
        }
        
        
        // New code to create monster encounters
        randEncounter = rand() % 11;
        ///DEBUGGING FUNTION
        // randEncounter = 8;
        
        if (randEncounter > 7){	// 1 in 5 (20%) chance moving will find an Encounter
            
            Fight(0);
            
        }
        else if (xCoord == xBossCoord && yCoord == yBossCoord)
        {
            printf("YOU ENCOUNTERED THE SUPER NINJA WHO IS GOING TO KILL YOU.\n");
            Fight(1);
        }
        else {
            
            // do nothing for now
            //eventually add in a "Counter" mechanism so if you keep not finding encounters, your chances to find one increase
            
        }
        
    }
    
    printf("\nThank you for Playing... Have a Great Day!");
    return 0;
    
}

/***********************************************************************************************/
//Fighting mechanics
int Fight(int type)
{
    // type = 0 means ninja fight
    // type = 1 means boss fight
    //Local Variables to add "flavor" to the game
    char *topping = "Junk";			//Topping per encounter
    int randTopping;				//Random variable to determine Topping
    int stage1;						//First part of narrative
    int stage2;						//Second part of narrative
    int ninjaAction;				//What the monster does
    int playerAction = 0;			//What the player does
    int damage = 0;					//Amount of damamge done
    int potionHealth = 25; // Potion restores 25 health.
    int potionNum = 3;      // Number of potions available.
    //char playerActionInput = NULL;
    
    //Create Player ... Pizza
    int pizzaHealth = 50;
    
    //Create Ninjas
    int ninjaHealth = 50;
    if(type == 1) // SUPER NINJA!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    {
        ninjaHealth = 75;
    }
    
    int ninjaXP = 50;
    
    //Randomize the narrative each encounter
    randTopping = rand() % 6;
    switch(randTopping){
        case 0 : topping = "Pepperoni" ; break;
        case 1 : topping = "Anchovy" ; break;
        case 2 : topping = "Pineapple" ; break;
        case 3 : topping = "Mushroom" ; break;
        case 4 : topping = "Veggie" ; break;
        case 5 : topping = "Meat Lovers" ; break;
    }
    stage1 = rand() % 4; // 4 different possibilities for first narrative
    stage2 = rand() % 2; // 2 different possibilities for second narrative
    if( type == 1 )
    {
        stage2 = 0;
    }
    
    //First narrative part of the Random Encounter
    switch(stage1){
        case 0 : printf("A ninja drops out of the trees above.\n"); break;
        case 1 : printf("A ninja steps out from behind a nearby blade of grass.\n"); break;
        case 2 : printf("A plume of smoke appears and a ninja now stands in front of you.\n"); break;
        case 3 : printf("A ninja taps you on the shoulder from behind.\n"); break;
    }
    
    //After first part of narrative, set up second part
    printf("He sniffs at you, and ");
    
    //Second narrative part of the Random Encounter
    switch(stage2){
        case 0 : ninjaAction = 0; printf("decides he wants pizza so he gets ready to slice you up.\n\n"); break;
        case 1 : ninjaAction = 1; printf("runs away due to your %s topping.\n\n", topping); break;
    }
    
    // What the Ninja Does
    if (ninjaAction == 0){
        
        while(ninjaHealth > 0){
            
            while(playerAction != 1
                  && playerAction != 2
                  && playerAction != 3
                  && playerAction != 4){
                
                printf("What do you do?\n");
                printf("(1) Throw %s toppings at him\n", topping);
                printf("(2) Melee him\n");
                if( type == 0 )
                {
                    printf("(3) Run Away\n");
                }
                printf("(4) Use Potion! Restores %d health", potionHealth);
                
                scanf("%d", &playerAction);
                //				playerAction = (int)playerAction;
                //this keyboard is BOSS!!
                //				playerAction = (int) playerActionInput;
                if(type == 1 && playerAction == 3)
                {
                    // Overriding user selection if they still attempted 3.
                    playerAction = 0;
                }
                
                if ((playerAction != 1 && playerAction != 2 && playerAction != 3 && playerAction != 4 && playerAction != 'q' && playerAction != 'Q' && potionNum != 0)){ //|| (/*player presses any other key*/)){
                    
                    printf("Invalid input.\n\n");
                    
                }
                
                //				if player presses any character other than 1, 2, 3, q, then provide feedback that keys not allowed
                //				if player presses q then quit
                
                else {
                    
                    //continue
                    
                }
                
            }
            
            // Create Damage player does to ninja if option 2 selected
            damage = rand() % 11;	// 0-10 Damage
            
            switch(playerAction){
                case 1 : ninjaHealth -= 5; printf("You throw %s toppings at him. (You deal 5 damage)\n", topping); break;
                case 2 : ninjaHealth -= damage; printf("You Melee him. (You deal %d damage)\n", damage); break;
                case 3 : ninjaHealth = -100; printf("You decide the ninja looks too hungry and decide to run away.\n"); break;
                case 4 : pizzaHealth += potionHealth;
                    printf("You used a potion! Your health is now %d !\n", pizzaHealth);
                    printf("You have %d potions left.", potionNum);
                    break;
            }
            
            //Ninja is still Alive
            if (ninjaHealth > 0)
            {
                printf("The ninja has %d health left.\n", ninjaHealth);
                
                //Ninja Attacks player
                damage = rand() % 11;	// 0-10 Damage
                if( type == 1 )
                {
                    damage = rand() % 20;
                }
                pizzaHealth -= damage;
                printf("The Ninja does %d damage to you.\n", damage);
                printf("You have %d health left.\n\n", pizzaHealth);
                
                //			}
                
                //Player is Dead
                if (pizzaHealth <= 0){
                    
                    printf("You are dead!\n\n");
                    //Restart Game
                    main();
                    
                }
                
            }
            
            //Ninja is Dead
            else if (ninjaHealth <= 0 && ninjaHealth > -100){
                
                printf("The ninja is dead! You gain %d XP and replenish your health to full.\n\n", ninjaXP);
                
            }
            
            //Reset Player Action to have options on next round
            playerAction = 0;
            
        }
        
    }
    
    else if (ninjaAction == 1){
        printf("What a chicken.. ah well...\n\n");
    }
    else {
        printf("GAME ERROR... EXITING GAME");
        return 0;
    }
    return 0;
}

/***********************************************************************************************/
/* //The Final Battle...to be finished 20 April
 int FinalBattle()
 {
 
	//Create Boss ... Wizard
	int wizardHealth = 40;
	int wizardXP = 100;
	
	printf("The ground shakes and a wizard materializes from nowhere.\n\n");
	
	
 }
 */
