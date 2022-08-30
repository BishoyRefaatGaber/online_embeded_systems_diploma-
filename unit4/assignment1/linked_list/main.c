#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "conio.h"
#define PRINTF(...)  {fflush(stdin);fflush(stdout);\
		printf(__VA_ARGS__);\
		fflush(stdin);fflush(stdout);}


//data of the student
struct S_DATA{
	int ID;
	char NAME[40];
	float HEIGHT;
};

// packet
struct S_STUDENT{
	struct S_DATA Student;
	struct S_STUDENT *pSNextStudent;
};

struct S_STUDENT *gpFirstStudent = NULL;
void ADD_STUDENT (){
	char temp[40];
	struct S_STUDENT *NewtStudent; //pointer points to no thing (wild pointer)
	struct S_STUDENT *LastStudent;  //pointer points to no thing (wild pointer)
	if (!gpFirstStudent){
		NewtStudent = (struct S_STUDENT*)malloc(sizeof(struct S_STUDENT));//now it points to a new location of data
		gpFirstStudent = NewtStudent;

	}
	/*if it enters to else that means that
	gpFirstStudent->Student equal the data ,
	gpFirstStudent->pSNextStudent points to the next element*/
	else {
		LastStudent = gpFirstStudent;
		while (LastStudent->pSNextStudent){
			LastStudent=LastStudent->pSNextStudent;
		}
		NewtStudent = (struct S_STUDENT*)malloc(sizeof(struct S_STUDENT));

		//LastStudent->pSNextStudent enters the last *pSNextStudent and makes it equal NewtStudent
		LastStudent->pSNextStudent = NewtStudent;
	}
	PRINTF("Enter the ID : \n");
	gets(temp);
	NewtStudent->Student.ID = atoi(temp);

	PRINTF("Enter the name : \n");
	gets(NewtStudent->Student.NAME);

	PRINTF("Enter the heigth : \n");
	gets(temp);
	NewtStudent->Student.HEIGHT = atof(temp);
	NewtStudent->pSNextStudent = NULL;
}

void Delete_Student(){
	char temp[40];
	unsigned int id_temp;
	PRINTF("\n============================\n");
	PRINTF("Enter the ID to be deleted");
	gets(temp);
	id_temp = atoi(temp);
	if(gpFirstStudent){
		struct S_STUDENT *pSelected_Student = gpFirstStudent;
		struct S_STUDENT *pPreviousStudent = NULL;
		while(pSelected_Student){
			if(pSelected_Student->Student.ID == id_temp){
				if(gpFirstStudent->Student.ID == pSelected_Student->Student.ID){
					gpFirstStudent = gpFirstStudent->pSNextStudent;
					free(pSelected_Student);
				}
				else if(pSelected_Student->pSNextStudent == NULL){
					pPreviousStudent->pSNextStudent = NULL;
					free(pSelected_Student);
				}
				else{
					pPreviousStudent->pSNextStudent = pSelected_Student->pSNextStudent;
					free(pSelected_Student);
				}
			}
			else {
				pPreviousStudent = pSelected_Student;
				pSelected_Student = pSelected_Student->pSNextStudent;
			}
		}
	}
}
void PRINT_STUDENTS(){
	struct S_STUDENT *Current_Student;
	Current_Student = gpFirstStudent;
	int counter = 0;
	PRINTF("\n=======The list elements=======\n");
	while(Current_Student){
		PRINTF("\tElement number : %d\n",counter+1);
		PRINTF("The student name : %s\n",Current_Student->Student.NAME);
		PRINTF("The student ID : %d\n",Current_Student->Student.ID);
		PRINTF("The student height : %f\n",Current_Student->Student.HEIGHT);
		PRINTF("\n============================\n");
		Current_Student = Current_Student->pSNextStudent;
		counter++;
	}
}
void Delete_All(){
	struct S_STUDENT *Current_Student,*element_to_free;
	Current_Student = gpFirstStudent;
	while(Current_Student){
		element_to_free = Current_Student;
		Current_Student = Current_Student->pSNextStudent;
		free(element_to_free);
	}
}
void Nth_Node(struct S_STUDENT *Student){
	int count = 0,index;
	PRINTF("\nEnter the index needed");
	scanf("%d",&index);
	struct S_STUDENT * IndexedStudent = Student;
	while(IndexedStudent){
		if(count == index){
			PRINTF("\n===============Student Data=============\n");
			PRINTF("The student name : %s\n",IndexedStudent->Student.NAME);
			PRINTF("The student ID : %d\n",IndexedStudent->Student.ID);
			PRINTF("The student height : %f\n",IndexedStudent->Student.HEIGHT);
			PRINTF("\n============================\n");
		}
		count++;
		IndexedStudent = IndexedStudent->pSNextStudent;
	}
}

int NodesNumber(struct S_STUDENT *Student){
	if(!Student)return 0;
	else return 1+NodesNumber(Student->pSNextStudent);
}
/*


 */

void Nth_Node_Reversed(struct S_STUDENT *Student){
	int count = 0,index;
	PRINTF("\nEnter the reversed index needed");
	scanf("%d",&index);
	struct S_STUDENT * FrontStudent = Student;
	struct S_STUDENT * BackStudent = Student;
	while(FrontStudent){
		if(count >= index+1){
			BackStudent = BackStudent->pSNextStudent;
		}
		FrontStudent = FrontStudent->pSNextStudent;
		count++;
	}
	PRINTF("\n===============Student Data=============\n");
	PRINTF("The student name : %s\n",BackStudent->Student.NAME);
	PRINTF("The student ID : %d\n",BackStudent->Student.ID);
	PRINTF("The student height : %f\n",BackStudent->Student.HEIGHT);
	PRINTF("\n============================\n");
}



void Reverse_List(){
	struct S_STUDENT *Current;
	struct S_STUDENT *Prevous;
	struct S_STUDENT *Next;
	Prevous = gpFirstStudent;
	Current = Prevous->pSNextStudent;
	Prevous->pSNextStudent = NULL;
	while(Current){
		Next = Current->pSNextStudent;
		Current->pSNextStudent = Prevous;
		Prevous = Current;
		Current = Next;
	}
	gpFirstStudent = Prevous;
}

void List_Middle(){
	struct S_STUDENT *Fast = gpFirstStudent ;
	struct S_STUDENT *Slow = gpFirstStudent ;
	unsigned int count = 0;

	while(Fast->pSNextStudent)
	{
		Fast = Fast->pSNextStudent;
		Fast = Fast->pSNextStudent;
		Slow = Slow->pSNextStudent;
		count++;
	}
	PRINTF("\n===============Student Data %d=============\n",count);
	PRINTF("The student name : %s\n",Slow->Student.NAME);
	PRINTF("The student ID : %d\n",Slow->Student.ID);
	PRINTF("The student height : %f\n",Slow->Student.HEIGHT);
	PRINTF("\n============================\n");

}



int main(){
	unsigned int num;
	while(1){
	PRINTF("=====Choose some=====\n");
	PRINTF("1 : ADD STUDENT\n");
	PRINTF("2 : Delete Student\n");
	PRINTF("3 : PRINT STUDENTS\n");
	PRINTF("4 : Delete All\n");
	PRINTF("5 : Nth Node\n");
	PRINTF("6 : Nodes Number\n");
	PRINTF("7 : Nth Node Reversed\n");
	PRINTF("8 : Reverse List\n");
	PRINTF("9 : List Middle\n");
	scanf("%d",&num);
	switch (num){
	case 1:
		ADD_STUDENT ();
		break;
	case 2:
		Delete_Student();
			break;
	case 3:
		PRINT_STUDENTS();
			break;
	case 4:
		Delete_All();
			break;
	case 5:
		Nth_Node(gpFirstStudent);
			break;
	case 6:
		int c;
		 c = NodesNumber(gpFirstStudent);
		 printf("Nodes number = %d\n",c);
			break;
	case 7:
		Nth_Node_Reversed(gpFirstStudent);
			break;
	case 8:
		Reverse_List();
			break;
	case 9:
		List_Middle();
			break;
	default : printf("Invalid choice");
	}
	}

	return 0;
}

