#include "head.h"

void scramb(){
	
	int result[row*col];
	int i,j;
	srand(time(NULL));
	
	for(i=0;i<row*col;i++){
		while(1){
			result[i]=rand()%(row*col);
			for(j=0;j<i;j++){
				if(result[i]==result[j]){
					break;
				}
			}
			if(i==j){
				break;
			}
		}
	}
	
	for(i=0;i<row;i++){
		for(j=0;j<col;j++){
			mat[i][j]=result[col*i+j];
		}
	}
	
	if(!judge()){
		int t;
		if(mat[0][0]!=0){
			if(mat[0][1]!=0){
				t=mat[0][0];
				mat[0][0]=mat[0][1];
				mat[0][1]=t;
			}else{
				t=mat[1][0];
				mat[1][0]=mat[1][1];
				mat[1][1]=t;
			}
		}else{
			t=mat[1][0];
			mat[1][0]=mat[1][1];
			mat[1][1]=t;
		}
	}
	
}
