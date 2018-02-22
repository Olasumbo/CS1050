#include<stdlib.h>
#include<time.h>
#include<stdio.h>

int load_data( char* filename, int* accountnum, float* amount, int size);
void print_data( int*, float*, int );
int highest_amount( float*, int);
int lowest_amount( float*, int);
float average_amount( float*, int);
int update_data(char*, int*, float*, int);
void write_data( char*, int*, float*, int, int, int, float);
void print_stats( int*, float*, int, int, int, float);
void sort_data( int*,float*, int);


int main(int argc, char *argv[])
{
  if (argc !=  5)
  {
  	printf("Incorrect number of arguments\n");
	return 1;
  }
  int size = atoi(argv[2]);
  int *account =(int*) malloc(sizeof(int) * size);
  float *amount =(float*) malloc(sizeof(float) * size);
  int load;
  load = load_data(*(argv+1),account,amount, size);
  //printf("load\n");
  int store = lowest_amount(amount,size);
  int storemax = highest_amount(amount,size);
  print_data(account, amount, size);
  
  printf(" The highest amount is %.2f in the account %d\n",*(amount + storemax), *(account + storemax));
  printf(" The lowest amount is %.2f in the account %d\n", *(amount + store),*( account + store));
  printf(" The average amount is %.2f\n", average_amount(amount,size));

  printf("****UPDATE WITH NEW VALUES****\n");

  //load_data(*(argv+1),account,amount, size);
  update_data(*(argv + 3), account, amount, size);
  sort_data( account,amount, size);
  store = lowest_amount(amount,size);
  storemax = highest_amount(amount,size);
  average_amount(amount, size);
  print_data(account, amount, size);

  //load_data(*(argv+1),account,amount, size);
  print_stats(account, amount, size, storemax, store, average_amount(amount,size)); 
  write_data(*(argv + 4), account, amount, size,storemax, store, average_amount(amount,size));



  free(account);
  free(amount);


  return 0;

}
int load_data( char* filename , int* accountnum ,float* amount, int size)
{
	FILE *cfptr = fopen(filename,"r"); 
	    if( cfptr == NULL )
	{
	     printf(" file could not be opened\n");
	     return 0;
	}
	int i;
	printf(" Account  Amount\n");
	for ( i = 0; i < size; i++)
	{
		fscanf( cfptr, "%d %f ", (accountnum + i), (amount+ i));
		//printf("%d     %.2f", *(accountnum + i),*(amount + i));
	}
	fclose(cfptr);

	return 1;
}
void print_data( int* accountnum , float* amount, int size )
{
	int i;
	//float* amount;
	//int*  accountnum;
	for( i = 0; i < size; i++)
	{
		printf(" %d, %.2f\n", *(accountnum + i), *(amount + i));
	}
}
int highest_amount(float *amount, int size)
{
	int i;
	//int  max = 0;

	int max = *(amount + 1);
	int index = 0;
	for ( i = 1; i < size; i++)
	{
		if(*(amount + i) > max)
		{
		     max = *(amount +i);
		     index = i;
		}
	}
return index;
}
int lowest_amount( float *amount, int size)
{
	int i;
	//int min = *(amount + 1);

	int min = *(amount + 1);
	int index = 0;
	for ( i = 0; i < size; i++)
	{
		if(*(amount + i) < min)
		{
			min = *(amount +i);
			index = i;
		}
	}
return index;
}
float average_amount( float *amount, int size)
{
    int i;
    float average = 0.0;
    float total = 0;
    for( i = 0; i < size; i++)
    {
       total += *(amount + i);
    }
      average = (total/size) ;

      return average;
}
int update_data( char * filename, int* accountnum, float *amount, int size)
{
	FILE *fptr = fopen(filename,"r"); 
	    if( fptr == NULL )
	{
	     printf(" File could not be opened\n");
	     return 0;
	}

	//int *Accounts_update = (int*)malloc(sizeof(int)*size);
	int i;
	int *inpaccount = (int*)malloc(sizeof(int)*size);
        if( inpaccount == NULL )
	{
	     printf(" File could not be opened\n");
	     return 0;
	}

	float *inpamount = (float*)malloc(sizeof(float)*size);
        if( inpamount == NULL )
	{
	     printf(" File could not be opened\n");
	     return 0;
	}

	printf(" Account Amount\n");
	int j = 0;
	
        for ( i = 0; i < size; i++)
	{
            fscanf( fptr, "%d %f\n", (inpaccount + i), (inpamount + i));
	  
		for ( j = 0; j < 5; j++)
	{          
		if (*(accountnum + i) == *(inpaccount + j))
		{
		*(amount + i) += *(inpamount + j);
		}
	}
        }	
	fclose(fptr);
	free(inpaccount);
	free(inpamount);
	return 1;

	//return *(Accounts_update);
}

void write_data( char* filename, int* accountnum, float* amount, int size, int max, int min, float average)
{
	FILE *str = fopen(filename,"w"); 
	    if( str == NULL )
	{
	     printf(" File could not be opened\n");
	     fclose(str);
	}
	int i;
	for( i = 0; i < size; i++)

	fscanf(str, " %d %f\n", ( accountnum + i), ( amount + i));
	fprintf(str, "The highest amount is %.2f in the account %d\n", *(amount +max), *(accountnum + max));
	fprintf(str, "The lowest  amount is %.2f in the account %d\n",  *(amount + min), *(accountnum + min));
	fprintf(str, "The average amount is %.2f\n", average);
	printf(" output written to %s\n Thank you\n", filename);
	fclose(str);

}
void print_stats( int* accountnum , float* amount, int size, int max, int min, float average)
{
      	printf("The highest  amount is %.2f in the account %d\n", *( amount + max), *(accountnum + max));
	printf("The lowest amount is %.2f in the account %d\n",  *( amount + min), *(accountnum + min));
	printf("The average amount is %.2f\n", average);	
}
void sort_data( int* accountnum ,float* amount, int size)
{
int i, j;
int temp = 0;
int temp2 = 0;

  for(i = 0; i < size-1; i++)
{
	for(j=0; j < size-i-1; j++)
	{
		if(*(accountnum + j) > *(accountnum + j+1))
		{
			temp = *( accountnum + j);
			*(accountnum + j) = *(accountnum + j+1);
			*(accountnum +j + 1) = temp;

                         temp2 = *( amount + j);
			*(amount + j) = *(amount+ j+1);
			*(amount + j + 1) = temp2;

		}
	}
}

}
