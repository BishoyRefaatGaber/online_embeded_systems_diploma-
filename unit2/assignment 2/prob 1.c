//write c program to check whether a number is even or odd


#include "stdio.h"
void  main(){
	int a;
	printf("Enter an integer you want to check:");
	fflush(stdin);fflush(stdout);
	scanf("%d",&a);
	if (a%2==0)printf("%d is even",a);
	else printf("%d is odd",a);

}


