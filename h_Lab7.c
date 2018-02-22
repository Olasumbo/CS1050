#include<stdlib.h>
#include<time.h>
#include<stdio.h>
#define MAX 100
 
int errorCheck (int x);
void initialize_2Darray(int array[][MAX], int size);
void print_2Darray( int array[][MAX] , int size);
int check_index( int index, int size);
int find_columnmax( int array[][MAX], int c, int size);
float calculate_columnaverage( int array[][MAX], int c, int size ); 
int countZero( int array[][MAX], int size);
int length ( char s[]);

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
        printf(" Enter the column 1 - %d;\n", size );
	scanf("%d", &index);
	while( check_index(index,size) == 0)
	{
		printf("Enter the column 1 - %d\n", size );
	        scanf("%d", &index);
	}

          printf(" The largest number present in the colunm %d is %d \n ", index, find_columnmax( Array, index , size));
          printf(" The average of the number in the colunm is %.2f \n ", calculate_columnaverage( Array, index , size));
	  printf(" The number of Zero's in the 2-D array is %d\n", countZero( Array, size));

	  char s[MAX];
	  printf(" Enter a string:\n");
	  scanf("%s", s);
	  printf(" The length of the string %s is %d\n", s, length(s));
	  
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
{

	if( index < 1 || index > size )
		return 0;
        else 
		return 1;
}

int find_columnmax( int array[][MAX], int c, int size)
{
	int i;
	int max = 0;
  for( i=0; i < size; i++)
  {
  	if (array[i][c] > max)
	{
		max = array[i][c];	
	}
  
  }
  return max;
}

float calculate_columnaverage( int array[][MAX], int c, int size ) 
{ 
    int i;
    float average = 0;
    float total;
    for( i= 0; i < size; i++)
    {
       total += array[i][c];
    }
      average = (total/2) ;

      return average;
}

int countZero( int array[][MAX], int size)
{
	int counter = 0;
	int i, j;
	for ( i=0; i < size; i++)
	{
            for( j=0; j< size; j++)
	    {
	    	if (array[i][j] == 0)
		counter++;
	    }
	}
  return counter;
}
//void addN(int array[][MAX], int size)
//{


//}I couldn't figure it pout

int length ( char s[])
{
	int length = 0;
	while( s[length] !='\0' )
	{
		length++;
        }
		return length;
}
//void copy ( char s[], char s1[])
//{
	//int i;
	 //for( i=0; i< s[]; i++)
		 //s[i] = s1[i] ;


		 	
//} I Ran out time..
