#include "head.h"

int **Map;

char * findRoad(POINT begin,POINT end){
	char *road;
	int i,j;
	int num=0;
	int currentX,currentY;
	int deap=row+col,width=(int)pow(4,(row+col));
	int found=0;
	
	Node ***node;
    node=(Node ***)malloc(deap*sizeof(Node**));
	for(i=0;i<deap;i++){
		node[i]=(Node**)malloc(width*sizeof(Node *));
	}
	
	
	for(i=0;i<deap;i++){
		for(j=0;j<width;j++){
			
			node[i][j]=NULL;
		}
	}
	
	node[0][0]=malloc(sizeof(Node));
	node[0][0]->dir='\0';
	node[0][0]->father=NULL;
	node[0][0]->point.x=begin.x;
	node[0][0]->point.y=begin.y;
	
	for(i=0;i<deap;i++){
		num=0;
		for(j=0;node[i][j]!=NULL;j++){
			currentX=node[i][j]->point.x;
			currentY=node[i][j]->point.y;
			if(currentY!=col-1&&Map[currentX][currentY+1]){
				node[i+1][num]=malloc(sizeof(Node));
				node[i+1][num]->dir='R';
				node[i+1][num]->father=node[i][j];
				node[i+1][num]->point.x=currentX;
				node[i+1][num]->point.y=currentY+1;
	
				if(currentX==end.x&&currentY+1==end.y){
					found=1;
					goto aim;
				}
				num++;
			}
			if(currentY!=0&&Map[currentX][currentY-1]){
				node[i+1][num]=malloc(sizeof(Node));
				node[i+1][num]->dir='L';
				node[i+1][num]->father=node[i][j];
				node[i+1][num]->point.x=currentX;
				node[i+1][num]->point.y=currentY-1;
	
				if(currentX==end.x&&currentY-1==end.y){
					found=1;
					goto aim;
				}
				num++;
			}
			if(currentX!=0&&Map[currentX-1][currentY]){
				node[i+1][num]=malloc(sizeof(Node));
				node[i+1][num]->dir='U';
				node[i+1][num]->father=node[i][j];
				node[i+1][num]->point.x=currentX-1;
				node[i+1][num]->point.y=currentY;
		
				if(currentX-1==end.x&&currentY==end.y){
					found=1;
					goto aim;
				}
				num++;
			}
			if(currentX!=row-1&&Map[currentX+1][currentY]){
				node[i+1][num]=malloc(sizeof(Node));
				node[i+1][num]->dir='D';
				node[i+1][num]->father=node[i][j];
				node[i+1][num]->point.x=currentX+1;
				node[i+1][num]->point.y=currentY;
	
				if(currentX+1==end.x&&currentY==end.y){
					found=1;
					goto aim;
				}
				num++;
			}
		}
		aim:
			if(found==1){
				break;
			}
	}
	road=calloc(i+2,sizeof(char));
	Node *currentNode=node[i+1][num];
	for(j=0;currentNode->dir!='\0';j++){
		road[i-j]=currentNode->dir;
		currentNode=currentNode->father;
	}
	road[i+1]='\0';
	
	return road;
}

void zeroTo(int loc[2]){
	int zeroLoc[2];
	char *road;
	int i;
	findLoc(0,zeroLoc);
	POINT begin={zeroLoc[0],zeroLoc[1]};
	POINT end={loc[0],loc[1]};
	
	road=findRoad(begin,end);
	for(i=0;road[i]!='\0';i++){
		operatZero(road[i]);
	}
}

void getNextLoc(POINT point,char dir,int loc[2]){
	switch(dir){
		case 'U':
		case 'w':{
			loc[0]=point.x-1;
			loc[1]=point.y;
			break;
		}
		case 'D':
		case 's':{
			loc[0]=point.x+1;
			loc[1]=point.y;
			break;
		}
		case 'L':
		case 'a':{
			loc[0]=point.x;
			loc[1]=point.y-1;
			break;
		}
		case 'R':
		case 'd':{
			loc[0]=point.x;
			loc[1]=point.y+1;
			break;
		}
	}
}

void finishN(int n){
	int locN[2];
	int locOriN[2];
	char *road;
	int nextLoc[2];
	
	findLoc(n,locN);
	findOriLoc(n,locOriN);
	
	POINT begin={locN[0],locN[1]};
	POINT end={locOriN[0],locOriN[1]};
	
	road=findRoad(begin,end);
	getNextLoc(begin,road[0],nextLoc);
	
	if(locN[0]==locOriN[0]&&locN[1]==locOriN[1]){
		Map[locN[0]][locN[1]]=0;
		return ;
	}else{
		Map[locN[0]][locN[1]]=0;
		zeroTo(nextLoc);
		Map[locN[0]][locN[1]]=1;
		zeroTo(locN);
		finishN(n);
	}
	
}

void NTo(int n,int loc[2]){
	int Nloc[2];
	char *road;
	int nextLoc[2];
	
	findLoc(n,Nloc);
	
	POINT begin={Nloc[0],Nloc[1]};
	POINT end={loc[0],loc[1]};
	
	road=findRoad(begin,end);
	getNextLoc(begin,road[0],nextLoc);
	
	if(Nloc[0]==loc[0]&&Nloc[1]==loc[1]){
		
		return ;
	}else{
		Map[Nloc[0]][Nloc[1]]=0;
		zeroTo(nextLoc);
		Map[Nloc[0]][Nloc[1]]=1;
		zeroTo(Nloc);
		NTo(n,loc);
	}
}

void finishLine(int line){
	int i,j=0;
	int loc[2];
	int OriLoc[2];
	int loc2[2];
	
	for(i=line;j<col-1;){
		for(j=0;j<col-1;j++){
			loc[0]=i;
			loc[1]=j;
			if(mat[i][j]!=findOriNum(loc)){
				finishN(findOriNum(loc));
			}
		}
	}
	loc[0]=line+1;
	loc[1]=col-3;
	OriLoc[0]=line;
	OriLoc[1]=col-1;
	loc2[0]=line;
	loc2[1]=col-1;
	
	if(mat[line][col-1]!=findOriNum(OriLoc)){
		if(mat[line+1][col-3]!=findOriNum(OriLoc)){
			NTo(findOriNum(OriLoc),loc);
			Map[loc[0]][loc[1]]=0;
			zeroTo(loc2);
			Map[loc[0]][loc[1]]=1;
			swapNum(0,mat[loc[0]][loc[1]]);
			printf("wddsawasddw");
		}else{
			Map[loc[0]][loc[1]]=0;
			zeroTo(loc2);
			Map[loc[0]][loc[1]]=1;
			swapNum(0,mat[loc[0]][loc[1]]);
			printf("wddsawasddw");
		}
	}
	Map[line][col-1]=0;
	printf("\n");
}

void finishUp(){
	int i;
	for(i=0;i<row-2;i++){
		finishLine(i);
	}
}

void finishTwo(int colum){
	
	int loc1[2]={row-2,colum};
	int loc2[2]={row-1,colum};
	int loc3[2]={row-2,colum+2};
	int loc4[2]={row-1,colum+2};
	
	if(mat[loc1[0]][loc1[1]]!=findOriNum(loc1)){
		if(mat[loc4[0]][loc4[1]]!=findOriNum(loc1)){
			NTo(findOriNum(loc1),loc4);
			Map[loc4[0]][loc4[1]]=0;
			zeroTo(loc1);
			Map[loc4[0]][loc4[1]]=1;
			swapNum(0,mat[loc4[0]][loc4[1]]);
			printf("waasdwdsaaw");
		}else{
			Map[loc4[0]][loc4[1]]=0;
			zeroTo(loc1);
			Map[loc4[0]][loc4[1]]=1;
			swapNum(0,mat[loc4[0]][loc4[1]]);
			printf("waasdwdsaaw");
		}
	}
	Map[loc1[0]][loc1[1]]=0;
	
	if(mat[loc2[0]][loc2[1]]!=findOriNum(loc2)){
		if(mat[loc3[0]][loc3[1]]!=findOriNum(loc2)){
			NTo(findOriNum(loc2),loc3);
			Map[loc3[0]][loc3[1]]=0;
			zeroTo(loc2);
			Map[loc3[0]][loc3[1]]=1;
			swapNum(0,mat[loc3[0]][loc3[1]]);
			printf("saawdsdwaas");
		}else{
			Map[loc3[0]][loc3[1]]=0;
			zeroTo(loc2);
			Map[loc3[0]][loc3[1]]=1;
			swapNum(0,mat[loc3[0]][loc3[1]]);
			printf("saawdsdwaas");
		}
	}
	Map[loc2[0]][loc2[1]]=0;
	
}

void finishAlmost(){
	int i;
	for(i=0;i<col-2;i++){
		finishTwo(i);
	}
}

void finish2minus2(){
	int loc[2]={row-1,col-1};
	int loc2[2]={row-2,col-2};
	zeroTo(loc);
	while(mat[row-2][col-2]!=findOriNum(loc2)){
		operatZero('L');
		operatZero('U');
		operatZero('R');
		operatZero('D');
	}
}

void solve(){
	
	int i,j;
	
	Map=calloc(col*row,sizeof(int));
	for(i=0;i<row;i++){
		*(Map+i)=calloc(col,sizeof(int));
	}
	for(i=0;i<row;i++){
		for(j=0;j<col;j++){
			Map[i][j]=1;
		}
	}
	
	if(row>2&&col>2){
		finishUp();
		finishAlmost();
		finish2minus2();
	}else if(row==2&&col!=2){
		finishAlmost();
		finish2minus2();
	}else if(col==2&&row!=2){
		finishUp();
		finish2minus2();
	}else{
		finish2minus2();
	}
	system("pause");
}

