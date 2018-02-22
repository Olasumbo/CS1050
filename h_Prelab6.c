#include<stdlib.h>
#include<time.h>
#include<stdio.h>
 
int errorCheck (int x);
void initialize_array(int array[], int size);
void print_array( int array[] , int size);

int main (void)
{
	 int size = 0;
	 	 while (errorCheck (size) == 0)
	{	
		printf(" Enter a number between 1 and 100\n");
		scanf("%d", &size);
	}
	srand(time(NULL));

	int Array1[size];
	int Array2[size];
	initialize_array( Array1, size );
	initialize_array( Array2, size );
	
	print_array( Array1, size );
	print_array( Array2, size );

	return 0;
}
	
int errorCheck(int x)
{    
	if ( x  <= 0 ||  x  > 100)
		return 0;
	else
		return 1;
}
void initialize_array(int array[], int size)
{
	int i;
	for(i =0; i < size; i++)
		array[i] = (rand() % 10);
}
void print_array( int array[], int size)
{
	int i;
	for(i =0; i < size; i++)
		printf("%d ", array[i]);

	printf("\n");
}


