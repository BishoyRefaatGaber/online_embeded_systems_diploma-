//c program to insert an element in an array

#include "stdio.h"

void main(){
	int x,y;
	printf("enter the number of elements");
	fflush(stdin);fflush(stdout);
	scanf("%d",&x);
	float arr[x+5],m;
	for(int i=1;i<=x;i++){
		arr[i-1]=i;
	}
	printf("enter the element to be inserted");
	fflush(stdin);fflush(stdout);
	scanf("%f",&m);
	printf("enter the location");
	fflush(stdin);fflush(stdout);
	scanf("%d",&y);
	for(int i=x;i>=y;i--){
		arr[i]=arr[i-1];
	}
	x++;
	arr[y-1]=m;
	for(int i=0;i<x;i++){
		printf("%.2f  ",arr[i]);
	}
}


