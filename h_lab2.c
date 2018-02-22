#include<stdio.h>

int main( void)
{
	int num1;
	int num2;
	int sum;
	int subtract;
	float division;
	int product;
	int remainder1;
	int remainder2;

	printf("Enter your first number\n");
	scanf("%d", &num1);
	if (num1 >= 0)
		printf(" num1 ");
	else
	{
		if(num1 < 0)
		printf("Error- Enter a non-negative number\n");
		scanf("%d", &num1);
	}

	 printf("Enter your second numberr \n");
	 scanf("%d" ,&num2);

	 if (num2 >= 0)
	 	printf(" num2");
	 else
	{
		if (num2 < 0)
		printf("Error - Enter a non-negative number\n");
		scanf("%d", &num2);
	}

	sum = num1 + num2;
	printf("The sum of %d and %d equals %d\n", num1,num2,sum );

	subtract = num1 - num2;
	printf("The difference of %d and %d equals %d\n", num1,num2,subtract ); 

	product = num1 * num2;
	printf("The product of %d and %d equals %d\n", num1,num2,product); 

	division=(float) num1/ num2;
	printf("%d divided by %d equals %.2f\n", num1,num2,division ); 
	
	if ( num1 < num2)
	{
		printf("%d is the smaller number\n", num1);
	}
	
	if ( num2 > num1)
	{
		printf("%d is the larger number\n", num2);
	}

	remainder1 = num1%2;
	if ( remainder1 == 0)
	{
	
		printf("%d is even\n", remainder1);
	}
	
	else
	{
		if ( remainder1 == 1)
		printf("%d is odd\n", remainder1);
	}
	
	remainder2 = num2%2;
	if ( remainder2 == 0)
	{
		printf("%d is even\n", remainder2);
	}
	
	else
	{
		if ( remainder2 == 1)
		printf("%d is odd\n", remainder2);
	}


	return 0;



}





