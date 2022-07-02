//c program to mask a simple calculator to add,subtract,multiply or divide using switch ....case

#include "stdio.h"
void  main(){
	float a,b;
	char x;
	printf("enter a mathematical operation");
	fflush(stdin);fflush(stdout);
	scanf("%f",&a);
	scanf("%c",&x);
	scanf("%f",&b);
	switch (x){
	case '+':
		printf("%f %c %f = %f",a,x,b,a+b);
		break;
	case '-':
		printf("%f %c %f = %f",a,x,b,a-b);
		break;
	case '*':
		printf("%f %c %f = %f",a,x,b,a*b);
		break;
	case '/':
		printf("%f %c %f = %f",a,x,b,a/b);
		break;
	default :
		printf("error occurred");
	}


}
