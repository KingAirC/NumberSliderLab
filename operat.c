#include "head.h"

void init(){
	int i,j;
	for(i=0;i<row;i++){
		for(j=0;j<col;j++){
			mat[i][j]=col*i+j+1; 
		}
	}
	mat[row-1][col-1]=0;
}

void print(){
	int i,j;
	for(i=0;i<row;i++){
		for(j=0;j<col;j++){
			if(mat[i][j]==0){
				printf("\t");
			}else{
				printf("%d\t",mat[i][j]);
			}
		}
		printf("\n\n");
	}
	printf("\n");
}

void findLoc(int num,int loc[2]){
	int i,j;
	for(i=0;i<row;i++){
		for(j=0;j<col;j++){
			if(num==mat[i][j]){
				loc[0]=i;
				loc[1]=j;
				return ;
			}
		}
	}
}

void swapNum(int num1,int num2){
	int loc1[2];
	int loc2[2];
	int t;
	findLoc(num1,loc1);
	findLoc(num2,loc2);
	t=mat[loc1[0]][loc1[1]];
	mat[loc1[0]][loc1[1]]=mat[loc2[0]][loc2[1]];
	mat[loc2[0]][loc2[1]]=t;
}

void operat(char dir){
	int i,j;
	int zeroLoc[2];
	findLoc(0,zeroLoc);
	switch(dir){
		case 'w':{
			if(zeroLoc[0]<row-1){
				i=zeroLoc[0]+1;
				j=zeroLoc[1];
				swapNum(0,mat[i][j]);
			}
			break;
		}
		case 's':{
			if(zeroLoc[0]>0){
				i=zeroLoc[0]-1;
				j=zeroLoc[1];
				swapNum(0,mat[i][j]);
			}
			break;
		}
		case 'a':{
			if(zeroLoc[1]<col-1){
				i=zeroLoc[0];
				j=zeroLoc[1]+1;
				swapNum(0,mat[i][j]);
			}
			break;
		}
		case 'd':{
			if(zeroLoc[1]>0){
				i=zeroLoc[0];
				j=zeroLoc[1]-1;
				swapNum(0,mat[i][j]);
			}
			break;
		}
		default:{
			
			break;
		}
	}
}

void operatZero(char dir){
	switch(dir){
		case 'U':
		case 'w':{
			operat('s');
			printf("s"); 
			break;
		}
		case 'D':
		case 's':{
			operat('w');
			printf("w");
			break;
		}
		case 'L':
		case 'a':{
			operat('d');
			printf("d");
			break;
		}
		case 'R':
		case 'd':{
			operat('a');
			printf("a");
			break;
		}
	}
}
