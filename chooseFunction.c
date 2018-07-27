#include "head.h"

void chooseFunction(){
	int i,j;
	char choose;
	char FileName[7];
	
inputagain:
	
	system("cls");
	printf("input the row and colum(>=2)\n");
	scanf("%d%d",&row,&col);
	if(row<2||col<2){
		MessageBox(NULL,"Out of Bound!please input again","error",0);
		goto inputagain;
	}
	srand(time(NULL));
	mat=calloc(col*row,sizeof(int));
	for(i=0;i<row;i++){
		*(mat+i)=calloc(col,sizeof(int));
	}
	
	while(1){
		system("cls");
		printf("choose a mode(%d * %d)\n",row,col);
		
		printf("1.play 2.test 3.input\n");
		printf("4.view 5.return 6.exit\n");
		printf("7.help\n");
		
		
		scanf("%c",&choose);
		switch(choose){
			case '1':{
				while(1){
					play();
				}
				break;
			}
			case '2':{
				test();
				break;
			}
			case '3':{
				input();
				break; 
			}
			case '4':{
				sprintf(FileName,"%cp%c.xls",48+row,48+col);
				view(FileName);
				
				break;
			}
			case '5':{
				chooseFunction();
			}
			case '6':{
				exit(0);
				break;
			}
			case '7':{
				help();
				break;
			}
			default:{
				
				break;
			}
		}
	}
}
