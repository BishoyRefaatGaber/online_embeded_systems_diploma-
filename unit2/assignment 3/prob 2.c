//c program to calculate the average using an array

#include "stdio.h"

void main(){
	int x;
	float avg=0;
	printf("enter the number of elements");
	fflush(stdin);fflush(stdout);
	scanf("%d",&x);
	float arr[x];
	printf("enter the data");
	fflush(stdin);fflush(stdout);
	for (int i=0;i<x;i++){scanf("%f",&arr[i]);}
	for (int i=0;i<x;i++){ avg+=arr[i];}

	avg/=(float)x;
	printf("average= %f",avg);

}


