//c program to find the transpose of a matrix

#include "stdio.h"

void main(){
	int x,y;
	printf("enter the dimentions of the matrix");
	fflush(stdin);fflush(stdout);
	scanf("%d %d",&x,&y);
	float arr1[x][y],arr2[y][x];
	printf("enter the matrix");
	fflush(stdin);fflush(stdout);
	for(int i=0 ;i<x;i++){
		for(int j=0;j<y;j++){
			scanf("%f",&arr1[i][j]);
		}
	}
	for(int i=0 ;i<y;i++){
		for(int j=0;j<x;j++){
			arr2[i][j]=arr1[j][i];
		}
	}
	for(int i=0 ;i<y;i++){
		for(int j=0;j<x;j++){
			printf("%.1f\t",arr2[i][j]);
		}
		printf("\n");
	}
}



