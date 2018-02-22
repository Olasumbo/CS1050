#include<stdio.h>

int checkError(int x);
int checkEven(int even);

int main (void)

{
	int input;
	printf(" Enter a number:\n");
	scanf("%d", &input);
	int check = checkError(input);
	//int Even = checkEven (input);

  while(check == 0)
      {
	printf("Please enter a positive number:\n ");
	scanf("%d", &input);
	check = checkError(input);
      }  
}
	
int checkError( int x)
{

	if(x < 0)
	     return 0;
	if(x >= 0)

     {
	printf("It's positive\n");
	return 1;
     }
}

/*int checkEven( int even)
{
	if ( input % 2 == 0)
		return 0;
	
	else
		return 1;

}
*/



