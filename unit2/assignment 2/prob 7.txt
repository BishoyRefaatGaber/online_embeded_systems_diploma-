//c program to find factorial of a number

#include "stdio.h"
void  main(){
	int a,fact=1;
	printf("Enter an integer :");
	fflush(stdin);fflush(stdout);
	scanf("%d",&a);
	if (a>0){
		for(int i=1;i<=a;i++){
			fact*=i;
		}
	}
	else printf("Error!!! factorial of a negative number doesn't exist");

	printf("fact = %d",fact);
}
