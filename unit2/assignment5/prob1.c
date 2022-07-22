//c program to store information of a student


#include "stdio.h"

struct Sstudent{
	char Name[20];
	int roll_num;
	float mark;
}student1;

void main(){
	printf("Enter information of student");
	fflush(stdin);fflush(stdout);
	scanf("%s",student1.Name);
	scanf("%d",&student1.roll_num);
	scanf("%f",&student1.mark);

	printf("name  : %s\n",student1.Name);
	printf("Roll  : %d\n",student1.roll_num);
	printf("Marks : %.3f\n",student1.mark);
}
