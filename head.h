#include "stdio.h"
#include "stdlib.h"
#include "malloc.h"
#include "time.h"
#include "windows.h"
#include "math.h"

int row;
int col;
int **mat;

typedef struct Node{
	char dir;
	POINT point;
	struct Node* father;
}Node;

int main();
void test();
void init();
void print();
void findLoc(int num,int loc[2]);
void swapNum(int num1,int num2);
void operat(char dir);
void operatZero(char dir);
int judge();
void findOriLoc(int num,int loc[2]);
int findOriNum(int loc[2]);
int findHeadNum();
void scramb();
int finish();
void play();
void input();
void view(char *file);
void help();
void chooseFunction();
void solve();
char* findRoad(POINT begin,POINT end);
void zeroTo(int loc[2]);
void getNextLoc(POINT point,char dir,int loc[2]);
void finishN(int n);
void finishLine(int line);
void finishUp();
void NTo(int n,int loc[2]);
void finishTwo(int colum);
void finishAlmost();
