#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 10

int check_error(int size)
{
	if (size<=0 || size>100)
		return 0;
	else
		return 1;
}
void init_2D_Array(int a[][MAX],int size)
{
	int i,j;
	srand(time(NULL));
	for(i=0; i<size; i++)
	{
		for( j=0; j<size; j++)
		{
			a[i][j]= rand()%10;
		}
	}
}
void print_2D_array(int a[][MAX],int size)
{
	int i,j;
	for( i=0; i<size; i++)
	{
		for( j=0; j<size; j++)
		{
			printf("%3d",a[i][j]);
		}
		printf("\n");
	}
}
int check_index(int a,int size)
{
	if(a<1 || a>size)
		return 0;
	else
		return 1;
}

int col_max(int a[][MAX],int c,int size)
{
	int i;
	int max;
	if(c!=0)
		c=c-1;
	max=a[0][c];
	for(i=0;i<size;i++)
	{
		if(a[c][i]>max)
		{
			max=a[i][c];
		}
	}
	return max;
}
float col_avg(int a[][MAX],int c,int size)
{
	int i;
	float sum;
	if(c!=0)
		c=c-1;
	for(i=0;i<size;i++)
	{
		sum+=a[i][c];
	}
	return  sum/size;
}
int countZero(int a[][MAX],int size)
{
	int i,j;
	int count = 0;
	for (i = 0; i < size; ++i)
	{
		for (j = 0; j < size; ++j)
		{
			if(a[i][j]==0)
				count++;
		}
	}
	return count;
}
void addN(int a[][MAX],int size)
{
	int i,j;
	int add = 0;
	for (i = 0; i < size; ++i)
	{
		int add = 0;
		for (j = 0; j < size; ++j)
		{
			add+=a[i][j];
		}
		a[i][--j]=add;
	}
	printf("New Matrix is : \n");
	print_2D_array(a,size);
}
int length(char x[])
{
	int i = 0;
	int count = 0;

	while( x[i] != '\0' )
	{
		i++;
	}
	return i;
	
}
void copy(char x[],char y[])
{
	int i;
	int len=length(x);
	for(i=0;i<=len;i++)
	{
		y[i]=x[i];
	}
	i++;

}
void merge(char x[],char y[],char z[])
{
	int a=length(x);
	int b=length(y);
	int i;

	for(i=0;i<b;i++)
	{
		z[i]=x[i];
	}
	for(i=0;i<a;i++)
	{
		z[i+a]=y[i];
	}
	z[i+a]='\0';
}
int main(void)
{
	int size;
	int array[MAX][MAX];
	printf("\n Enter the size of the array : ");
	scanf("%d",&size);
	while(check_error(size)==0)
	{
		printf("\n Out of bounds, Please enter the size again : ");
		scanf("%d",&size);
	}
	init_2D_Array(array,size);
	printf("\n The 2D array is : \n");
	print_2D_array(array,size);
	int col;
	printf("\n Enter the column 1-%d : ",size);
	scanf("%d",&col);
	while(check_index(col,size)==0)
	{
		printf("\n Enter the column 1-%d : ",size);
		scanf("%d",&col);
	}
	int max=col_max(array,col,size);
	printf("\n The largest number present in the column %d is %d ", col,max);
	float avg=col_avg(array,col,size);
	printf("\n The average of the numbers in the column %d is %.2f ", col,avg);
	int zero=countZero(array,size);
	printf("\n The number of Zero's in the 2-D array is %d \n",zero );
	addN(array,size);
	//printf("\n New Matrix is : \n");
	//print_2D_array(array,size);

	char a[MAX],b[MAX],c[MAX];
	printf("Enter a string: \n");
	scanf("%s",a);
	int len=length(a);
	printf(" Length of the string %s is %d ",a,len);
	copy(a,b);
	printf("The copy of the string %s is %s\n",a,b);

	printf("***** BONUS *****\n");
	printf("\n Enter the second string: ");
	scanf("%s",b);
	merge(a,b,c);
	printf("\n The merged string is: %s \n",c);
	
	return 0;
}
		



