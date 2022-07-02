/*
strings assignment
*/


//c program to find the frequency of a character in a string

#include "stdio.h"
#include "string.h"

void main(){
	char s[20],c;
	int m=0;
	printf("enter a string");
	fflush(stdin);fflush(stdout);
	gets(s);
	printf("enter a character to find frequency");
	fflush(stdin);fflush(stdout);
	scanf("%c",&c);
	for(int i=0;i<=strlen(s);i++){
		if (c==s[i])m++;
	}
	printf("frequency of %c = %d",c,m);




}


