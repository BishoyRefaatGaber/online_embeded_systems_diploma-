//c program to calculate the power of a number using recursion


#include "stdio.h"
int power (int y,int l){

if (l!=0)
return y*power(y,l-1);
else return 1;
}

void main (){
	int num1,num2;
	printf("Enter Base number : ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&num1);
    num2=power(num1,num1);
    printf("%d ^ %d = %d",num1,num1,num2);
}
