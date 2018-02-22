#include<stdlib.h>
#include<time.h>
#include<stdio.h>
#define MAX 100

int length (char*);
char* copy(char*);
void clear( char*);
char* reverse(char*);
int compare( char*, char*);
char* merge( char*, char*);
int palindrome(char*);



int main( void )
{
	char* sptr = NULL;  // understand this 
        sptr = malloc(sizeof(char)*MAX); // this is the same thing as efining a character and assigning it a number.
	printf(" Enter a String\n");
	printf(" Input string is:  ");
	scanf("%s", sptr);
	
	int len =0;
	len = length(sptr);
	//printf(" The length of the string is %d", len);	

	char*string2 = copy(sptr);
	printf(" The copy of %s to string 2 is %s\n", sptr, string2);

	char * st = reverse(sptr);
	printf(" The reverse of %s is %s\n", sptr, st);
	
	char * sec = NULL;
        sec  = malloc(sizeof(char)*MAX); 
	printf(" Enter a String\n");
        scanf("%s", sec);
	//printf(" The merge of %s and %s is %s\n", sec, seco, sptr);
        char *seco = merge(sptr, sec);
	printf(" The merge of %s and %s is %s\n", sec, seco, sptr);
	

	clear(sptr);
	clear(string2);

	return 0;
}
int length (char* string)
{
	int len = 0;
	int i = 0;
	while( *(string + i)  != '\0')
	{
		//printf(" The character we are looking at is %c \n\n", *(string+i));
        	len++;
		i++;
	}
	return len;
}
char* copy(char* string)
{
	int i = 0;
	int len = length(string);
	char *sptr2 = malloc(sizeof(char)* (len+1)); 
	while ( *(string+i) != '\0')
	{
	    *(sptr2 + i) = *(string + i);
	      i++;
	}
            *(sptr2+i) = '\0';

return sptr2;

}
void clear( char* string)
{
	free(string);
}
char* reverse(char* string)
{
	int i;
	int len = length(string);
	char *sptr = malloc(sizeof(char)* (len+1)); 
	for( i = 0;i < len; i++)
	{
		*(sptr+i) = *(string+len - i-1);
	}

	   *(sptr+(len)) = '\0';

return sptr;

}
//int compare( char* string1, char* string2)
//{
	//char *sptr = malloc(sizeof(char)* (10)); 
//}


char* merge( char* string1, char* string2)
{
	int i =0;
	//int j =0;
	char *sptr = malloc(sizeof(char)* (length(string1)+length (string2)+1)); 
	while( *(string1+i) != '\0'&& *( string2 +i) != '\0' )
	{	
	        printf("%c%c", *(string1 + i) , *(string2 + i));
		++i;
	}

	if  ( *(string1 +i) == '\0')
	{
		while (*(string2+i) != '\0')
		{
		   printf("%c", *(string2 +i));
		   ++i;
		}
		
	}

	if  ( *(string2 + i) == '\0')
	{
		while ( *(string1 +i) != '\0')
		{
		   printf("%c", *(string1 +i));
		   ++i;
		}
		
	}
return sptr;
}

//int palindrome(char*);






      
