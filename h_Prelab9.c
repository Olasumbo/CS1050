#include<stdlib.h>
#include<time.h>
#include<stdio.h>
#include<ctype.h>
#define MAX 20
 
int checkStudentNum( char array[MAX]);
int length( char array[]);

int main (void)
{
 char studentID[MAX];
 int len;
 printf(" Enter	the string of your Student ID:\n");
 scanf("%s", studentID);

len = length(studentID);
	while( checkStudentNum(studentID) == 0)
	{
		printf("Your student ID must contain 6 or more numbers. numbers only!\n");
		printf(" Enter a valid ID:\n" );
		scanf("%s", studentID);

	}
printf("String length is %d\n", len);

 return 0;
}

int checkStudentNum( char array[MAX])
{
	char *ptr = array;
	int is_a_digit = -1;
	int len =0;
	len = length(array);	
	if ( len > 0 || len <= 6)
	{
		return 0;
	}
	while (*ptr != '\0')
	{
		printf("Adress of pointer ptr is : %p\n", ptr);
		printf(" THe value in ptr is :%d\n", *ptr);
		ptr++;
	}

	is_a_digit == isdigit(*ptr);
	if(is_a_digit = 0)
	{
		return 0;
	}
}
int length( char array[])
{

	char* ptr = array;
	int counter = 0;
	
	while( *ptr != '\0')
	{
		ptr++;
		counter++;
	}

	return counter;
}

