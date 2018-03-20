#ifndef __FOUR_H
#define __FOUR_H

#include<iostream>
#include<vector>
#include<ctime>
#include<stdio.h>
#include<cmath>
#include<assert.h>
#include <regex> 
#include<string> 

using namespace std;

//难度系数
typedef enum
{
	NORMAL,
	HARD,
	NIGHTMARE,
	INFERNO
}Level;

//四则运算
typedef enum
{
	NOTHING,
	ADD,
	SUB,
	MUL,
	DIV,
	USED
}Sym;




//1、算式类
template<class T>
class MyEquation 
{
public:
	MyEquation(T * valL, Sym * symL, int valNum, int * bL, int * bR, int bN);
	void printEqu(bool showAnswer=false);
	T autoCalSingle(T * valL, Sym * symL, int valNum);
	T autoCal(T * valL, Sym * symL, int valNum, int * bracketL, int * bracketR, int bn);

	bool errorOccur;
	T userAns;

	string retEqu()
	{
		return eStr;
	}

	T retAns()
	{
		return answer;
	}
private:
	T * valList;
	Sym * symList;
	int valueNum;
	int * bracketL;
	int * bracketR;
	int bn;
	
	string eStr;
	T answer;

};

//2、主类
class MyFour
{
public:
	//设置表题量，难度
	MyFour(int num, int level)
	{
		assert(num <= 100 && num>0);
		Fnum = num;
		FIntNum = 0;
		//Ftable = (MyEquation<T>*)malloc(sizeof(MyEquation<T>)*num);

		assert(level >= 0 && level < 4);
		Flevel = (Level)level;
		srand((unsigned)time(NULL));
	};
	//void getSetting();//修改设置

	void generate();//生成题目与答案
	void printTable(bool showAnswer=false);
	void MyFour::printError(bool showAnswer = true);

	
	//string retAnEqu();
	

	//设置表：题量，难度
	int Fnum;
	Level Flevel;
	
	//算式表
	int FIntNum;
	vector<MyEquation<int>> FtableInt;
	vector<MyEquation<float>> FtableFloat;

	//捕获用户操作并记录

	//时间表

	//错题表

	//评价表

};


#define random(a,b) (rand() % ((b) - (a) + 1) + (a))
#define MaxEntryNum 5


#endif