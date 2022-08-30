#include "lifo.h"


LIFO_STATUS print(LIFO_BUFF *MY_ITEM,LIFO_DATA_TYPE TYPE){
	if (MY_ITEM->COUNT == 0)
		return LIFO_EMPTY;
	int i;
	switch (TYPE){
	case INTEGER :
		printf("==============================================\n");
		printf("INTEGERS NUMBERS IN LIFO\n");
		for(i=1;i<=MY_ITEM->COUNT;i++){
			printf("%d\n",*(int*)(MY_ITEM->HEAD-i*sizeof(int)));
		}
		printf("==============================================\n");
		break;
	case FLOAT_POINT :
		printf("==============================================\n");
		printf("FLOAT NUMBERS IN LIFO\n");
		for(i=1;i<=MY_ITEM->COUNT;i++){
			printf("%f\n",*(float*)(MY_ITEM->HEAD-i*sizeof(float)));
		}
		printf("==============================================\n");
		break;
	case CHARACTER :
		printf("==============================================\n");
		printf("CHARACTERS IN LIFO\n");
		for(i=1;i<=MY_ITEM->COUNT;i++){
			printf("%c\n",*(char*)(MY_ITEM->HEAD-i*sizeof(char)));
		}
		printf("==============================================\n");
		break;
	case STRING :
		printf("==============================================\n");
		printf("STRINGS IN LIFO\n");
		for(i=1;i<=MY_ITEM->COUNT;i++){
			printf("%s\n",MY_ITEM->HEAD_STR-i);
		}
		printf("==============================================\n");
		break;
	}
	return LIFO_NO_ERROR;

}

LIFO_STATUS POP(LIFO_BUFF *MY_ITEM,LIFO_DATA_TYPE TYPE){
	/*check if  lifo  is null*/
	switch (TYPE){
	case INTEGER :
	case FLOAT_POINT :
	case CHARACTER :
		if (!MY_ITEM->HEAD || !MY_ITEM->BASE)
			return LIFO_NULL;
		break;
	case STRING :
		if (!MY_ITEM->HEAD_STR || !MY_ITEM->BASE_STR)
			return LIFO_NULL;
		break;
	}
	/*check if lifo is empty*/

	if (MY_ITEM->COUNT == 0)
		return LIFO_EMPTY;

	/*pop item*/
	switch (TYPE){
		MY_ITEM->COUNT--;
	case INTEGER :
		MY_ITEM->HEAD-=sizeof(int);
		break;
	case FLOAT_POINT :
		MY_ITEM->HEAD-=sizeof(float);
		break;
	case CHARACTER :
		MY_ITEM->HEAD-=sizeof(char);
		break;
	case STRING :
		MY_ITEM->HEAD_STR--;
		break;
	}
	printf("ITEM POPED\n");
	return LIFO_NO_ERROR;

};
LIFO_STATUS Push(LIFO_BUFF *MY_ITEM,LIFO_DATA_TYPE TYPE){
	/*check if  lifo  is null*/
	switch (TYPE){
	case INTEGER :
	case FLOAT_POINT :
	case CHARACTER :
		if (!MY_ITEM->HEAD || !MY_ITEM->BASE)
			return LIFO_NULL;
		break;
	case STRING :
		if (!MY_ITEM->HEAD_STR || !MY_ITEM->BASE_STR)
			return LIFO_NULL;
		break;
	}

	/*check if lifo is full*/
	if (MY_ITEM->COUNT == MY_ITEM->LENGTH)
		return LIFO_FULL;


	/*add item to lifo*/
	PRINTF("ENTER YOUR ITEM\n");
	switch (TYPE){
	case INTEGER :
		int item_int;
		scanf("%d",&item_int);
		*(int*)(MY_ITEM->HEAD)=item_int;
		MY_ITEM->COUNT++;
		MY_ITEM->HEAD+=sizeof(int);
		break;
	case FLOAT_POINT :
		float item_float;
		scanf("%f",&item_float);
		*(float*)(MY_ITEM->HEAD)=item_float;
		MY_ITEM->COUNT++;
		MY_ITEM->HEAD+=sizeof(float);
		break;
	case CHARACTER :
		char item_char;
		scanf("%c",&item_char);
		*(char*)(MY_ITEM->HEAD)=item_char;
		MY_ITEM->COUNT++;
		MY_ITEM->HEAD+=sizeof(char);
		break;
	case STRING :
		char item_string[LIFO_LENGTH][STRING_LENGTH];
		scanf("%s",&item_string);
		strcpy(MY_ITEM->HEAD_STR,item_string);
		MY_ITEM->COUNT++;
		MY_ITEM->HEAD_STR++;
		break;
	}

	return LIFO_NO_ERROR;
};
LIFO_STATUS init(LIFO_BUFF *MY_ITEM,void * BUFF,unsigned int length,LIFO_DATA_TYPE TYPE){
	if(BUFF == NULL)return LIFO_NULL;
	switch (TYPE){
	case INTEGER :
		MY_ITEM->BASE = (int*)BUFF;
		MY_ITEM->HEAD = (int*)BUFF;
		MY_ITEM->COUNT = 0;
		MY_ITEM->LENGTH = length;
		break;
	case FLOAT_POINT :
		MY_ITEM->BASE = (float*) BUFF;
		MY_ITEM->HEAD = (float*)BUFF;
		MY_ITEM->COUNT = 0;
		MY_ITEM->LENGTH = length;
		break;
	case CHARACTER :
		MY_ITEM->BASE = (char*)BUFF;
		MY_ITEM->HEAD = (char*)BUFF;
		MY_ITEM->COUNT = 0;
		MY_ITEM->LENGTH = length;
		break;
	case STRING :
		MY_ITEM->BASE_STR = BUFF;
		MY_ITEM->HEAD_STR = BUFF;
		MY_ITEM->COUNT = 0;
		MY_ITEM->LENGTH = length;

		break;
	}
	PRINTF("LIFO IS INITIALIZED\n");
	return LIFO_NO_ERROR;


};

