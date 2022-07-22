//c program to calculate the factorial of a number using recursion


#include "stdio.h"

int fact (int x){
	if (x==1)return 1;
return x*fact(x-1);

}

void main (){
	int m,factnumber;
	printf("Enter a positive number : \n");
	fflush(stdin);fflush(stdout);
	scanf("%d",&m);
    factnumber=fact(m);
    printf("%d",factnumber);
}
