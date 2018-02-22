#include<stdio.h>

int main (void)
{
	int circle = 0;
	int square = 0;
	int cube = 0;
	float  Areacircle;
	int Areasquare;
	int Areacube;
	int selection;
	int inputa = 0;
	int inputb = 0;
	int inputc = 0;
	int input = 0;
  printf(" Welcome to Area Calculator\n");
  printf(" 1 represents a circle\n 2 represents a square\n 3 represents a cube\n");
  printf(" Please make a selection: ");
  scanf("%d", &selection);

	switch (selection)
	{
		case 2:
		printf("Square\n");
		printf("Enter two positive number: ");
		scanf("%d", &inputa);
		while(inputa <= 0)
		{
			printf("Numbers must be greater than 0: ");
			scanf("%d", &inputa);
		}
		scanf("%d", &inputb);
		while(inputb <= 0)
		{
			printf("Numbers must be greater than 0: ");
			scanf("%d", &inputb);
		}
		Areasquare = inputa * inputb;
		printf("Area of the square is %d\n", Areasquare);
		break;

		case 3: 
		printf("Cube\n");
		printf("Enter a positive number: ");
		scanf("%d", &inputc);
		while(inputc <= 0)
		{
			printf("Numbers must be greater than 0: ");
			scanf("%d", &inputc);
		}
		Areacube = 6*inputc*inputc;
		printf("Area of the cube  is %d\n",Areacube);
		break;

	}
  if( selection == 1)
  {	
	   printf(" circle\n");
	   printf(" Enter a positive number: ");
	   scanf("%d", &input);
	   if (input <= 0)
	       	{	
		   printf(" Number can't be zero or negative\n");
		}
	   else
		  {
		   Areacircle = (3.14159*input*input);
		   printf( " Radius of circle is %d\n", input);
		   printf(" Area of circle is %.2f\n", Areacircle);
		  }
  }
return 0;

}
