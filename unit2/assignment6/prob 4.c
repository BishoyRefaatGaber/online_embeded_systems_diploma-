/* Write a program in C to print the elements of an array in reverse order. */


#include "stdio.h"

int main(){
    int arr[5]={1,2,3,4,5},*ptr;
    ptr=&arr[4];
    int i=4;
    for(;i>=0;i--){
    	printf("element - %d : %d \n",5-i,*ptr);
    	ptr--;
    }

    return 0;
}
