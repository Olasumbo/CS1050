#include<stdio.h>

int main( void)
{
	int num1;
	int num2;
	int sum;
	int product;

	printf("Enter your first interger\n");
	scanf("%d", &num1);
	if (num1 >= 0)
		printf("num1")
	else
	{
		if(num1 < 0)
		printf("Error- Enter a positive interger");
	}

	 printf("Enter a second Interger \n");
	 scanf("%d" , num2);
	 if (num2 >= 0);
	 	printf(" num2")
	 else
	{
		if (num2 <0)
		printf("Error - Enter a positive interger");
	}

	sum = num1 + num2;
	printf("The sum of" num1 " and" num2 "is " sum);
	product = num1 * num2;
	printf("The product of" num1 " and " num2 " is" product); 
}
