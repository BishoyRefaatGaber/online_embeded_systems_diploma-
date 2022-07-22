//c program to store information of a student


#include "stdio.h"

struct student{
	char Name[20];
	int roll_num;
	float mark;
};

void main(){
	struct student Sstudents[10];
	printf("Enter information of student \n");
	for(int i=0;i<10;i++){
		printf("Enter name %d : ",i+1);
		fflush(stdin);fflush(stdout);
		scanf("%s",Sstudents[i].Name);
		printf("Enter roll number %d : ",i+1);
		fflush(stdin);fflush(stdout);
		scanf("%d",&Sstudents[i].roll_num);
		printf("Enter mark %d : ",i+1);
		fflush(stdin);fflush(stdout);
		scanf("%f",&Sstudents[i].mark);
	}
        printf("Students data\n");
	for(int i=0;i<10;i++){
		printf("name %d : %s\n",i+1,Sstudents[i].Name);
		printf("Roll number %d : %d\n",i+1,Sstudents[i].roll_num);
		printf("Mark %d : %.2f\n",i+1,Sstudents[i].mark);
		printf("##################################\n");
	}
}
