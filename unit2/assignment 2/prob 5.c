//c program to check whether a character is an alphabet or not

#include "stdio.h"
void  main(){
	char a;
	printf("Enter a character:");
	fflush(stdin);fflush(stdout);
	scanf("%c",&a);
	if (a>='A'&& a<='z') printf("%c is an alphabet",a);
	else printf("%c is not an alphabet",a);
}


