/*
arry assignment
*/

//c program to add two multidimentional array 2*2

#include "stdio.h"

void main(){
	float arr1[2][2],arr2[2][2],sum[2][2];
	printf("enter the elements of 1st matrix");
	fflush(stdin);fflush(stdout);
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			scanf("%f",&arr1[i][j]);
		}
	}
	printf("enter the elements of 2nd matrix");
	fflush(stdin);fflush(stdout);
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			scanf("%f",&arr2[i][j]);
		}
	}

	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			sum[i][j]=arr1[i][j]+arr2[i][j];
		}
	}

	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			printf("%.3f ",sum[i][j]);
		}
		printf("\n");
	}

}


