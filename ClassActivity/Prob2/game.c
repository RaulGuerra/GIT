//Written by Raul Guerra Umana
//PROGRAM OUTLINE:


//create random seed to populate random number generator. Create global maxRange variable (set to 10 at start)
//design menu and functions that will be responisble for the options.
//Option 1: void option1(int max). Holds number generator, asks for input, calls for validation, checks for answer.
//Option 2: ask user for input, validate input, make changes to maxRange, store maxRange in file.
//Option 3: Thank player, end game printf("\n");

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

int validateNumber(char str[]);
int validateMenu(char c);

void opt1(int max);
void opt2();
void opt3();

int static MAX_NUM = 10;
int quitFlag = 1; //0 = false, 1 = true;



void main(void)
{
    int invalidMenu; //flag to check if menu input is valid
    FILE *fp;
    char buff[10];
    const char *fileName = "SavedMax.txt";

    printf("Reading previous saved game data... \n");


    if(access(fileName, F_OK) == 0) //if file exists
    {
        fp = fopen(fileName, "r"); //file should only have an int stored.
        fscanf(fp, "%s", buff); //buff now has an int.

        printf("Stored number is %s\n", buff); //testing buff

        if (validateNumber(buff) == 1) //checking for consistency in game file.
        {
            if (strlen(buff) > 0 && strlen(buff) < 3) //checking if input is correct.
                MAX_NUM = atoi(buff);  //put int into MAX_NUM
        
        }
        else
            printf("Corrupted game file. Max number set to default. \n");
        
    }
    else //file doesn't exist
    {
        printf("Creating new save file. \n");
        fp = fopen(fileName, "w+");
    }

    


    do //main menu
    {
        
        printf("WELCOME TO THE GAME!!!\n");
        printf("These are the options:\n\n");
        printf("1. Play\n");
        printf("2. Change max number\n");
        printf("3. Quit\n");

        
        char c; //to hold input

        do
        {
            printf("What would you like to do? ");

            fflush(stdout);
            c = getchar();
            

            invalidMenu = validateMenu(c); //validating char

            if (invalidMenu == 1)
                printf("Bad input. Only 1, 2, or 3 is allowed.");

        } while (invalidMenu == 1);







    } while (quitFlag);
    

    //Before closing game, save any MAX_NUM in file.
    fp = freopen(fileName, "w+", stdout); //reopening file.
    printf("%d", MAX_NUM); //rewriting file with current max number.
    fclose(stdout); 




}



int validateNumber(char str[])
{
    int strLength = strlen(str);
    

    for (int i = 0; i < strLength; i++)
    {
        char c = str[i];

        switch (c) //check for every valid char
        {
        case '0':
            break;
        case '1':
            break;
        case '2':
            break;
        case '3':
            break;
        case '4':
            break;
        case '5':
            break;
        case '6':
            break;
        case '7':
            break;
        case '8':
            break;
        case '9':
            break;
        case 'q':
            return 2; //if player pressed q, quit game.
            break;
        default:
            return 0; //if character doesn't match any case, input is invalid. Return false.
            break;
        }
    }

    return 1; //if str only contains valid chars, valid input. return true.

}


int validateMenu(char c)
{

        switch (c) //check for valid char
        {
        case '1':
            opt1(MAX_NUM);
            break;
        case '2':
            opt2();
            break;
        case '3':
            opt3();
            break;
        default:
            return 1; //if character doesn't match any case, input is invalid. Return true.
            break;
        }

    return 0; //if str only contains valid chars and only has 1 dot at most, valid input. return false.

};


void opt1(int max)
{
    time_t t; //to populate seed
    int flag = 1; //flag to signal to terminate function
    int validGuess = 1; //flag to check input

    srand((unsigned) time(&t));

    int randNum = (rand() % max) + 1; //generating random number

    do
    {

        printf("Guess a number between 1 and %d: ", max);

        char str[10]; //to store input

        scanf("%s", str); //asking for input

        validGuess = validateNumber(str); //validating input

        if (validGuess == 2) //quit game if player typed q or Q in input
        {
            printf("Returning to main menu now.\n\n\n");
            return;
        }
        else if (validGuess == 1) //valid input
        {
            int guess = atoi(str); //converting string to int

            if (guess == randNum) //checking if guess is correct
            {
                printf("CONGRATS! That's the right number! Returning to main menu.\n\n\n");
                flag = 0;
            }
            else
            {
                if (guess < randNum)
                    printf("Try guessing HIGHER number or press 'q' to quit.\n\n");
                else
                    printf("Try guessing LOWER number or press 'q' to quit.\n\n");
                
                
            }
            
        }
        else // validGuess == 0, invalid input
        {
            printf("Invalid input. Only positive numbers are allowed. Press 'q' to quit. Try again.\n");
        }
        
        

       
    } while (flag);
    
    return;

};



void opt2()
{

    int validInput = 1; //flag to check input
    int flag = 1; //flag to signal to terminate function

    printf("The current max number is %d. You can change it all the way up to 50. Enter the new max number or press 'q' to return to main menu: ", MAX_NUM);

    do
    {
        char str[10]; //to store input
        scanf("%s", str); //asking for input

            validInput = validateNumber(str); //validating guess

            if (validInput == 2) //quit game if player typed q or Q in input
            {
                printf("Returning to main menu now.\n\n\n");
                return;
            }
            else if (validInput == 1) //valid input
            {
                int newMax = atoi(str); //converting string to int
                
                if (newMax > 50 || newMax < 2) //invalid newMax
                {
                    printf("Invalid input. Max number has to be between 2 and 50. Press 'q' to quit or you can try again.\n");
                }
                else //valid newMax
                {
                    MAX_NUM = newMax;
                    flag = 0; //exit loop
                }


                
            }
            else // validGuess == 0, invalid input
            {
                printf("Invalid input. Only positive numbers are allowed. Press 'q' to quit or you can try again.\n");
            }   

    } while (flag);
    




};



void opt3()
{
    printf("\n\nTHANKS FOR PLAYING!");
    quitFlag = 0;
};