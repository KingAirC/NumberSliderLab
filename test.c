#include "head.h"

void test(){
	char oper;
	int i,j;
	init();
	
	while(1){
		system("cls");
		print();
		scanf("%c",&oper);
		if(oper=='i'){
			init();
		}else if(oper=='e'){
			break;
		}else if(oper=='p'){
			printf("please input two numbers:\n");
			scanf("%d%d",&i,&j);
			if((i<0||i>row*col-1)||(j<0||j>row*col-1)){
				MessageBox(NULL,TEXT("out of bound!"),TEXT("error"),0);
			}else{
				swapNum(i,j);
			}
		}
		operat(oper);
	}
}

