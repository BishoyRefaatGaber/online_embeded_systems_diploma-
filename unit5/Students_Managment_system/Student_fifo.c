#include "Student_fifo.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
DATA *arr[S_LEN];
S_FIFO ptr;

void init (){
	ptr.BASE = arr;
	ptr.HEAD = arr;
	ptr.LENGTH = S_LEN;
	ptr.COUNT = 0;
}



STATUS add_student_file(char *path){
	int i,j;
	char tok[256];
	FILE *fp;
	fp = fopen(path,"r");
	if (!fp){
		PRINTF("FILE COULD NOt BE FOUND");
		return FILE_ERROR;
	}
	fgets(tok,256,fp);
	char *token;
	for(i = 0;i<8;i++){
		switch (i){
		case 0 :
			token = strtok(tok," ");
			strcpy(ptr.HEAD->fname,token);
			break;
		case 1:
			token = strtok(NULL," ");
			strcpy(ptr.HEAD->lname,token);
			break;
		case 2:
			token = strtok(NULL," ");
			ptr.HEAD->roll = atoi(token);
			break;
		case 3:
			token = strtok(NULL," ");
			ptr.HEAD->GPA = atof(token);
			break;

		case 4:
			token = strtok(NULL," ");
			ptr.HEAD->cid[0] = atoi(token);
			break;
		case 5:
			token = strtok(NULL," ");
			ptr.HEAD->cid[1] = atoi(token);
			break;
		case 6:
			token = strtok(NULL," ");
			ptr.HEAD->cid[2] = atoi(token);
			break;
		case 7:
			token = strtok(NULL," ");
			ptr.HEAD->cid[3] = atoi(token);
			break;

		}
	}

	fclose(fp);
	for (i=0 ; i < ptr.COUNT ; i++){
		if (ptr.HEAD->roll == (ptr.BASE+i)->roll){
			PRINTF("Roll number used before so file rejected\n");
			PRINTF("=========================\n");
			return FILE_ERROR;
		}
	}
	for (i=0 ; i < 4 ; i++){
		for(j=0;j<i;j++){
			if(ptr.HEAD->cid[i] == ptr.HEAD->cid[j]){
				PRINTF("Subject ID : %d used twice so file rejected\n",ptr.HEAD->cid[i]);
				PRINTF("=========================\n");
				return FILE_ERROR;
			}
		}
	}
	if(!(ptr.HEAD->GPA >= 0 && ptr.HEAD->GPA <= 4)){
		PRINTF("GPA isn't between 0 and 4 used before so file rejected\n");
		PRINTF("=========================\n");
		return FILE_ERROR;
	}
	ptr.HEAD++;
	ptr.COUNT++;
	return No_ERROR;
}


STATUS add_student_manually(){
	if(!ptr.HEAD || !ptr.BASE){
		PRINTF("LIST IS NULL\n");
		return null;
	}

	if(ptr.COUNT == ptr.LENGTH){
		PRINTF("LIST IS FULL\n");
		return FULL;
	}
	int i,j;
	PRINTF("Enter student number %d data ",ptr.COUNT+1);
	PRINTF("Roll : ");
	scanf("%d",&ptr.HEAD->roll);
	roll_check(ptr.HEAD->roll);
	PRINTF("First name : ");
	gets(ptr.HEAD->fname);
	PRINTF("Last name : ");
	gets(ptr.HEAD->lname);
	PRINTF("GPA : ");
	while(1){
		scanf("%f",&ptr.HEAD->GPA);
		if(ptr.HEAD->GPA >= 0 && ptr.HEAD->GPA <= 4){
			break;
		}
		else {
			PRINTF("GPA IS REJECTED\n");
			PRINTF("GPA : ");
		}
	}
	PRINTF("SUBJECTS\n");
	PRINTF("Math 12\n");
	PRINTF("Field 14\n");
	PRINTF("Physics 16\n");
	PRINTF("Circuits 18\n");
	PRINTF("Electronics 20\n");
	PRINTF("Microcontroler_Architecture 22\n");
	int c;
	for(i = 0 ; i < 4 ; i++){
		while(1){
			PRINTF("SUB %d : ",i+1);
			scanf("%d",&ptr.HEAD->cid[i]);
			if(ptr.HEAD->cid[i] == 12 || ptr.HEAD->cid[i] == 14 || ptr.HEAD->cid[i] == 16 || ptr.HEAD->cid[i] == 18 || ptr.HEAD->cid[i] == 20 || ptr.HEAD->cid[i] == 22){
				for(c=0;c<i;c++){
					if(ptr.HEAD->cid[i] == ptr.BASE->cid[c]){
						PRINTF("SUBJECT PICKED BEFORE\n");
						PRINTF("=========================\n");
						break;

					}

				}
				if(c == i){break;}
			}
			else{
				PRINTF("SUBJECT ID DOES NOT EXIST\n");
			}
		}
	}
	ptr.HEAD++;
	ptr.COUNT++;
	return No_ERROR;
}


STATUS find_rl(int roll){
	if(!ptr.HEAD || !ptr.BASE){
		PRINTF("LIST IS NULL\n");
		return null;
	}
	if(!ptr.COUNT){
		PRINTF("LIST IS EMPTY\n");
		return EMPTY;
	}
	int i,j ;
	for (i=0 ; i < ptr.COUNT ; i++){
		if (roll == (ptr.BASE+i)->roll){
			PRINTF("Roll number : %d\n",(ptr.BASE+i)->roll);
			PRINTF("Name : %s %s\n",(ptr.BASE+i)->fname,(ptr.BASE+i)->lname);
			PRINTF("Total GPA : %f\n",(ptr.BASE+i)->GPA);
			PRINTF("Subjects ID : \n");
			for(j = 0 ; j < 4 ; j++){
				PRINTF("  %d",(ptr.BASE+i)->cid[j]);
			}
			PRINTF("\n");
			return No_ERROR;
		}
	}
	PRINTF("Roll number not found\n");
	return No_ERROR;
}



STATUS find_fn(char *fname){
	if(!ptr.HEAD || !ptr.BASE){
		PRINTF("LIST IS NULL\n");
		return null;
	}
	if(!ptr.COUNT){
		PRINTF("LIST IS EMPTY\n");
		return EMPTY;
	}
	int i,j ;
	for (i=0 ; i < ptr.COUNT ; i++){
		if (!strcmp(fname,(ptr.BASE+i)->fname)){
			PRINTF("==========================\n");
			PRINTF("=======Student Data=======\n");
			PRINTF("Name : %s %s\n",(ptr.BASE+i)->fname,(ptr.BASE+i)->lname);
			PRINTF("Roll number : %d\n",(ptr.BASE+i)->roll);
			PRINTF("Total GPA : %f\n",(ptr.BASE+i)->GPA);
			PRINTF("Subjects ID : \n");
			for(j = 0 ; j < 4 ; j++){
				PRINTF("  %d",(ptr.BASE+i)->cid[j]);
			}
			PRINTF("\n");
			return No_ERROR;
		}
	}
	PRINTF("Name not found\n");
	return No_ERROR;
}



STATUS find_c(int SUBID){
	if(!ptr.HEAD || !ptr.BASE){
		PRINTF("LIST IS NULL\n");
		return null;
	}
	if(!ptr.COUNT){
		PRINTF("LIST IS EMPTY\n");
		return EMPTY;
	}
	int i,j,n,c = 0 ;
	for (i=0 ; i < ptr.COUNT ; i++){
		for (j=0 ; j < 4 ; j++){
			if (SUBID == (ptr.BASE+i)->cid[j]){
				c++;
				PRINTF("==========================\n");
				PRINTF("=======Student Data=======\n");
				PRINTF("Name : %s %s\n",(ptr.BASE+i)->fname,(ptr.BASE+i)->lname);
				PRINTF("Roll number : %d\n",(ptr.BASE+i)->roll);
				PRINTF("Total GPA : %f\n",(ptr.BASE+i)->GPA);
				PRINTF("Subjects ID : ");
				for(n = 0 ; n < 4 ; n++){
					PRINTF("  %d",(ptr.BASE+i)->cid[n]);
				}
				PRINTF("\n");
			}
		}
	}
	PRINTF("\n\t\t\t**Total number of students : %d**\n",c);
	return No_ERROR;
}



STATUS tot_s(){
	if(!ptr.HEAD || !ptr.BASE){
		PRINTF("LIST IS NULL\n");
		return null;
	}
	if(!ptr.COUNT){
		PRINTF("LIST IS EMPTY\n");
		return EMPTY;
	}
	PRINTF("Total number of students : %d\n",ptr.COUNT);
	return No_ERROR;
}


STATUS del_s(){
	if(!ptr.HEAD || !ptr.BASE){
		PRINTF("LIST IS NULL\n");
		return null;
	}
	if(!ptr.COUNT){
		PRINTF("LIST IS EMPTY\n");
		return EMPTY;
	}
	int roll_del;
	PRINTF("Enter roll number you need to delete\n");
	scanf("%d",&roll_del);
	int i,j,c ;
	for (i=0 ; i < ptr.COUNT ; i++){
		if (roll_del ==(ptr.BASE+i)->roll){
			for(j=i;j<(ptr.COUNT-1);j++){
				(ptr.BASE+j)->roll = (ptr.BASE+j+1)->roll;
				(ptr.BASE+j)->GPA = (ptr.BASE+j+1)->GPA;
				strcpy((ptr.BASE+j)->fname , (ptr.BASE+j+1)->fname);
				strcpy((ptr.BASE+j)->lname , (ptr.BASE+j+1)->lname);
				for(c=0;c<4;c++){
					(ptr.BASE+j)->cid[c] = (ptr.BASE+j+1)->cid[c];
				}
			}
			break;
		}
	}
	if(i == ptr.COUNT ){
		PRINTF("ROLL NUMBER NOT FOUND\n");
		return No_ERROR;
	}
	ptr.HEAD--;
	ptr.COUNT--;
	return No_ERROR;
}


STATUS up_s(int roll){
	if(!ptr.HEAD || !ptr.BASE){
		PRINTF("LIST IS NULL\n");
		return null;
	}
	if(!ptr.COUNT){
		PRINTF("LIST IS EMPTY\n");
		return EMPTY;
	}

	int i,choose,j ;
	for (i=0 ; i < ptr.COUNT ; i++){
		if (roll == (ptr.BASE+i)->roll){
			PRINTF("Which data you need to modify ??\n");
			PRINTF("1 : Name\n");
			PRINTF("2 : Roll number\n");
			PRINTF("3 : Total GPA\n");
			PRINTF("4 : Subjects ID\n");
			scanf("%d",&choose);
			switch (choose){
			case 1:
				PRINTF("First name : ");
				gets((ptr.BASE+i)->fname);
				PRINTF("Last name : ");
				gets((ptr.BASE+i)->lname);
				break;
			case 2:
				int j;
				PRINTF("Roll : ");
				scanf("%d",&(ptr.BASE+i)->roll);
				while (1){
						for (j=0 ; j < ptr.COUNT ; j++){
							if(i == j){continue;}
							if (ptr.BASE+i == (ptr.BASE+j)->roll){
								PRINTF("Roll number used before \n");
								PRINTF("=========================\n");
								break;
							}
						}
						if(j == ptr.COUNT){
							break;
						}
						PRINTF("Roll : ");
						scanf("%d",&(ptr.HEAD->roll));
						roll = ptr.HEAD->roll;

					}
				break;
			case 3:
				PRINTF("GPA : ");
				scanf("%d",&(ptr.BASE+i)->GPA);
				break;
			case 4:
				PRINTF("SUBJECTS\n");
				PRINTF("Math 12\n");
				PRINTF("Field 14\n");
				PRINTF("Physics 16\n");
				PRINTF("Circuits 18\n");
				PRINTF("Electronics 20\n");
				PRINTF("Microcontroler_Architecture 22\n");
				for(j = 0 ; j < 4 ; j++){
					PRINTF("SUB %d : ",j+1);
					scanf("%d",&(ptr.BASE+i)->cid[j]);
				}
			}

			PRINTF("\n");
			return No_ERROR;
		}
	}
	if(i == ptr.COUNT){
		PRINTF("ROLL NUMBER NOT FOUND\n");
	}
	return No_ERROR;
}


STATUS show_s(){
	if(!ptr.HEAD || !ptr.BASE){
		PRINTF("LIST IS NULL\n");
		return null;
	}
	if(!ptr.COUNT){
		PRINTF("LIST IS EMPTY\n");
		return EMPTY;
	}
	int i,n;
	PRINTF("==========================\n");
	for (i=0 ; i < ptr.COUNT ; i++){
		PRINTF("=======Student Data=======\n");
		PRINTF("Name : %s ",(ptr.BASE+i)->fname);
		PRINTF("%s\n",(ptr.BASE+i)->lname);
		PRINTF("Roll number : %d\n",(ptr.BASE+i)->roll);
		PRINTF("Total GPA : %f\n",(ptr.BASE+i)->GPA);
		PRINTF("Subjects ID : ");
		for(n = 0 ; n < 4 ; n++){
			PRINTF("  %d",(ptr.BASE+i)->cid[n]);
		}
		PRINTF("\n");
	}
	PRINTF("\n\t\t\t**Total number of students : %d**\n",ptr.COUNT);
	return No_ERROR;
}




void roll_check(int roll){
	int i ;

	while (1){
		for (i=0 ; i < ptr.COUNT ; i++){
			if (roll == (ptr.BASE+i)->roll){
				PRINTF("Roll number used before \n");
				PRINTF("=========================\n");
				break;
			}
		}
		if(i == ptr.COUNT){
			break;
		}
		PRINTF("Roll : ");
		scanf("%d",&(ptr.HEAD->roll));
		roll = ptr.HEAD->roll;

	}
}




