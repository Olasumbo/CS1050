#include<stdlib.h>
#include<time.h>
#include<stdio.h>
int average_amount(int x, int y, int z);
int check_grade(int x);

 
int main(int argc, char *argv[])
{
  if (argc !=  7)
  {
  	printf("Incorrect number of arguments\n");
	return 1;
  }
  
  int grade1 = atoi(argv[3]);
  int grade2 = atoi(argv[4]);
  int grade3 = atoi(argv[5]);

 //printf(" The average of the course is %d\n", average_amount(grade1,grade2, grade3));
 int grd = average_amount( grade1, grade2, grade3);
 printf(" The grade of %s %s is %c\n", argv[1], argv[2], check_grade(grd));
 printf(" The average of the course is %d\n", average_amount(grade1,grade2, grade3));


return 0;
}
int check_grade( int x)
{
	char g;
	if ( x <= 60)
	{
		g = 'F';
	}
	if ( x > 60 && x <= 70)
	{
		g ='D';
	}
	if ( x > 70 && x <= 80)
	{
		g = 'C';
	}
	if ( x > 80 && x <= 90)
	{
		g = 'B';
	}
	if ( x > 90 && x <= 100)
	{
		g = 'A';
	}

	return g;

}
int average_amount( int x, int y, int z)
{
    //int x,y,z;
    int average = 0;
    int total = 0;
    total = (x+y+z);
    average = (total/3) ;

      return average;
}
