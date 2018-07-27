#include "head.h"
int **map;

void findOriLoc(int num,int loc[2]){
	if(num!=0){
		if(num%col!=0){
			loc[0]=num/col;
			loc[1]=num%col-1;
		}else{
			loc[0]=num/col-1;
			loc[1]=col-1;
		}
	}else{
		loc[0]=row-1;
		loc[1]=col-1;
	}
}

int findOriNum(int loc[2]){
	if(!(loc[0]==row-1&&loc[1]==col-1)){
		return loc[0]*col+loc[1]+1;
	}else{
		return 0;
	}
}

int findHeadNum(){
	int i,j;
	int OriLoc[2];
	for(i=0;i<row;i++){
		for(j=0;j<col;j++){
			if(map[i][j]){
				findOriLoc(mat[i][j],OriLoc);
				if(!(OriLoc[0]==i&&OriLoc[1]==j)){
					map[i][j]=0;
					return mat[i][j];
				}else{
					map[i][j]=0;
				}
			}
		}
	}
	return -1;
}

int judge(){
	int flag;
	int i,j;
	int currentNum,headNum;
	int oriLoc[2];
	int zeroLoc[2];
	int cycle[row*col/2],circleNum=0;
	map=calloc(col*row,sizeof(int));
	for(i=0;i<row;i++){
		*(map+i)=calloc(col,sizeof(int));
	}
	
	for(i=0;i<row;i++){
		for(j=0;j<col;j++){
			map[i][j]=1;
		}
	}
	
	while((headNum=currentNum=findHeadNum())+1){
		for(i=0;;i++){
			findOriLoc(currentNum,oriLoc);
			if(headNum==mat[oriLoc[0]][oriLoc[1]]){
				break;
			}
			map[oriLoc[0]][oriLoc[1]]=0;
			currentNum=mat[oriLoc[0]][oriLoc[1]];
		}
		cycle[circleNum++]=i+1;
	}
	
	for(i=0,j=0;i<circleNum;i++){
		if(cycle[i]%2==0){
			j++;
		}
	}
	
	flag=j%2==0;
	findLoc(0,zeroLoc);
	if((row-1-zeroLoc[0]+col-1-zeroLoc[1])%2!=0){
		flag=!flag;
	}
	return flag;
}

int finish(){
	int i,j;
	for(i=0;i<row;i++){
		for(j=0;j<col;j++){
			if(i==row-1&&j==col-1){
				if(mat[i][j]!=0){
					return 0;
				}
			}else{
				if(mat[i][j]!=col*i+j+1){
					return 0;
				}
			}
		}
	}
	return 1;
}

