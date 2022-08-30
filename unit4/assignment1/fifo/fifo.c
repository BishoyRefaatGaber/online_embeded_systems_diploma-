#include "fifo.h"


FIFO_STATUS print(FIFO_BUFF *MY_ITEM,FIFO_DATA_TYPE TYPE){

	if (MY_ITEM->COUNT == 0){


		return FIFO_EMPTY;}
	int i;
	switch (TYPE){
	case INTEGER :
		printf("==============================================\n");
		printf("INTEGERS NUMBERS IN FIFO\n");
		for(i=0;i<MY_ITEM->COUNT;i++){
			printf("%d\n",*(int*)(MY_ITEM->TAIL+i*sizeof(int)));
		}
		printf("==============================================\n");
		break;
	case FLOAT_POINT :
		printf("==============================================\n");
		printf("FLOAT NUMBERS IN FIFO\n");
		for(i=0;i<MY_ITEM->COUNT;i++){
			printf("%f\n",*(float*)(MY_ITEM->TAIL+i*sizeof(float)));
		}
		printf("==============================================\n");
		break;
	case CHARACTER :
		printf("==============================================\n");
		printf("CHARACTERS IN LIFO\n");
		for(i=0;i<MY_ITEM->COUNT;i++){
			printf("%c\n",*(char*)(MY_ITEM->TAIL+i*sizeof(char)));
		}
		printf("==============================================\n");
		break;
	case STRING :
		printf("==============================================\n");
		printf("STRINGS IN LIFO\n");
		for(i=0;i<MY_ITEM->COUNT;i++){
			printf("%s\n",(MY_ITEM->TAIL_STR)+i);
		}
		printf("==============================================\n");
		break;
	}
	return FIFO_NO_ERROR;

}

FIFO_STATUS POP(FIFO_BUFF *MY_ITEM,FIFO_DATA_TYPE TYPE){
	/*check if  lifo  is null*/
	switch (TYPE){
	case INTEGER :
	case FLOAT_POINT :
	case CHARACTER :
		if (!MY_ITEM->HEAD || !MY_ITEM->BASE || !MY_ITEM->TAIL)
			return FIFO_NULL;
		break;
	case STRING :
		if (!MY_ITEM->HEAD_STR || !MY_ITEM->BASE_STR  || !MY_ITEM->TAIL_STR)
			return FIFO_NULL;
		break;
	}
	/*check if lifo is empty*/

	if (MY_ITEM->COUNT == 0)
		return FIFO_EMPTY;
	/*pop item*/
	switch (TYPE){
	MY_ITEM->COUNT--;
	case INTEGER :
		if(MY_ITEM->TAIL == (MY_ITEM->BASE + MY_ITEM->LENGTH * sizeof(int))){
			MY_ITEM->TAIL=MY_ITEM->BASE;
		}
		else{
			MY_ITEM->TAIL+=sizeof(int);

		}
		break;
	case FLOAT_POINT :
		if(MY_ITEM->TAIL == (MY_ITEM->BASE + MY_ITEM->LENGTH * sizeof(float))){
			MY_ITEM->TAIL=MY_ITEM->BASE;
		}
		else{
			MY_ITEM->TAIL+=sizeof(float);

		}
		break;
	case CHARACTER :
		if(MY_ITEM->TAIL == (MY_ITEM->BASE + MY_ITEM->LENGTH * sizeof(char))){
			MY_ITEM->TAIL=MY_ITEM->BASE;
		}
		else{
			MY_ITEM->TAIL+=sizeof(char);

		}
		break;
	case STRING :
		if(MY_ITEM->TAIL == (MY_ITEM->BASE + MY_ITEM->LENGTH * STRING_LENGTH)){
			MY_ITEM->TAIL_STR=MY_ITEM->BASE;
		}
		else{
			MY_ITEM->TAIL_STR++;

		}
		break;

	}
	printf("ITEM POPED\n");
	return FIFO_NO_ERROR;

};
FIFO_STATUS Push(FIFO_BUFF *MY_ITEM,FIFO_DATA_TYPE TYPE){
	/*check if  lifo  is null*/
	switch (TYPE){
	case INTEGER :
	case FLOAT_POINT :
	case CHARACTER :
		FIFO_IS_FULL (&MY_ITEM,TYPE);
		break;
	case STRING :
		FIFO_IS_FULL (&MY_ITEM,TYPE);
		break;
	}

	/*add item to lifo*/
	PRINTF("ENTER YOUR ITEM\n");
	switch (TYPE){
	case INTEGER :
		int item_int;
		scanf("%d",&item_int);
		*(int*)(MY_ITEM->HEAD)=item_int;
		MY_ITEM->COUNT++;
		if(MY_ITEM->HEAD == (MY_ITEM->BASE + MY_ITEM->LENGTH * sizeof(int))){
			MY_ITEM->HEAD=MY_ITEM->BASE;
		}
		else{
			MY_ITEM->HEAD+=sizeof(int);

		}
		break;
	case FLOAT_POINT :
		float item_float;
		scanf("%f",&item_float);
		*(float*)(MY_ITEM->HEAD)=item_float;
		MY_ITEM->COUNT++;

		if(MY_ITEM->HEAD == (MY_ITEM->BASE + MY_ITEM->LENGTH * sizeof(float))){
			MY_ITEM->HEAD=MY_ITEM->BASE;
		}
		else{
			MY_ITEM->HEAD+=sizeof(float);
		}break;
	case CHARACTER :
		char item_char;
		scanf("%c",&item_char);
		*(char*)(MY_ITEM->HEAD)=item_char;
		MY_ITEM->COUNT++;

		if(MY_ITEM->HEAD == (MY_ITEM->BASE + MY_ITEM->LENGTH * sizeof(char))){
			MY_ITEM->HEAD=MY_ITEM->BASE;
		}
		else{
			MY_ITEM->HEAD+=sizeof(char);
		}
		break;
	case STRING :
		char item_string[FIFO_LENGTH][STRING_LENGTH];
		scanf("%s",&item_string);
		strcpy(MY_ITEM->HEAD_STR,item_string);
		MY_ITEM->COUNT++;

		if(MY_ITEM->HEAD == (MY_ITEM->BASE + MY_ITEM->LENGTH *STRING_LENGTH)){
			MY_ITEM->HEAD_STR=MY_ITEM->BASE;

		}
		else{
			MY_ITEM->HEAD_STR++;
		}
		break;
	}

	return FIFO_NO_ERROR;
};
FIFO_STATUS FIFO_IS_FULL (FIFO_BUFF *MY_ITEM,FIFO_DATA_TYPE TYPE){
	switch (TYPE){
	case INTEGER :
	case FLOAT_POINT :
	case CHARACTER :
		if(!MY_ITEM->BASE || !MY_ITEM->HEAD || !MY_ITEM->TAIL)
			return FIFO_NULL;
		break;
	case STRING :
		if(!MY_ITEM->BASE || !MY_ITEM->HEAD_STR || !MY_ITEM->TAIL_STR)
			return FIFO_NULL;
		break;
		switch (TYPE){
		case INTEGER :
		case FLOAT_POINT :
		case CHARACTER :
		case STRING :
			if(MY_ITEM->COUNT == MY_ITEM->LENGTH)
				return FIFO_FULL;
			break;


			return FIFO_NO_ERROR;
		};
	};
};
FIFO_STATUS init(FIFO_BUFF *MY_ITEM,void * BUFF,unsigned int length,FIFO_DATA_TYPE TYPE){
	if(BUFF == NULL)
		return FIFO_NULL;

	switch (TYPE){
	case INTEGER :
		MY_ITEM->BASE = (int*)BUFF;
		MY_ITEM->HEAD = (int*)BUFF;
		MY_ITEM->TAIL = (int*)BUFF;
		MY_ITEM->COUNT = 0;
		MY_ITEM->LENGTH = length;
		break;
	case FLOAT_POINT :
		MY_ITEM->BASE = (float*) BUFF;
		MY_ITEM->HEAD = (float*)BUFF;
		MY_ITEM->TAIL = (float*)BUFF;
		MY_ITEM->COUNT = 0;
		MY_ITEM->LENGTH = length;
		break;
	case CHARACTER :
		MY_ITEM->BASE = (char*)BUFF;
		MY_ITEM->HEAD = (char*)BUFF;
		MY_ITEM->TAIL = (char*)BUFF;
		MY_ITEM->COUNT = 0;
		MY_ITEM->LENGTH = length;
		break;
	case STRING :
		MY_ITEM->BASE_STR = BUFF;
		MY_ITEM->HEAD_STR = BUFF;
		MY_ITEM->TAIL_STR = BUFF;
		MY_ITEM->COUNT = 0;
		MY_ITEM->LENGTH = length;
		break;
	};

	printf("FIFO IS INITIALIZED\n");
	return FIFO_NO_ERROR;

};
