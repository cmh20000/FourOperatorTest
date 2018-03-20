#include"Four.h"
//难度定义：
//1、normal：两位数以内，2-5项
//2、hard：两位数以内，带括号，2-5项
//3、nightmare：三位数以内，带括号，带小数
//4、inferno：微积分
/***************************最大公约数******************************/
int Mygcd(int p, int q)
{
	if (q == 0) return p;

	int r = p%q;
	return Mygcd(q, r);
}

/******************************归并排序*****************************/
template<typename T>
void merge(T a[], int p, int q, int r)
{
	int i, j, k, n1, n2;
	T * front, *back;

	n1 = q - p + 1;
	n2 = r - q;

	front = (T*)malloc(n1*sizeof(T));
	back = (T*)malloc(n2*sizeof(T));

	for (int i = 0; i < n1; i++)
	{
		front[i] = a[p + i];
	}
	for (int i = 0; i < n2; i++)
	{
		back[i] = a[q + i + 1];
	}
	//合并元素  
	i = 0, j = 0, k = p;
	while (i < n1 && j < n2)
	{
		if (front[i] < back[j])
		{
			a[k++] = front[i++];
		}
		else
		{
			a[k++] = back[j++];
		}
	}
	//将剩余的元素合并  
	while (i < n1)
	{
		a[k++] = front[i++];
	}
	while (j < n2)
	{
		a[k++] = back[j++];
	}
}

template<typename T>
void merge_sort(T a[], int p, int r)
{
	int q;
	if (p < r)
	{
		q = (p + r) / 2;
		merge_sort(a, p, q);
		merge_sort(a, q + 1, r);
		merge(a, p, q, r);
	}
}


/****************************自动计算*******************************/

//一、无括号式计算
template<class T>
T MyEquation<T>::autoCalSingle(T * valL, Sym * symL, int valNum)
{   //0、拷贝一份
	if (valNum == 1) return valL[0]; //防止大括号

	T * valList = (T *)malloc(sizeof(T)*valNum);
	Sym * symList = (Sym *)malloc(sizeof(T)*(valNum - 1));

	for (int i = 0; i < valNum; i++)
	{
		valList[i] = valL[i];
		if (i == valNum - 1) break;
		symList[i] = symL[i];
	}

	T valTemp;

	//1、计算乘除
	for (int i = 0; i < valNum-1; i++)
	{
		//1.1 周边计算	
		if (symList[i] == MUL)
		{
			valTemp = valList[i] * valList[i + 1];
			symList[i] = USED;
		}
		else if (symList[i] == DIV)
		{
			valTemp = valList[i] / valList[i + 1];
			symList[i] = USED;
		}
		else continue;
		//1.2 邻域更新
		int j = i;
		while (symList[j-1] == USED && j-1 >= 0) j--;
		valList[j] = valTemp;
		j = i;
		while (symList[j+1] == USED && j+1 < valNum) j++;
		valList[j+1] = valTemp;
	}

	//2、计算加减
	for (int i = 0; i < valNum - 1; i++)
	{
		//2.1 周边计算
		
		if (symList[i] == ADD)
		{
			valTemp = valList[i] + valList[i + 1];
			symList[i] = USED;
		}
		else if (symList[i] == SUB)
		{
			valTemp = valList[i] - valList[i + 1];
			symList[i] = USED;
		}
		else continue;

		//2.2 邻域更新
		int j = i ;
		while (symList[j-1] == USED && j-1 >=0) j--;
		valList[j] = valTemp;
		j = i;
		while (symList[j+1] == USED && j+1 < valNum) j++;
		valList[j+1] = valTemp;
	}

	return valTemp;
}

//二、括号分割与递归
template<class T>
T MyEquation<T>::autoCal(T * valL, Sym * symL, int valNum, int * bracketL, int * bracketR, int bn)
{
   //0、最好外部拷贝输入，否则递归代价太大

    //1、没有括号了
	if (bn == 0)  return autoCalSingle(valL, symL, valNum);
	
	//2、存在括号，提取第一个括号计算，更新4数组
	else
	{
		//2.1 找到这个括号
		bn--;
		int i=0;
		while (bracketR[i] < bracketL[bn] ) i++; 

		//2.2 中间的数拿去计算，并且填上位置	
		int tempNum = bracketR[i] - bracketL[bn]+1; //3-2+1=2个数
		T * tempVal = (T*)malloc(sizeof(T)*tempNum);
		Sym * tempSym = (Sym*)malloc(sizeof(Sym)*tempNum-1);
		for (int j = 0; j < tempNum; j++)
		{
			tempVal[j] = valL[bracketL[bn] - 1 + j]; 
			if (j == tempNum - 1) break;
			tempSym[j] = symL[bracketL[bn] - 1 + j];
		}
		valL[bracketL[bn]-1] = autoCalSingle(tempVal, tempSym, tempNum);

		//2.3 整理原val sym数组，就是后面的数据前行
		for (int j = bracketR[i]; j < valNum; j++)
		{
			valL[j - tempNum + 1] = valL[j];
			symL[j - tempNum] = symL[j-1];
		}
		//2.4 右括号往前移，同时要减位置数
		for (int j = i; j < bn; j++)
		{
			bracketR[j] = bracketR[j+1]-tempNum+1;
		}
		//2.5 继续下一层
		return autoCal(valL, symL, valNum-tempNum+1, bracketL, bracketR, bn);
	}

}


/*********************构造模块*************************************/

//三、构造算式
void MyFour::generate()
{
	int valueListInt[MaxEntryNum] = {0};
	float valueListFloat[MaxEntryNum] = { 0.0 };
	Sym symbolList[MaxEntryNum-1];
	int bracketL[MaxEntryNum / 2] = {0};
	int bracketR[MaxEntryNum / 2] = {0};
	int bn = 0;

	//0、难度选项与设置
	int maxNum;
	bool brackFlag,floatFlag;
	
	switch (Flevel)
	{
	case NORMAL: maxNum = 10; brackFlag = false; floatFlag = false; break;
	case HARD: maxNum = 100; brackFlag = true; floatFlag = false; break;
	case NIGHTMARE: maxNum = 1000; brackFlag = true; floatFlag = true; break;
	case INFERNO: maxNum = 10000; brackFlag = true; floatFlag = true; break;
	}


	for (int i = 0; i < Fnum; i++)
	{
		int intOrFloat = (floatFlag?random(0, 1):1); //表示此算式是Int还是Float

		//1、随机数产生n个项，并控制范围
		int n = random(2, MaxEntryNum);
		
		if (intOrFloat)
		{
			for (int j = 0; j < n; j++)
			{
				valueListInt[j] = (j < n ? random(-maxNum, maxNum) : 0);
			}
		}
		else
		{
			for (int j = 0; j < n; j++)
			{
				valueListFloat[j] = (j < n ? (random(-maxNum, maxNum)+random(0,99)*0.01) : 0.0);
			}
		}

		//2、随机产生n-1个链接符号
		for (int j = 0; j < MaxEntryNum-1; j++)
		{
			symbolList[j] = (j < n-1 ? (Sym)(random(1, 4)) : NOTHING);
			if (symbolList[j] == DIV && intOrFloat) //控制整数可除
			{
				valueListInt[j + 1] = Mygcd(valueListInt[j], valueListInt[j + 1]);
			}
		}

		//3、随机产生括号内联
		if (brackFlag)
		{
			//3.1 允许的个数 
			bn = random(0, n / 2);
			for (int j = 0; j < bn; j++)
			{
				//3.2 允许的位置:1、左不可n，右不可1 2、先左后右 3、右不可交错
				int posL = random(1, n - 1);
				int posR;
				bool breakFlag = 1, testFlag = 0, conFlag = 0;

				while (1)
				{
					posR = random(posL + 1, n);
					for (int k = 0; k <j; k++)
					{
						if (bracketL[k] == posR)//前面全部对比一下，不能和左括号同位
						{
							breakFlag = 0;
							break;
						}
						if (bracketR[k] == posR)//前面全部对比一下，如果存在同位的右括号，那么后面要检验是否左括号同位
						{
							testFlag = 1;
						}
						breakFlag = 1;
					}
					if (breakFlag) break;
				}
				//3.3 完全重合，那么重分配一次
				if (testFlag)
				{
					for (int k = 0; k < j; k++) //前面全部对比一下，不能完全相同
					{
						if (bracketL[k] == posL)
							conFlag = 1;
					}
					if (conFlag)
					{
						j--;
						continue;
					}

				}

				bracketL[j] = posL;
				bracketR[j] = posR;
			}

		}

		//4、生成算式类并自动计算结果
		if (intOrFloat)
		{
			MyEquation<int> tempE(valueListInt, symbolList, n, bracketL, bracketR, bn);
			FtableInt.push_back(tempE);
			FIntNum++;
		}
		else
		{
			MyEquation<float> tempE(valueListFloat, symbolList, n, bracketL, bracketR, bn);
			FtableFloat.push_back(tempE);
		}
		
	}

}

//四、算式构造函数，生成字符串和答案
template < class T >
MyEquation<T>::MyEquation(T * valL, Sym * symL, int valNum, int * bL, int * bR, int bN)
{
	//1、拷贝数据
	errorOccur = false;
	userAns = (T)0;

	valueNum = valNum;
	bn = bN;
	valList = (T *)malloc(sizeof(T)*valNum);
	symList = (Sym *)malloc(sizeof(Sym)*(valNum - 1));
	bracketL = (int *)malloc(sizeof(int)*bN);
	bracketR = (int *)malloc(sizeof(int)*bN);
	for (int i = 0; i < valNum; i++)
	{
		valList[i] = valL[i];
		if (i == valNum-1) break;
		symList[i] = symL[i];
	}
	for (int i = 0; i < bN; i++)
	{
		bracketL[i] = bL[i];
		bracketR[i] = bR[i];
	}

	//2、括号归并排序
	merge_sort(bracketL, 0, bn - 1);
	merge_sort(bracketR, 0, bn - 1);


	//3、构建算式字符串
	string bl = "(";
	string br = ")";
	int p = 0, lp = 0, rp = 0;
	string s = "";
	for (int i = 0; i < valueNum; i++)
	{
		//左括号
		while(bracketL[lp] == i+1)
		{
			s += bl;
			lp++;
		}

		//数值处理
		//浮点数仅取两位小数
		regex pattern("(-|[0-9])\\d*\\.\\d*");
		string temps = to_string(valList[i]);
		if (regex_match(temps, pattern))
			temps = temps.substr(0, temps.length() - 4);
		//负数
		if (valList[i] < 0)
		{
			s += bl;
			s += temps;
			s += br;
		}
		else
			s += temps;

		//右括号
		while(bracketR[rp] == i+1)
		{
			s += br;
			rp++;
		}

		if (i == valueNum - 1) break;
		//符号
		switch (symList[i])
		{
		case ADD:s += '+'; break;
		case SUB:s += '-'; break;
		case MUL:s += '*'; break;
		case DIV:s += '/'; break;
		}
	}
	eStr = s;

	//4、计算结果（要拷贝一份丢进去）
	T * valListTemp = (T *)malloc(sizeof(T)*valNum);
	Sym * symListTemp = (Sym *)malloc(sizeof(Sym)*(valNum - 1));
	int * bracketLTemp = (int *)malloc(sizeof(int)*bN);
	int * bracketRTemp = (int *)malloc(sizeof(int)*bN);
	int valNumTemp = valNum;
	int bnTemp = bN;
	for (int i = 0; i < valNum; i++)
	{
		valListTemp[i] = valL[i];
		if (i == valNum-1) break;
		symListTemp[i] = symL[i];
	}
	for (int i = 0; i < bN; i++)
	{
		bracketLTemp[i] = bracketL[i];
		bracketRTemp[i] = bracketR[i];
	}
	answer = autoCal(valListTemp, symListTemp, valNumTemp, bracketLTemp, bracketRTemp, bnTemp);
	int a = 1;
}


//四、算式输出函数（类型问题）
template < class T >
void MyEquation<T>::printEqu(bool showAnswer)
{
	if (showAnswer)
		cout<<eStr<<" = "<<answer<<endl;
	else
		cout << eStr<<endl;
}


void MyFour::printTable(bool showAnswer)
{
	for (int i = 0; i < FIntNum; i++)
	{
		FtableInt[i].printEqu(showAnswer);
		cout << endl;
	}
	for (int i = 0; i < Fnum - FIntNum;i++)
	{
		FtableFloat[i].printEqu(showAnswer);
		cout << endl;
	}
}

void MyFour::printError(bool showAnswer)
{
	
	for (int i = 0; i < FIntNum; i++)
	{
		if (FtableInt[i].errorOccur)
		{
			FtableInt[i].printEqu(showAnswer);
			cout << endl;
		}
		
	}
	for (int i = 0; i < Fnum - FIntNum; i++)
	{
		if (FtableFloat[i].errorOccur)
		{
			FtableFloat[i].printEqu(showAnswer);
			cout << endl;
		}
	}
}

/*
string MyFour::retAnEqu()
{
	static int count = 0;
	if (count < FIntNum)
	{
		count++;
		return FtableInt[count-1].retEqu();
	}
	else if (count == Fnum)
	{
		count = 0;
		return "None";
	}
		
	else
	{
		count++;
		return FtableFloat[count - FIntNum].retEqu();
	}
		
}

template < class T >
T MyFour::retAnEuq()
{
   
}
*/