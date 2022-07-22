//Write Source Code to Swap Two Numbers


#include "stdio.h"
void  main(){
	float a,b,c;
	printf("Enter value of a:");
	fflush(stdin);fflush(stdout);
	scanf("%f",&a);
	printf("Enter value of b:");
	fflush(stdin);fflush(stdout);
	scanf("%f",&b);
	c=a;
	a=b;
	b=c;
	printf("After swapping, value of a = %.2f\n",a);
	printf("After swapping, value of a = %.2f\n",b);
}


