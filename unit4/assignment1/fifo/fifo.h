#ifndef FIFO_H_
#define FIFO_H_
#include "stdio.h"
#include "string.h"
#define FIFO_LENGTH  5
#define STRING_LENGTH 30

#define PRINTF(...) {fflush(stdin);fflush(stdout);\
	                 printf(__VA_ARGS__);\
	                 fflush(stdin);fflush(stdout);}
typedef enum {
	FIFO_NO_ERROR,   /*0*/
	FIFO_EMPTY,     /*1*/
	FIFO_FULL,     /*2*/
	FIFO_NULL     /*3*/
}FIFO_STATUS;

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
}FIFO_DATA_TYPE;

typedef struct{
	unsigned int LENGTH;
	void *HEAD;
	unsigned int COUNT;
	void *TAIL;
	void *BASE;
	char (*TAIL_STR)[STRING_LENGTH];
	char (*BASE_STR)[STRING_LENGTH];
	char (*HEAD_STR)[STRING_LENGTH];
}FIFO_BUFF;

FIFO_STATUS POP(FIFO_BUFF *MY_ITEM,FIFO_DATA_TYPE TYPE);
FIFO_STATUS Push(FIFO_BUFF *MY_ITEM,FIFO_DATA_TYPE TYPE);
FIFO_STATUS init(FIFO_BUFF *MY_ITEM,void * BUFF,unsigned int length,FIFO_DATA_TYPE TYPE);
FIFO_STATUS print(FIFO_BUFF *MY_ITEM,FIFO_DATA_TYPE TYPE);
FIFO_STATUS FIFO_IS_FULL (FIFO_BUFF *MY_ITEM,FIFO_DATA_TYPE TYPE);
#endif
