#include<stdlib.h>
#include<time.h>
#include<stdio.h>
#define MAX 100
 
int errorCheck (int x);
void initialize_2Darray(int array[][MAX], int size);
void print_2Darray( int array[][MAX] , int size);
int check_index( int index, int size);

int main (void)
{
	 int size = 0;
	 	 while (errorCheck (size) == 0)
	{	
		printf(" Enter a number between 1 and 100\n");
		scanf("%d", &size);
	}
	srand(time(NULL));

	int Array[size][MAX];
	initialize_2Darray( Array, size );
        print_2Darray( Array, size );

	int index;
	printf(" Enter the column %d - %d\n", check_index(index,size), size);
	scanf("%d", &index);
	//int check = check_index(index, size);
	//while(check == 0)
	//{
		//printf("Please enter a vlue between 1 and %d\n", size);
		//scanf("%d", &check);
		//check = check_index(index, size);
//	}

        return 0;

}
	
int errorCheck(int x)
{    
	if ( x  <= 0 ||  x  > 100)
		return 0;
	else
		return 1;
}
void initialize_2Darray(int array[][MAX], int size)
{
	int i;
	int j;
	for(i =0 ; i < size; i++)
	{   
	for(j = 0; j < size; j++)
	{
	 array[i][j] = (rand() % 10);
	}
	}
}
void print_2Darray( int array[][MAX], int size)
{
	int i;
	int j;
	for(i =0; i < size; i++)
	{
	for ( j=0; j< size; j++)
	{
        	printf("%d ", array[i][j]);
	}
	printf("\n");
	}
}
int check_index( int index, int size)
//do
{
	if ( index > 1 && index < size )
		return 0;
        else 
		return 1;
}
//while ( index == 0)

