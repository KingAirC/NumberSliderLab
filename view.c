#include "head.h"
void view(char *file){
	double num,numBuffer;
	double avgTime=0,avgMemory=0,avgStep=0;
	double maxTime=0,maxMemory=0,maxStep=0;
	double minTime=9999,minMemory=9999,minStep=9999;
	char del;
	char cmd[11];
	int i,j;
	system("cls");
	printf("%d * %d layer number slide\n",row,col);
	printf("time\tmemory\tsteps\n");
	
	FILE *fp=fopen(file,"r");
	if(fp!=NULL){
		fseek(fp,0,0);
		i=0;
		while(!feof(fp)){
			fscanf(fp,"%lf",&num);
			printf("%.2lf\t",num);
			i++;
			if(i%3==0){
				printf("\n");
				avgStep+=num;
				if(num>maxStep){
					maxStep=num;
				}
				if(num<minStep){
					minStep=num;
				}
			}else if(i%3==1){
				avgTime+=num;
			}else{
				avgMemory+=num;
				if(num>maxMemory){
					maxMemory=num;
				}
				if(num<minMemory){
					minMemory=num;
				}
			}
		}
		avgStep/=((i-1)/3);
		avgTime-=num;
		avgTime/=((i-1)/3);
		avgMemory/=((i-1)/3);
		
		fseek(fp,0,0);
		
		for(j=1;j<i-1;j++){
			fscanf(fp,"%lf",&numBuffer);
			if(j%3==1){
				num=numBuffer;
				if(num>maxTime){
					maxTime=num;
				}
				if(num<minTime){
					minTime=num;
				}
			}
		}
		
		fscanf(fp,"%f",&num);
		
		printf("\r*****************\n");
		printf("average:\n%.2f\t%.2f\t%.2f\n",avgTime,avgMemory,avgStep);
		printf("max:\n%.2f\t%.2f\t%.2f\n",maxTime,maxMemory,maxStep);
		printf("min:\n%.2f\t%.2f\t%.2f\n",minTime,minMemory,minStep);
		fclose(fp);
		printf("\nif you press 'd',the programme can delet all the record!\n");
		getchar();
		scanf("%c",&del);
		if(del=='d'){
			sprintf(cmd,"del %cp%c.xls",48+row,48+col);
			system(cmd);
		}
		system("pause");
	}else{
		MessageBox(NULL,TEXT("You have never chosen this mode or the file was deleted!"),TEXT("error"),0);
	}
}
