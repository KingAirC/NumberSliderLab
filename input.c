#include "head.h"

void input(){
	int i,j,k,l;
	int t[2]={-1,-1};
	char oper;
	system("cls");
	for(i=0;i<row;i++){
		for(j=0;j<col;j++){
			scanf("%d",&mat[i][j]);
			if(0<=mat[i][j]&&mat[i][j]<=row*col-1){
				for(k=0;k<i;k++){
					for(l=0;l<col;l++){
						if(mat[i][j]==mat[k][l]){
							MessageBox(NULL,"repeated!please input again","error",0);
							return ;
						}
					}
				}
				for(l=0;l<j;l++){
					if(mat[i][j]==mat[i][l]){
						MessageBox(NULL,"repeated!please input again","error",0);
						return ;
					}
				}
			}else{
				MessageBox(NULL,"Out of Bound!please input again","error",0);
				return ;
			}
		}
	}
	
	if(judge()){
		printf("yes\n");
		system("pause");
		while(1){
			system("cls");
			print();
			scanf("%c",&oper);
			if(oper=='e'){
				return ;
			}else if(oper=='i'){
				init();
			}else if(oper=='o'){
				solve();
			}
			operat(oper);
		}
	}else{
		MessageBox(NULL,"this situation can not be resolved","error",0);
	}
}
