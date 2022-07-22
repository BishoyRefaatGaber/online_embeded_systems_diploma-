//Write C Program to Multiply two Floating Point Numbers

#include "stdio.h"
void  main(){
	float x,y,mul;
	printf("Enter two integers:");
	fflush(stdin);fflush(stdout);
	scanf("%f",&x);
	scanf("%f",&y);
	mul=x*y;
	printf("product : %.2f",mul);

}


