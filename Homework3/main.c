#include "Homework3.h"

int main(int argc, char** argv)
{
	 if ( argc != 2)
         {
              printf( "Incorrect number of arguments\n");
              return 0;
         }

	Node* root = get_cars(argv[1]);

	while( root == NULL)
	{
		printf("End of file reached");
	}

	int key;
	int count = 0;
	int year;
	int price;

  do    
  {
	printf(" To search for a vehicle newer than a specific year enter '1'\n");
	printf(" To search for a vehicle that costs less than a certain price enter '2'\n");
	printf(" To search for a vehilce with both of the above parameters enter '3'\n");
	printf(" To exit enter '-1'\n");
	scanf("%d", &key);

	while( key < -1 || key > 3)
        {
        	printf("Incorrect input value\n");
                scanf("%d", &key);
        }
	
	switch( key )
	{
		case 1:
		printf("Enter the year you would like the vehicles to be newer than:\n");
		scanf("%d", &year);
		search_tree(root, year,price,&count);

		break;

		case 2:
		printf("Enter the price you would like the vehicles to be less than:\n");
		scanf("%d", &price);
		while( price < -1 || price > MAXCARPRICE)
		{
			printf("You are going beyond our budget\n");
			printf(" Enter a valid amount\n");
			scanf("%d", &price);
		}
		search_tree(root, year,price, &count);

		break;

		case 3:
		printf("Enter the year you would like the vehicles to be newer than:\n");
		scanf("%d", &year);
		printf("Enter the price you would like the vehicles to be less than:\n");
		scanf("%d", &price);
		search_tree(root, year,price, &count);

		break;

		default:
		break;

	}
  }while( key != -1);
	
	Free(root);

return 0;
}
