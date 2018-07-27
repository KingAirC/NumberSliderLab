#include "head.h"
void play(){
	char oper;
	int times=0,begin,end,step=0;
	int pause=0,contin=0;
	char wait;
	double Time;
	char chTime[5],chStep[3],chtimes[3];
	char FileName[10];
	
	scramb();
	begin=clock();
	while(1){
		system("cls");
		print();
		scanf("%c",&oper);
		if(oper==10){
			times++;
		}else if(oper=='e'){
			chooseFunction();
		}else if(oper=='p'){
			pause=clock();
			system("cls");
			scanf("%c",&wait);
			while(wait!='c'){
				scanf("%c",&wait);
			}
			contin=clock();
			print();
		} 
		if(oper=='w'||oper=='a'||oper=='s'||oper=='d'){
			step++;
		}
		
		if(finish()){
			system("color d3");
			end=clock();
			Time=(double)(end-begin-(contin-pause))/1000;
			system("cls");
			
			printf("\n\n\n\t\t\t\tCongratulation!You win!\n");
			printf("\t\t\t\t\n\n\t\t\ttime:%.2lf seconds\n\t\t\tmemory:%d\n\t\t\tsteps:%d\n",Time,times,step);
			if(MessageBox(NULL,TEXT("Save or not?"),TEXT("Notice"),MB_YESNO)==IDYES){
				sprintf(FileName,"%cp%c.xls",48+row,48+col);
				FILE *fp=fopen(FileName,"a");
				fprintf(fp,"%.2lf\t%d\t%d\n",Time,times,step);
				
				fclose(fp);
			}
			system("pause");
			system("color 0f");
			return ;
		}
		operat(oper);
	}
}
