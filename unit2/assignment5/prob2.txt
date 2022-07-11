//C program to add two distances (in inch-feet) system using structures


#include "stdio.h"

struct number{
	int feet;
	float inch;
}num1,num2,sum;

void main(){
	printf("Enter num1");
	fflush(stdin);fflush(stdout);
	scanf("%d",&num1.feet);
	scanf("%f",&num1.inch);
	printf("Enter num2");
	fflush(stdin);fflush(stdout);
	scanf("%d",&num2.feet);
	scanf("%f",&num2.inch);
	sum.feet=num1.feet+num2.feet;
	sum.inch=num1.inch+num2.inch;
	if (sum.inch>12){
		sum.inch-=12;
		sum.feet++;
	}

	printf("Sum of distances = %d feet - %.2f inches",sum.feet,sum.inch);
}
