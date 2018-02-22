#include <stdio.h> 
int main(void)
{
	int x,y ;
	printf("Enter the First number");
	scanf("%d",&x) ;

	printf("\n Enter the second number:");
	scanf("%d", &y);

	if (x>y)
	{
	printf("%d is the largest number\n", x);
	}
	else
	{
	printf("%d is the largest number\n", y);
	}
	printf("\n");

	return 0;
}


