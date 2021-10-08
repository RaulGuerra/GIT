#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//function prototypes
int checkSums(int square[3][3]);
int generateRandSquare();
void printSquare(int square[3][3]);

int main(void)
{
	int foundSquare = 0; //flag to end loop
	int count = 0; //to count the loops

    int validSquare[3][3] = {
	{4, 9, 2},
	{3, 5, 7},
	{8, 1, 6}};
	
	int invalidSquare[3][3] = {
	{3, 9, 2},
	{4, 5, 7},
	{9, 1, 6}};

	//testing valid square:
	printSquare(validSquare);

	if (checkSums(validSquare))
		printf("This square is a Lo Shu Magic Square\n\n");
	else
		printf("This square is invalid\n\n");

	printSquare(invalidSquare);
	if (checkSums(invalidSquare))
		printf("This square is a Lo Shu Magic Square\n\n");
	else
		printf("This square is invalid\n\n");
	


	do
	{
		foundSquare = generateRandSquare();
		count++;
		printf("%d\n", count);
	} while (foundSquare != 1);
	
};


int checkSums(int square[3][3])
{
	int sums[8] = {0,0,0,0,0,0,0,0}; //to store sums
	
	int j = 2; //to traverse diag2 
	for (int i = 0; i < 3; i++)
	{
		sums[0] += square[i][i]; //check first diagonal
		sums[1] += square[i][j]; //check second diagonal
		sums[2] += square[0][i];  //check row1
		sums[3] += square[1][i];	//check row2
		sums[4] += square[2][i];	//check row3
		sums[5] += square[i][0];	//check col1
		sums[6] += square[i][1];	//check col2
		sums[7] += square[i][2];	//check col3

		j--;
	}
		
	for (int k = 0; k < 8; k++)
	{
		if (sums[k] != 15)
			return 0; //return 0 if invalid
	}

	return 1; //return 1 if valid
}


int generateRandSquare()
{
	int newSquare[3][3];
	
	int arr[9] = {1,2,3,4,5,6,7,8,9}; //list to be shuffled randomly
	int k = 0; //index to traverse arr

	time_t t; //to populate seed

	srand((unsigned) time(&t));

	//shuffling list
	for (int i = 0; i < 9; i++)
	{
		int j = rand() % (9-i) + i;
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;

	}

	//populating square
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			newSquare[i][j] = arr[k];
			k++;
		}
	}	
		
	
	if (checkSums(newSquare) == 1) //if valid square
	{
		printSquare(newSquare); //print the square
		return 1; //return true
	}
	

	return 0; //else return false

}

void printSquare(int square[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		printf("[   %d   %d   %d   ]\n", square[i][0], square[i][1], square[i][2]);
	
	}	


}