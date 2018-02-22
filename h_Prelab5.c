#include<stdlib.h>
#include<time.h>
#include<stdio.h>

int errorCheck (int x);
void DisplayMenu ();
int generateNumber();
int Cube (int x);
int division (int x, int y);

int main (void)

{	int input;
        DisplayMenu();
	scanf("%d", &input);
	while (errorCheck (input) == 0)
	{	
		DisplayMenu();
		scanf("%d", &input);
	}

	srand(time(NULL));
        int random = generateNumber();
	int z = Cube(random);
	int y = division( random);

	return 0;
}

void DisplayMenu()
{	
	printf("Select a mathematical operation\n");
	printf(" 1 for Cube\n");
	printf(" 2 for Division\n");
	printf(" Enter your choice:\n");
}
int errorCheck(int x )
{    
	if ( x == 1 ||x == 2)
		return 1;
	else
		return 0;
}
int generateNumber()
{
	return(rand() % 10 );
}
int Cube( int x)
{
	return( x*x*x );
}
int division(int x , int y)
{
	if( x == 0||y == 0)
		return 0;
	if(x > y)
	        return (float)x/y;
	else
	        return(float)y/x;
   return 0;
}


