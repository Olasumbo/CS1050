#include<stdlib.h>
#include<time.h>
#include<stdio.h>
#define MAX 100

int length (char*);
char* copy(char*);
void clear( char*);

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
		printf(" The character we are looking at is %c \n\n", *(string+i));
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


