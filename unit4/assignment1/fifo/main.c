#include "fifo.h"
int main(){
	FIFO_BUFF MY_ITEM;
	FIFO_DATA_TYPE TYPE;
	OPERATION operation;
while(1){
	PRINTF("ENTER OPERATION\n");
	PRINTF("%d : INITALIZE\n",INITALIZE);
	PRINTF("%d : PUSH_ITEM\n",PUSH_ITEM);
	PRINTF("%d : POP_ITEM\n",POP_ITEM);
	PRINTF("%d : PRINTF_ITEMS\n",PRINTF_ITEMS);
	scanf("%d",&operation);

	/*TYPE=STRING;*/
	/*initialize lifo array*/

    switch (operation){
    case  INITALIZE :
        PRINTF("ENTER THE FIFO DATA TYPE\n");
        PRINTF("%d : INTEGER\n",INTEGER);
        PRINTF("%d : FLOAT_POINT\n",FLOAT_POINT);
        PRINTF("%d : CHARACTER\n",CHARACTER);
        PRINTF("%d : STRING\n",STRING);
        scanf("%d",&TYPE);
        switch (TYPE){
        case INTEGER :
            int BUFF_int[FIFO_LENGTH];
            init( &MY_ITEM,BUFF_int,FIFO_LENGTH,TYPE);
            break;
        case FLOAT_POINT :
            float BUFF_float[FIFO_LENGTH];
            init( &MY_ITEM,BUFF_float,FIFO_LENGTH,TYPE);
            break;
        case CHARACTER :
            char BUFF_char[FIFO_LENGTH];
            init( &MY_ITEM,BUFF_char,FIFO_LENGTH,TYPE);
            break;
        case STRING :
            char BUFF_string[FIFO_LENGTH][STRING_LENGTH];
            init( &MY_ITEM,BUFF_string,FIFO_LENGTH,TYPE);
            break;
        }
        break;
        case PUSH_ITEM :
            Push(&MY_ITEM,TYPE);
            break;
        case POP_ITEM :
            POP(&MY_ITEM,TYPE);
            break;
        case PRINTF_ITEMS :
            print(&MY_ITEM,TYPE);
            break;
    }
}
	return 0;
}
