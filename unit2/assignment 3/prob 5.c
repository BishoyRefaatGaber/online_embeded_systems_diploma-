//c program to search an element in an array

#include "stdio.h"

void main(){
	int x;
	printf("enter number the of elements");
	fflush(stdin);fflush(stdout);
	scanf("%d",&x);
	printf("enter the elements");
	fflush(stdin);fflush(stdout);
	float arr[100],m;
	for(int i=0;i<x;i++){
		scanf("%f",&arr[i]);
	}
	printf("enter the number to be searched");
	fflush(stdin);fflush(stdout);
	scanf("%f",&m);
	for(int i=0;i<=x;i++){
		if (i==x)printf("the number is not found");
		else if (arr[i]==m){
			printf("number found at location %d\n",i+1);
			break;

		}

	}
}



