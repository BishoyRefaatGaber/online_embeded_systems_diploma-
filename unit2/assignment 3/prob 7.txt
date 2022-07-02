//c program to find the length of a string

#include "stdio.h"
#include "string.h"

void main(){
	char s[20];
	int m=0;
	printf("enter a string");
	fflush(stdin);fflush(stdout);
	gets(s);

	for(int i=0;s[i]!='\0';++i){
		m++;
	}
	printf("length of %s = %d",s,m);




}

