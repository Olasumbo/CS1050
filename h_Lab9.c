#include<stdlib.h>
#include<time.h>
#include<stdio.h>
#include<ctype.h>
#define MAX 20
 
int checkStudentNum( char array[MAX]);
int length( char array[]);
int checkDigit(char array[]);
int checkUpperLetter(char array[]);
int checkpasswordLength( char array[]);
int checkSpecialchar( char array[]);



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

char password[MAX];
printf(" Enter your password\n");
scanf("%s", password);
	
	while( checkpasswordLength(password) == 0)
	{
		printf("Password length  must be 6-10!\n");
		printf(" Enter a valid password:\n" );
		scanf("%s", password);
	}


	while( checkUpperLetter(password) == 0)
	{
		printf("Password must include uppercase!\n");
		printf(" Enter a valid password:\n" );
		scanf("%s", password);
	}

	while( checkDigit(password) == 0)
	{
		printf("Password must include a digit!\n");
		printf(" Enter a valid password:\n" );
		scanf("%s", password);
	}

	while( checkSpecialchar(password) == 0)
	{
		printf(" Please incluse a special charater in your password \n");
		printf(" Enter a valid password:\n" );
		scanf("%s", password);
	}

 return 0;
}

int checkStudentNum( char array[MAX])
{
	char *ptr = array;
	int is_a_digit = -1;
	int len =0;
	len = length(array);	
	if ( len < 6 || len > 8)
	{
		return 0;
	}
	//while (*ptr != '\0')
	//{
		//printf("Adress of pointer ptr is : %p\n", ptr);
		//printf(" THe value in ptr is :%d\n", *ptr);
		//ptr++;
	//}

	is_a_digit = ( isdigit(*ptr));
	if(is_a_digit == 0)
	{
		return 0;
	}
	else;
	return 1;

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
int checkUpperLetter(char array[])
{
	char* ptr = array;
	int i;
	for( i =0; ptr[i] !='\0'; i++)
	{
	     if (isupper(ptr[i])!= 0)
	     return 1;
	}
	
return 0;
}
int checkDigit(char array[])
{
	char* ptr = array;
	int i;
	for(i =0; ptr[i] !='\0'; i++)
	{
	     if (isdigit( ptr[i]) != 0)
	     return 1;
	}	
return 0;
	
}
int checkpasswordLength( char array[])
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
int checkSpecialchar( char array[])
{
	int i =0;
	while( array[i] !='\0' )
	{
		if( isalnum(array[i] != 0))
			i++;
	}

	if ( i == 0)
		return 0;
	else
		return 1;

}
