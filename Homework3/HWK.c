#include "Homework3.h"

int help (char* string)
{

	if(string == NULL){
		printf("ERROR IN HELP, STRING IS NULL!!\n");
		return -1;
	}

	if(strcmp( string,"price") == 0)
	{
		return 1;
	}
	else if (strcmp(string,"mileage") == 0)
	{
		return 2;
	}
	else if (strcmp(string,"model") == 0)
	{
		return 3;
	}
	else if (strcmp(string,"color") == 0)
	{
		return 4;
	} 
	else if (strcmp(string,"make") == 0)
	{
		return 5;
	} 
	else if (strcmp(string,"type") == 0)
	{
		return 6;
	} 
	else if (strcmp(string,"year") == 0)
	{
		return 7;
	}

	return 0; 
}

int color_helper (char* string)
{
        if(string == NULL)
	{
                 printf("ERROR\n");
                 return -1;
        }

        if(strcmp( string,"blue") == 0)
        {
                return 1;
        }
        else if (strcmp(string,"red") == 0)
        {
		return 1;
        }
        else if (strcmp(string,"yellow") == 0)
        {
                 return 1;
        }
        else if (strcmp(string,"silver") == 0)
        {
                return 1;
        }
	else if (strcmp(string,"orange") == 0)
        {
                return 1;
        }
	else if (strcmp(string,"black") == 0)
        {
                  return 1;
        } 
	else if (strcmp(string,"white") == 0)
        {
                 return 1;
        }
        else if (strcmp(string,"green") == 0)
        {
                return 1;
        }
	else if (strcmp(string,"purple") == 0)
        {
                 return 1;
        }
	else if (strcmp(string,"turquise") == 0)
        {
                return 1;
        }
        return 0;
}

int make_helper (char* string)
 {
        if(string == NULL)
        {
                printf("ERROR\n");
                return -1;
        }
        if(strcmp( string,"chevrolet") == 0)
        {
               return 1;
        }
        else if (strcmp(string,"ford") == 0)
        {
                return 1;
        }
        else if (strcmp(string,"bmw") == 0)
        {
                return 1;
        }
        else if (strcmp(string,"mercury") == 0)
        {
                 return 1;
        }
        else if (strcmp(string,"pontiac") == 0)
        {
                 return 1;
        }
        else if (strcmp(string,"mercedes") == 0)
        {
                return 1;
        }
        else if (strcmp(string,"subaru") == 0)
        {
                 return 1;
        }
        else if (strcmp(string,"hundai") == 0)
        {
                  return 1;
        }
        else if (strcmp(string,"bugatti") == 0)
        {
                return 1;
        }
 	else if (strcmp(string,"toyota") == 0)
        {
                  return 1;
        }
        else if (strcmp(string,"gmc") == 0)
        {
                return 1;
        }
	else if (strcmp(string,"acura") == 0)
        {
                return 1;
        }
	else if (strcmp(string,"buick") == 0)
        {
                return 1;
        }
	else if (strcmp(string,"audi") == 0)
        {
                return 1;
        }
	else if (strcmp(string,"ferrari") == 0)
        {
                return 1;
        }
	else if (strcmp(string,"honda") == 0)
        {
                return 1;
        }
	else if (strcmp(string,"jeep") == 0)
        {
                return 1;
        }
	else if (strcmp(string,"kia") == 0)
        {
                return 1;
        }
	else if (strcmp(string,"dodge") == 0)
        {
                return 1;
        }
	else if (strcmp(string,"porche") == 0)
        {
                return 1;
        }
         return 0;
}

int type_helper (char* string)
{
        if(string == NULL)
        {
                printf("ERROR\n");
                return -1;
        }
        if(strcmp( string,"car") == 0)
        {
               return 1;
        }
	else if (strcmp(string,"truck") == 0)
        {
                return 1;
        }
	else if (strcmp(string,"van") == 0)
        {
                return 1;
        }
	else if (strcmp(string,"suv") == 0)
        {
                return 1;
        }

        return 0;
}
 
Node* get_cars(char* filename)
{ 
	FILE* fp = fopen(filename, "r");
	if ( fp == NULL)
	{
		printf("unable to open file\n");
		return NULL;
	}

	//We have space to store our sentace from the input file
	char line[MAXLINELENGTH];


	//Temp node to be added to our tree
	Node* space = NULL;

	//Actually pointer to our root of our tree
	Node* root = NULL;

	char* value = NULL;
	int key = 0;
	int error = 0;
	int catch = 0;

	while(fgets(line, MAXLINELENGTH, fp) != NULL)
	{
		space = malloc(sizeof(Node));

		value = strtok( line,"|");

		key = help(value);//This sends a line to the help function. it finds a TOKEN then returns a corresponding number. 

		//printf("Our token is: %s giving us a key of: %d\n\n\n",value,key);		

		while( value != NULL)
		{	
			switch(key)
			{
				// ************When it goes into case 1, we know it pointing at the string PRICE, then we string token NULL to make it point at the VALUE of price which gets place in value, then atoi it, then put it in my node(space)..Same goes for the other switch option***********	
				case 1:
					value = strtok( NULL, "|");// this is pointing to the price value
					//printf("We are inside case 1 and our value is: %s\n", value);
					space->price = atoi(value);// change it to number and put it in my NOde
					//printf("%d\n", space->price); // makin sure i have the right thing.
					break;

				case 2:
					value = strtok( NULL, "|");	
					//printf("We are inside case 2 and our value is: %s\n", value);
					space->mileage = atoi(value);
					//printf("%d\n", space->mileage); 
					break;

				case 3:
					value = strtok( NULL, "|");
					//printf("We are inside case 3 and our value is: %s\n", value);
					strcpy(space->model, value);
					//printf("%s\n", space->model); 
					break;

				case 4:
					value = strtok( NULL, "|");
					//printf("We are inside case 4 and our value is: %s\n", value);
					error = color_helper(value);
					if( error == 0)
					{
						free(space);
						catch++;
						//printf("The color of this car is invalid\n");
					}
					else
					{
						strcpy(space->color, value);
						//printf("%s\n", space->color);
					} 
					break;

				case 5:
					value = strtok( NULL, "|");
					//printf("We are inside case 5 and our make  is: %s\n", value);
					error =  make_helper(value);
					if( error == 0)
					{
						 free(space);
						 catch++;
                                                 //printf("The make of this Car is invalid\n");
					}
					else
					{
						 strcpy(space->make, value);
						 //printf("%s\n", space->make);
					}
					break;

				case 6:
					value = strtok( NULL, "|");
					//printf("We are inside case 6 and our type is: %s\n", value);
					error = type_helper(value);
					if(error == 0)
					{
						free(space);
						catch++;
						//printf(" The make of this car is invalid\n");
					}
					else
					{
						strcpy(space->type, value);
						//printf("%s\n", space->type); 
					}
					break;

				case 7:
					value = strtok( NULL, "|");
					//printf("We are inside case 7 and our year is: %s\n", value);
					space->year = atoi(value);
					//printf("%d\n", space->year); 
					break;

				default:
					//printf("********We are inside case Default*****\n\n");
					break;
			}
			value = strtok( NULL, "|");
			if(value == NULL){
				break;
			}
			key = help(value);	
			//printf("EXTRA CHECK, VALUE IS %s\n",value);
		}
		if( catch == 0)
		{
			root = add_to_tree(root,space);
		}
	}

	fclose(fp);	
	return space;
}

Node* add_to_tree(Node* head, Node* new)
{
	if(head == NULL)
	{
		head = malloc(sizeof(Node));	
		head->price = new->price;
		strcpy(head->model, new->model); 
		strcpy(head->type, new->type);
		strcpy(head->make, new->make);
		head->mileage = new->mileage;
		strcpy(head->color, new->color);
		head->year = new->year;
		head->left = NULL;
		head->right = NULL;
	}
	else if (new->price < head->price)
	{
		head->left = add_to_tree( head->left, new);
	}
	else if (new->price > head->price)
	{
		head->right = add_to_tree( head->right, new);
	}

	return head;//this returns the head
}

void search_tree(Node* root, int year, int price, int* count)
{
	if(price == 0)
	{
		price = 200000000;
	}
	if (root != NULL)
	{
		if( root->year > year && root->price <= price)
		{
			printf("%s %s %s %s %d %d %d",root->color, root->type, root->model, root->make, root->mileage, root->price, root->year);
			(*count)++;
		}
		search_tree(root->left, year, price, count);
		if(root->price <= price)
		{
			search_tree( root->right, year, price,count);
		}
		printf("The was %d cars founds\n", *count);

	}
}

