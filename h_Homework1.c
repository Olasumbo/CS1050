#include<stdio.h>
#include<math.h>

int main (void)
{	
	int inputa;
	float unit;
	float rate;
	float Energycharge;
	float Totalbill;
	float Customercharge;
	int choice;
	int counter = 0;
	float finalbill;
	// variables for the bonus
	int number;
	int x;
	int sum = 0;
	int sumeven = 0;
	int sumodd = 0;

do
{

  printf(" Welcome to Electricity Bill Calculator\n");
  printf(" 1 represents Residential\n 2 represents Commercial\n 3 represents Industrial\n");
  printf(" enter a connection type:\n ");
  scanf("%d", &inputa);
  while(inputa < 1 || inputa > 3)

	{
		printf("Incorrect choice. Please enter a valid choice\n");
                printf(" 1 represents Residential\n 2 represents Commercial\n 3 represents Industrial\n");
		scanf("%d", &inputa); 
	}

		       	 
  switch (inputa)

	{
		case 1:

		printf("Enter the number of units (in KWh):\n");
		scanf("%f", &unit);

		while(unit  < 1 || unit == 0)
		{
			printf("Incorrect value. Enter a positive unit \n ");
			scanf("%f", &unit);
		}

		if ( unit <= 300)
			rate = 7.50;
		if ( unit > 300 && unit <= 750) 
			rate = 10.00;
		if ( unit > 750 && unit <= 1500)
			rate = 13.50;
		if ( unit > 1500)
			rate = 15.00;

		Customercharge = 15.00;
		Energycharge = (unit*rate)/100;
	        Totalbill = ( Energycharge + Customercharge );
	
	 printf(" Total energy charge is $%.02f \n", Energycharge);
	 printf(" Total bill due from this connection is $%.02f \n", Totalbill);

 	 break;
 
		case 2:

		printf("Enter the number of units (in KWh):\n");
		scanf("%f", &unit);

		while(unit  < 1 || unit == 0)
		{	
		     printf("Incorrect value. Enter a positive unit \n ");
		     scanf("%f", &unit);
		}

		if ( unit <= 300)
			rate = 10.50;
		if ( unit > 300 && unit <= 750) 
			rate = 14.00;
		if ( unit > 750 && unit <= 1500)
			rate = 17.50;
		if ( unit > 1500)
			rate = 20.00;

		Customercharge = 70.00;
		Energycharge = ( unit*rate )/100;
	        Totalbill = ( Energycharge + Customercharge );
	
	 printf(" Total energy charge is $%.02f \n", Energycharge);
	 printf(" Total bill due from this connection is $%.02f \n", Totalbill);

 	 break;

		case 3:

		printf("Enter the number of units (in KWh):\n");
		scanf("%f", &unit);

		while(unit  < 1 || unit == 0)
		{	
		     printf("Incorrect value. Enter a positive unit \n ");
		     scanf("%f", &unit);
		}

		if ( unit <= 300)
			rate = 36.50;
		if ( unit > 300 && unit <= 750) 
			rate = 40.00;
		if ( unit > 750 && unit <= 1500)
			rate = 45.50;
		if ( unit > 1500)
			rate = 50.00;

		Customercharge = 650.00;
		Energycharge = ( unit*rate )/100;
	        Totalbill = ( Energycharge + Customercharge );
	
	 printf(" Total energy charge is $%.02f \n", Energycharge);
	 printf(" Total bill due from this connection is $%.02f \n", Totalbill);

 	 break;

}
	printf(" Do you want to calculate another bill? if yes type 1, if No type 0\n" );
	scanf("%d", &choice);
        while ( choice < 0 || choice > 1 )
	{
		printf("invalid choice. type 1 or 0\n");
		scanf("%d", &choice);
	}

	counter++;
	finalbill+= Totalbill;

}while(choice==1);
	
	printf(" You calculated the bill %d times and te total amount of the bill is $%.2f\n", counter, finalbill);


	printf("*****BONUS*****\n");
	printf(" Enter a number\n");
	scanf("%d", &number);
	
	  for( x = 1; x <= number; x++)
	{
         	printf("The numbers are: %d", x);
		printf("\n");
		sum += x;

		if ( x%2 == 0)
			sumeven += x;
		else
			sumodd += x;
	}
		printf(" The sum of all the numbers from 0 to %d is %d \n", number, sum); 
		printf(" The sum of all the even numbers:%d\n" , sumeven);
		printf(" The sum of all the odd numbers:%d\n" , sumodd);

	
	return 0;


}


