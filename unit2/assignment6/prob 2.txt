/* program in c to print all the alphabets using a pointer  . go to  the editor */


#include "stdio.h"

int main(){
   char alph [27],*alpha=&alph;
   int i=0;
   for (;i<26;i++){
	   *alpha='A'+i;
	   alpha++;
	   printf("%c  ",alph[i]);
   }


	return 0;
}
