#include "Student_fifo.h"
#include "stdio.h"
#include "string.h"
enum OPTIONS OP;
int main(){
	init ();
	while(1){
		PRINTF("Enter an option\n");
		PRINTF("1  : Add_student_form_file\n");
		PRINTF("2  : Add_student_manually\n");
		PRINTF("3  : Find_student_by_role_number\n");
		PRINTF("4  : Find_student_by_name\n");
		PRINTF("5  : Find_student_by_subject\n");
		PRINTF("6  : Get_total_number_of_student\n");
		PRINTF("7  : Delete_student\n");
		PRINTF("8  : Update_data\n");
		PRINTF("9  : Show_all_students\n");
		PRINTF("10 : Exit\n");
		scanf("%d",&OP);
		PRINTF("================================");
		PRINTF("================================");
		PRINTF("\n");
		PRINTF("\n");
		switch (OP){
		case 1:
			char path[100];
			PRINTF("FILE FORMAT : first_name	last_name	roll number		GPA		subject IDs\n");
			PRINTF("Enter the path of the file which must be in format\n");
			scanf("%s",path);
			add_student_file(path);
			break;
		case 2:
			add_student_manually();
			break;
		case 3:
			int roll;
			PRINTF("Enter roll number you need\n");
			scanf("%d",&roll);
			find_rl(roll);
			break;
		case 4:
			char fname[20];
			PRINTF("Enter first name you need\n");
			scanf("%s",&fname);
			find_fn(fname);
			break;
		case 5:
			int SUBID;
			PRINTF("Enter subject ID you need\n");
			while(1){
				scanf("%d",&SUBID);
				if(SUBID == 12 || SUBID == 14 || SUBID == 16 || SUBID == 18 || SUBID == 20 || SUBID == 22){
					break;
				}
			}
			find_c(SUBID);
			break;
		case 6:
			tot_s();
			break;
		case 7:
			del_s();
			break;
		case 8:
			int roll_up;
			PRINTF("Enter roll number you need\n");
			scanf("%d",&roll_up);
			up_s(roll_up);
			break;
		case 9:
			show_s();
			break;
		case 10:
			return 0;
		}
		PRINTF("======================================");
		PRINTF("======================================");
		PRINTF("\n");
		PRINTF("\n");
	}
	return 0;
}

