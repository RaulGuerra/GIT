
//Written by Raul Guerra Umana
//PROGRAM OUTLINE:

//ask for desired tax and tip percentage
//validate user input: only positive numeric values > 0 accepted
//generate random seed and create random number generator
//create array of 4 doubles, to store meal prices
//create function to populate array
//call random number genetor so it selects random meal.
//display results

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int validateInput(char str[]);

void main(void)
{
time_t t; //to populate seed
int invalid = 1; //flag to check validity of string. Assume it's invalid.
char meal[9];
double mealPrice;
double tax;
double subtotal;
double tip;
double total;





  char str[10]; //to hold tax input

  do
  {
     printf("Please input the tax to be charged (maximum input is 10 characters, enter as percentage. I.E. If you want 9.5%% tax, just type 9.5): ");

    fflush(stdout);
    scanf("%s", str);

    if (strlen(str) > 10)
        {
            printf("\nToo many characters. Keep it at 10 characters please!\n");
            continue;
        }
    

    invalid = validateInput(str); //validating str

    if (invalid == 1)
        printf("You wrote: %s, which is invalid. Only numbers 0-9 are allowed, and only 1 dot. Try again.\n", str);

  } while (invalid == 1);


    tax = atof(str); //saving tax
    printf("You entered: %f %% tax.\n", tax);

    tax = tax/100;


    char str1[10]; //to hold tip input
    do
  {
     printf("Please input the tip to be charged (maximum input is 10 characters, enter as percentage. I.E. If you want 11.3%% tip, just type 11.3): ");

    fflush(stdout);
    scanf("%s", str1);

    if (strlen(str1) > 10)
        {
            printf("\nToo many characters. Keep it at 10 characters please!\n");
            continue;
        }

    invalid = validateInput(str1); //validating str

    if (invalid == 1)
        printf("You wrote: %s, which is invalid. Only numbers 0-9 are allowed, and only 1 dot. Try again.\n", str1);

  } while (invalid == 1);


    tip = atof(str1);
    printf("You entered: %f %% tip.\n", tip);
    tip = tip/100;


    srand((unsigned) time(&t));


    int randNum = rand() % 4;

    switch (randNum)
    {
    case 0: //salad
        strcpy(meal, "Salad");
        mealPrice = 9.95;
        break;
    case 1: //soup
        strcpy(meal, "Soup");
        mealPrice = 4.55;
        break;
    case 2: //sandwich
        strcpy(meal, "Sandwich");
        mealPrice = 13.25;
        break;
    case 3: //Pizza
        strcpy(meal, "Pizza");
        mealPrice = 22.35;
        break;
    default:
        break;
    }

    subtotal = ((tax+1)*mealPrice);
    total = subtotal*(tip+1);

    printf("Meal: %s\n", meal);
    printf("Meal Price: $%.2f\n", mealPrice);
    printf("Tax Amount: $%.2f  \n", (tax*mealPrice));
    printf("Subtotal: $%.2f  \n", subtotal);
    printf("Tip Amount: $%.2f (Tips are calculated after tax)\n", (tip*subtotal) );
    printf("Total: $%.2f\n\n", total);
    printf("Thank you for visiting! Come again!");


  

    
};


int validateInput(char str[])
{
    int strLength = strlen(str);
    int dotCount = 0;


    for (int i = 0; i < strLength; i++)
    {
        if (dotCount > 1)
            return 1; //if there are more than 1 dots, invalid input. return true.


        switch (str[i]) //check for every valid char
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
        case '.':
            dotCount++;
            break;
        default:
            return 1; //if character doesn't match any case, input is invalid. Return true.
            break;
        }
    }

    return 0; //if str only contains valid chars and only has 1 dot at most, valid input. return false.

}





















