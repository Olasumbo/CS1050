#include<stdlib.h>
#include<time.h>
#include<stdio.h>
#define SIZE 

int errorCheck (int x);
void DisplayMenu ();
int generateNumber();
int checkguess( int guess, int answer);
void printResult( int result, int answer);

int main (void)

{  int choice;
   int counter;
   int correctcounter;
	do	
     {
              int input;
              DisplayMenu();
	      scanf("%d", &input);
	 while (errorCheck (input) == 0)
	{	
		printf(" Enter either a 0 or 1\n");
		scanf("%d", &input);
	}

	srand(time(NULL));
        int answer  = generateNumber();
        int result = checkguess( input, answer);
	printResult( result, answer);
        
	if( checkguess( input, answer) == 1)
		correctcounter++;

      printf(" Do you want to play again. Type 1 for yes and 0 for No\n");
      scanf("%d", &choice);	
        while( choice < 0 || choice > 1)
	{
	    printf( "invalid choice. Type 0 or 1\n");
	    scanf("%d", &choice);	    	
	}
	counter++;

     } while(choice == 1);

      printf(" You played the game %d times and got the correct guess%d times\n", counter, correctcounter);
      float Accuracy = (( float) counter/(float)correctcounter) * 100 ;
      printf(" your accuracy is %.2f percent " , Accuracy);
      printf(" Thank you for playing\n");

	return 0;
}

void DisplayMenu()
{	
	printf(" Please make a guess\n");
	printf(" 0 for heads\n");
	printf(" 1 for tails\n");
	printf(" Enter your choice:\n");
}
int errorCheck(int x )
{    
	if ( x == 0 || x == 1)
		return 1;
	else
		return 0;
}
int generateNumber()
{
	return(rand() % 2);
}
int checkguess( int guess, int answer)
{
	if ( guess  == answer)
		return 1;
	else
		return 0;
}
void printResult( int result, int answer)
{
 	printf(" you gussed was a");

	switch( result)
	{
	
		case 0:    //wrong

		   if ( answer == 0)
			printf(" TAILS");
		   if ( answer == 1)
			printf( "HEADS");
		printf( " and it did not match\n");
                
		break;

		case 1: //right
		   if ( answer == 0)
			printf(" HEADS ");
		   if ( answer == 1)
			printf( " TAILS ");
		printf( " Congrat!!! it match\n");

		break;
	}
}

///BONUS
//printf("********* BONUS*********")
 







          	

