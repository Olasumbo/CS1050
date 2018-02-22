#include<stdlib.h>
#include<time.h>
#include<stdio.h>
 
int errorCheck (int x);
void initialize_array(int array[], int size);
void print_array( int array[] , int size);
int max ( int array[] , int size);
int min ( int array[] , int size);
float average ( int array[], int size);
int count_number ( int array[], int size, int x);
int common_number ( int array[], int diarray[], int size);


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
	print_array( Array1, size );
	printf(" The maximum number is present at the index location %d in the array \n", max( Array1,size));
	printf(" The minimum number is present at the index location %d in the array \n", min( Array1, size) );	
	printf(" average numbers in the first array is %.2f \n",average( Array1, size));

	initialize_array( Array2, size );
        print_array( Array2 , size);   
	printf(" The maximum number is present at the index location %d in the array \n", max( Array2,size));
	printf(" The minimum number is present at the index location %d in the array \n", min( Array2, size));	
        printf(" average numbers in the first array is %.2f \n",average( Array2, size));

        int search;
	printf(" What number will you like to find? \n");
	scanf("%d", &search);
       printf("The count of number %d in the first array is %d \n", search, count_number( Array1, size, search ));
       printf("The count of number %d in the second array is %d\n", search, count_number( Array2, size, search ));

       printf("The  number of common numbers in the two arrays are %d \n", common_number( Array1, Array2, size));

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
int max ( int array[] , int size)
{
	int i;
	int index;
	int max = 0;
  for( i=0; i < size; i++)
  {
  	if (array[i] > max)
	{
		max = array[i];	
		index = i;
	}
  }

  return index;
}
int min ( int array[] , int size)
{
	int i;
	int index;
	int min = 10;
   for( i=0; i < size; i++)
  {
  	if (array[i] <  min)
	{
		min = array[i];	
		index = i;
	}
  }
 return index;
}

float average ( int array[], int size)
{
	int i;
	float average =0;
	   for( i=0; i < size; i++)
  	{
		average += array[i];
	}

	return average/(float)size;
}

int count_number ( int array[], int size, int x)
{
	int counter = 0;
	int i;
	for( i = 0; i < size; i++)
	{	
		if ( array[i] == x )
		 {  
			 ++counter;
		 }
	}
	return counter;

}
int common_number ( int array[], int diarray[], int size)
{
	int counter = 0;
	int i;
	
	for ( i =0; i< size; i++)
 	   if( array[i] == diarray[i])
		++counter;

	return counter;
}

