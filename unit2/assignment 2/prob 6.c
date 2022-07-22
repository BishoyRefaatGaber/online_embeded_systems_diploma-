//c program to sum the numbers untill number entered by the user

#include "stdio.h"
void  main(){
	int a,sum=0;
	printf("Enter an integer :");
	fflush(stdin);fflush(stdout);
	scanf("%d",&a);
	for(int i=1;i<=a;i++){
		sum+=i;
	}
	printf("sum = %d",sum);
}
