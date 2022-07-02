//c program to check vowel or consonant


#include "stdio.h"
void  main(){
	char a;
	printf("Enter an alphabet:");
	fflush(stdin);fflush(stdout);
	scanf("%c",&a);
	if (a=='a'||a=='A'||a=='i'||a=='I'||a=='o'||a=='O'||a=='u'||a=='U'||a=='e'||a=='E')printf("%c is vowel",a);
	else printf("%c is consonant",a);

}


