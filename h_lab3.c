#include<stdio.h>
#include<math.h>

int main (void)
{
	int selection;
	float year;
        float inputa;
	float Amount;
	float TotalAmount;
	float TotalInterest;

  printf("Bank account type\n");
  	 
	 while ( selection < 1 || selection > 3)
	 {
		 printf(" 1 represents Checking\n");
                 printf(" 2 represents Saving\n");
                 printf(" 3 represents Fixed Deposit\n");
	         printf(" Please enter a selection: ");
                 scanf("%d", &selection);
         }  
	 
	switch (selection)
	{
		case 1:
		printf("Enter a year\n");
		scanf("%f", &inputa);
		while(inputa < 1 || inputa > 10)
		{
			printf("Incorrect value. Year should be between 1-10 ");
			scanf("%f", &inputa);
		}
		
		printf("Enter Amount\n");
		scanf("%f", &Amount);
		while(Amount  < 1 || Amount == 0)
		{
			printf("Incorrect value.Enter Amount again ");
			scanf("%f", &Amount);
		}

                TotalAmount = Amount* pow(1.01, inputa);
		printf(" Total amount after %.02f years is %.02f \n", inputa, TotalAmount);

		TotalInterest = ( TotalAmount - Amount );
		printf(" Total interest earned on the amount %.02f is %.02f \n", Amount, TotalInterest);

		break;

		case 2:
		printf("Enter a year\n");
		scanf("%f", &year);
		while(year < 1 || year > 10)
		{
			printf("Incorrect value. Year should be between 1-10 ");
			scanf("%f", &year);
		}
		
		printf("Enter Amount\n");
		scanf("%f", &Amount);
		while(Amount  < 1 || Amount == 0)
		{
			printf("Incorrect value.Enter Amount again ");
			scanf("%f", &Amount);
		}

                TotalAmount = Amount* pow(1.03, year);
		printf(" Total amount after %.02f years is %.02f \n", year, TotalAmount);

		TotalInterest = ( TotalAmount - Amount );
		printf(" Total interest earned on the amount %.02f is %.02f \n", Amount, TotalInterest);

		break;

		case 3:
		printf("Enter a year\n");
		scanf("%f", &year);
		while(year < 1 || year > 10)
		{
			printf("Incorrect value. Year should be between 1-10 ");
			scanf("%f", &year);
		}
		
		printf("Enter Amount\n");
		scanf("%f", &Amount);
		while(Amount  < 1 || Amount == 0)
		{
			printf("Incorrect value.Enter Amount again ");
			scanf("%f", &Amount);
		}

                TotalAmount = Amount* pow(1.07, year);
		printf(" Total amount after %.02f years is %.02f \n", year, TotalAmount);

		TotalInterest = ( TotalAmount - Amount );
		printf(" Total interest earned on the amount %.02f is %.02f \n", Amount, TotalInterest);

		break;

	}
		
		return 0;

}
