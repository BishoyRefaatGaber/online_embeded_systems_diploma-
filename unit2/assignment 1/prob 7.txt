//Write Source Code to Swap Two Numbers without temp variable.


#include "stdio.h"
void  main(){
	float a,b;
	printf("Enter value of a:");
	fflush(stdin);fflush(stdout);
	scanf("%f",&a);
	printf("Enter value of b:");
	fflush(stdin);fflush(stdout);
	scanf("%f",&b);
	a=a+b;
	b=a-b;
	a=a-b;
	printf("After swapping, value of a = %.2f\n",a);
	printf("After swapping, value of a = %.2f\n",b);
}



//
////Write Source Code to Swap Two Numbers without temp variable.
//
//
//#include "stdio.h"
//void  main(){
//	int a,b;
//	printf("Enter value of a:");
//	fflush(stdin);fflush(stdout);
//	scanf("%d",&a);
//	printf("Enter value of b:");
//	fflush(stdin);fflush(stdout);
//	scanf("%d",&b);
//	a ^= b;
//	b ^= a;
//	a ^= b;
//	printf("After swapping, value of a = %d\n",a);
//	printf("After swapping, value of a = %d\n",b);
//}
//
//
//
//
