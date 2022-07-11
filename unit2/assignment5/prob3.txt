//C program to add two complex numbers



#include "stdio.h"

struct Snumber{
	float real;
	float img;
}num1,num2,sum;

void main(){
	printf("Enter num1\n");
	printf("Real : ");
	fflush(stdin);fflush(stdout);
	scanf("%f",&num1.real);
	printf("Imaginary : ");
	fflush(stdin);fflush(stdout);
	scanf("%f",&num1.img);
	printf("Enter num2\n");
	printf("Real : ");
	fflush(stdin);fflush(stdout);
	scanf("%f",&num2.real);
	printf("Imaginary : ");
	fflush(stdin);fflush(stdout);
	scanf("%f",&num2.img);
	sum.real=num1.real+num2.real;
	sum.img=num1.img+num2.img;

	printf("num1 + num2 = %.2f%c%.2f i",sum.real,(sum.img>0)?'+':' ',sum.img);
}
