#pragma once
/*
1字节     uint8_t
2字节     uint16_t
4字节     uint32_t
8字节     uint64_t
*/
#include "..\t1\tree.h"
#include "..\t1\EmployeeTree.h"

namespace solution{
	//static int n; //定义静态全局变量
//	extern int nA;
//	void fn();
	static void fnn();//声明静态函数

	void fnn()//定义静态函数

	{

		int n = 10;

		cout << n << endl;

	}

	#define MIN(A,B) ((A>=B?return A:return B))
	enum hasFile{ DOC=0, IMAGE };

	void Test1();
	void GetMemory1(char* p);
	char* GetMemory2();
	void Test2();
	void GetMemory3(char**p, int num);
	void Test3();
	void swap(int* p1, int* p2);

	void Func_size(char str[100]);

	void LoopMove(char* pstr, int steps);
	void LoopMove2(char* pstr, int steps);
	void InitTree();

	void InitEmployeeTree();

	void PrintTest(int nSpace);

	int recur_sum(int nNumber);

	typedef _Uint32t UIN16;

	typedef struct tagWaveFormat {
		char cRiff[4];
		_Uint32t filelong;
		char cWaveFlag[4];
		char cFmtflag[4];
		char cTransition[4];
		UIN16 nFormatTag;
		UIN16 nChannels;
		UIN16 nSamplesPerSec;
		UIN16 nAvgBytesperSec;
		UIN16 nBlockAlign;
		UIN16 nBitNumPerSample;
		char cDataFlag[4];
		UIN16 nAudioLength;
	} WAVEFORMAT;
}