//prime numbers between two intervals by making user-defined function


#include "stdio.h"

void prime (int x,int y){
	printf("prime numbers between %d and %d are : \n",x,y);
	for (int i=x;i<=y;i++){
		for (int j=2;j<=i;j++){
			if (j==i) {printf("%d\n",j);}
			else if (i%j==0){
				break;
			}

		}
	}
}

void main (){
	int first,second;
	printf("Enter two numbers (intervals) : \n");
	fflush(stdin);fflush(stdout);
	scanf("%d \n %d",&first,&second);
    prime(first,second);
}
