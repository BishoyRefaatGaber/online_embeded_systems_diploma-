/* Write a program in C to show a pointer to an array which contents are pointer to structure. */



#include "stdio.h"
struct emp
{
	char name[15];
	int id ;
};
int main(void)
{

	struct emp emp1={"Alex",1001};
	struct emp emp2={"Ali",1002};
	struct emp *ptr1=&emp1;
	struct emp *ptr2=&emp2;
	struct emp *(*arr[2])={ptr1,ptr2};
	struct emp *(*ptr)[2]=arr ;
	int i=0;
	for(;i<2;i++){
		printf("%s  %d\n",(*(*ptr+i))->name,(*(*ptr+i))->id);
	}
	return 0;
}
