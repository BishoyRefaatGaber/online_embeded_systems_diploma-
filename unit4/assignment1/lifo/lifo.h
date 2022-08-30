#ifndef LIFO_H_
#define LIFO_H_
#include "stdio.h"
#include "string.h"
#define LIFO_LENGTH  5
#define STRING_LENGTH 30

#define PRINTF(...) {fflush(stdin);fflush(stdout);\
	                 printf(__VA_ARGS__);\
	                 fflush(stdin);fflush(stdout);}
typedef enum {
	LIFO_NO_ERROR,   /*0*/
	LIFO_EMPTY,     /*1*/
	LIFO_FULL,     /*2*/
	LIFO_NULL     /*3*/
}LIFO_STATUS;

typedef enum{
    INITALIZE,
    PUSH_ITEM,
    POP_ITEM,
    PRINTF_ITEMS
}OPERATION;

typedef enum{
	INTEGER,         /*0*/
	FLOAT_POINT,    /*1*/
	CHARACTER,     /*2*/
	STRING        /*3*/
}LIFO_DATA_TYPE;

typedef struct{
	unsigned int LENGTH;
	void *HEAD;
	unsigned int COUNT;
	void *BASE;
	char (*BASE_STR)[STRING_LENGTH];
	char (*HEAD_STR)[STRING_LENGTH];
}LIFO_BUFF;

LIFO_STATUS POP(LIFO_BUFF *MY_ITEM,LIFO_DATA_TYPE TYPE);
LIFO_STATUS Push(LIFO_BUFF *MY_ITEM,LIFO_DATA_TYPE TYPE);
LIFO_STATUS init(LIFO_BUFF *MY_ITEM,void * BUFF,unsigned int length,LIFO_DATA_TYPE TYPE);
LIFO_STATUS print(LIFO_BUFF *MY_ITEM,LIFO_DATA_TYPE TYPE);

#endif
