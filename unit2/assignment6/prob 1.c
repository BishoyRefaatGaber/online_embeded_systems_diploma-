/* program in c to demonstrate how to handle the pointers in the program */


#include "stdio.h"

int main(){
    int m =29;
    printf("Address of m : %p\nValue of m : %d\n",&m,m);


    printf("\n\nNow ab is assigned with the address of m.");
    int * ab;
    ab=&m;
    printf("Address of m : %p\nValue of m : %d\n",&ab,*ab);


    printf("\n\nThe value of m assigned to 34 now.");
	m=34;
	printf("Address of m : %p\nValue of m : %d\n",&m,m);

	printf("\n\nThe pointer variable ab is assigned with the value 7 now.");
	*ab=7;
	printf("Address of m : %p\nValue of m : %d\n",&ab,*ab);

	return 0;
}
