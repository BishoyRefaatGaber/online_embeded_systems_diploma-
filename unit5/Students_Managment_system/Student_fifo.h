#ifndef STUDENT_FIFO_H_
#define STUDENT_FIFO_H_
#define S_LEN 100
#define PRINTF(...) {fflush(stdin);fflush(stdout);\
		printf(__VA_ARGS__);\
		fflush(stdin);fflush(stdout);}


typedef enum {
	No_ERROR,
	FULL,
	EMPTY,
	null,
	FILE_ERROR
}STATUS;

typedef enum{
	Math = 12,
	Field = 14,
	Physics = 16,
	Circuits = 18,
	Electronics = 20,
	Microcontroler_Architecture = 22
}SUBJECTS;
enum OPTIONS{
	Add_student_form_file = 1,
	Add_student_manually = 2,
	Find_student_by_role_number = 3,
	Find_student_by_name = 4,
	Find_student_by_subject = 5,
	Get_total_number_of_student = 6,
	Delete_student = 7,
	Update_data = 8,
	Show_all_students = 9,
	Exit = 10
};

typedef struct{
	char fname[20];
	char lname[20];
	int roll;
	float GPA;
	SUBJECTS cid[4];

}DATA;

typedef struct {
	int LENGTH;
	int COUNT;
	DATA *HEAD;
	DATA *BASE;
}S_FIFO;

STATUS add_student_file();
STATUS add_student_manually();
STATUS find_rl();
STATUS find_fn();
STATUS find_c();
STATUS tot_s();
STATUS del_s();
STATUS up_s();
STATUS show_s();

#endif /* STUDENT_FIFO_H_ */
