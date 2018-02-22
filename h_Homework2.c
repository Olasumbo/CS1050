#include<time.h>
#include<stdio.h>
#include<stdlib.h>

// Global Constants

#define ROW 6 // for row length
#define COL 4 // for column length
#define MAX 25 // for strings

void initialseats( char flight[][COL], int count);
void displayMenu();
void printFlightMap(char flight[][COL]);
int loginMatch ( char string1[], char string2[]);
int getTotalRevenue( char flight1[][COL], char flight2[][COL], char flight3[][COL]);
void flightMenu();
void seatReservation( char flight[][COL]);
void printMessage( char name[MAX], char num[MAX]);

int costMatrix[ROW][COL] = {{300, 200, 200, 300},
			    {300, 200, 200, 300},
	                    {300, 200, 200, 300},
                            {300, 200, 200, 300},
			    {300, 200, 200, 300},
	                    {300, 200, 200, 300}}; // This is the cost of each seat in all 3 flights.


int main(void)

{
	printf("********** WELCOME TO JOE'S AIRLINE BOOKING SYSTEM**************\n");
	char flight_1[ROW][COL];
	char flight_2[ROW][COL];
	char flight_3[ROW][COL];
	char userpawprint[MAX];
	char userpassword[MAX];
	char Name[MAX];
	//char flight_number[MAX];
	char adminPawprint[] = "dcwtb9";  //Darius Washington
	char adminPassword[] ="cmp_sc1050";


	srand(time(NULL));

        int seats;
	seats  = (1+ rand()% 5);

        int input;  // DIsplay menu calling
        displayMenu();
	scanf("%d", &input);
	 while (input < 1 || input > 3)
	{	
		printf(" Enter a valid choice\n");
		displayMenu();
		scanf("%d", &input);
	}

	    	switch(input)

	{
		case 1:
		printf(" Enter Admin Pawprint:");
		scanf("%s", userpawprint);
		int paw = 0;
		paw = loginMatch (adminPawprint, userpawprint);
		while (paw == 0)
		   {
			printf(" Invalid Pawprint\n");
			scanf("%s", userpawprint);
			paw = loginMatch(adminPawprint, userpawprint);
		   }
		
		// user input password
		printf(" Enter Admin Password:");
		scanf("%s", userpassword);
		int pass = 0;
		pass = loginMatch ( adminPassword, userpassword);
		while ( pass  == 0)
		   {
			printf(" Invalid Password combination\n");
			scanf("%s", userpassword);
			pass = loginMatch(adminPassword, userpassword);
		   }

	printf(" Printing Flight Map for Columbia to Miami\n");   /// Print Flight MAp
	//printFlightMap(flight_1);
	initialseats( flight_1, seats);
	printf(" Printing Flight Map for Columbia to Nashville\n");
	//printFlightMap(flight_2);
	initialseats( flight_2, seats);
	printf(" Printing Flight Map for Columbia to Las Vegas\n");
	//printFlightMap(flight_3);
	initialseats( flight_3, seats);
      printf(" The total earning from all the flights is $%d\n", getTotalRevenue(flight_1, flight_2, flight_3));
      printf(" You are logged out now\n");

	  break;
	  
	  case 2:  
	   
	 flightMenu();
         int choice;
	 scanf("%d", &choice);

               while  ( choice < 1 || choice > 3)
		{
		 printf(" Enter a valid option\n");
		 scanf("%d", &choice);
		}
	 if ( choice == 1)
	 {
	       initialseats( flight_1, seats);
          printf(" Enter your name");
	  scanf("%s", Name);
  		seatReservation(flight_1);
		char CouMia[] = "MIA1050";
               printf(" Congrats %s , your flight %s is booked\n", Name, CouMia);
	       printf(" Your e-ticket number is ");	        
	       printMessage( Name,CouMia);
	       printf("\n");
	 }

	 else if ( choice == 2)
		{
			initialseats( flight_2, seats);
 		printf(" Enter your name:\n");
		scanf("%s", Name);
			 seatReservation(flight_2);
			char CouNash[] = "BNA1050";
               printf(" Congrats %s , your flight %s is booked\n", Name, CouNash);
	       printf(" Your e-ticket number is ");	        
	       printMessage( Name,CouNash);
	       printf("\n");
		}
	 else if ( choice == 3)
		{
	          initialseats( flight_3, seats);
	printf(" Enter your name:\n");
	scanf("%s", Name);
		seatReservation(flight_3);
		char CouLas[] = "LAS1050";
        printf(" Congrats %s , your flight %s is booked\n", Name, CouLas);
	printf(" Your e-ticket number is ");	        
	printMessage( Name,CouLas);
	printf("\n");

                }

	 	 break;

	 case 3:
	 return 0;

     }
        

     return 0;

}
void initialseats( char flight[][COL], int count)
{
	int i;
	int j; 
	int row = rand() % ROW;
	int col = rand() % COL;


	for(i =0; i < ROW; i++)
	{  
		for( j = 0; j < COL; j++)
		{
		    flight[i][j] = 'O';
		}
	}
	for(i = 0; i < count; i++){
		row = rand() % ROW;
		col = rand() % COL;
		flight[row][col] = 'X';
	}

	       printFlightMap(flight);

}


void displayMenu()
{
   printf ( " 1. Admin Log-in\n 2. Reserve a seat\n 3. Exit\n Choose your option:");
}

void printFlightMap(char flight[ROW][COL])
{
	int i;
	int j;
	for(i =0; i < ROW; i++)
	{  
		for( j = 0; j < COL; j++)
		{
		  	printf("%c", flight[i][j]);
	        }
	               printf("\n");
	}	
}

int loginMatch ( char string1[MAX], char string2[MAX])
{
	int i =0;
	while( string1[i] != '\0' && string2[i] != '\0')
	{
		if ( string1[i] != string2[i] )	

	 		{
			  return 0; 
			}
		else 
			++i;
	}
		return 1;
}

int getTotalRevenue( char flight1[][COL], char flight2[][COL], char flight3[][COL]) 
{
     int m, k;
     int i, j;
     int a, b;
     int Total = 0;

    for ( m = 0; m < ROW; m++)
        for( k = 0; k < COL; k++)
		if ( flight1[m][k] == 'X')
		   {
			 Total += costMatrix[m][k]; 
		   }

    for ( i = 0; i < ROW; i++)
        for( j = 0; j < COL; j++)
		if ( flight2[i][j] == 'X')
		   {
			 Total += costMatrix[i][j]; 
		   }

    for ( a = 0; a < ROW; a++)
        for( b = 0; b < COL; b++)
		if ( flight3[a][b] == 'X')
		   {
			 Total +=  costMatrix[a][b]; 
		   }   
   
     return Total;
}

void flightMenu()
{
	  printf("Choose a flight\n");
	  printf(" 1. COU -----> MIA\n");
          printf(" 2. COU -----> BNA\n");
          printf(" 3. COU -----> LAS\n");
	
}

void seatReservation( char flight[ROW][COL])
{
      	int seatrow;
	int seatcol;
	int x = 0;

	while(x == 0)
	{
		printf(" Which seat row do you want:\n");
		scanf("%d", &seatrow);
		while( seatrow < 0 || seatrow > 5)
		{
			printf(" Error,pick a valid seat\n");
			scanf("%d", &seatrow);
		}
		printf(" Which seat column do you want:\n");
		scanf("%d", &seatcol);
		while( seatcol < 0 || seatcol > 3)
		{
			printf(" Error,pick a valid seat\n");
			scanf("%d", &seatcol);
		}
           if ( flight[seatrow][seatcol] == 'X')
		   {
			printf(" Error this seats hs been taken\n"); 
		   } 
     
            else   
	  	{
			(flight[seatrow][seatcol] = 'X');
			printf(" Your request has been reserved\n");
			printFlightMap(flight);
			printf("\n");
			++x;
		}
	}
	
}
void printMessage( char name[MAX], char num[MAX])
{
	int i = 0;
	while( name[i]	!= '\0'&& num[i] != '\0' )
	{	
	        printf("%c%c", name[i] , num[i]);
		++i;
	}

	if  ( name[i] == '\0')
	{
		while (num[i] != '\0')
		{
		   printf("%c", num[i]);
		   ++i;
		}
		
	}

	if  ( num[i] == '\0')
	{
		while (name[i] != '\0')
		{
		   printf("%c", name[i]);
		   ++i;
		}
		
	}
}

 

