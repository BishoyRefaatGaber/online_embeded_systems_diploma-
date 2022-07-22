/* program in c to print a string in reverse using a pointer */


#include "stdio.h"
#include "string.h"
int main(){
    char str[]="w3resource",*ptr;
    ptr=&str[strlen(str)-1];
    int i=strlen(str)-1;
    for(;i>=0;i--){
    	printf("%c",*ptr);
    	ptr--;
    }

    return 0;
}
