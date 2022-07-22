//c program to area of a circle


#include "stdio.h"
#define pi 3.1415922654

void main(){
	float r;
	printf("Enter the radius : ");
	fflush(stdout);
	scanf("%f",&r);
	printf("Area = %.3f",pi*r*r);

}
