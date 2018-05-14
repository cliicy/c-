#pragma once
#include "..\t1\tree.h"
#include "..\t1\EmployeeTree.h"
#include "ListNode.h"
#include "Node.h"
#include "queue.h"
#include "stack.h"
#include <stdio.h>



using namespace linkedlistofclasses;
using namespace linkedNodeofclasses;
using namespace treetask;
using namespace queuesavitch;
using namespace stacksavitch;

namespace solution{
	/*
	1字节     uint8_t
	2字节     uint16_t
	4字节     uint32_t
	8字节     uint64_t
	*/

#define common_dir "..\\..\\common\\"
#define infile "infile.txt"
#define outfile "outfile.txt"




#define MIN(A,B) ((A)>=(B)?(return A):(return B))

	Node* addTwoNumbers(Node* n1, Node* n2);
	ListNode* addxTwoNumbers(ListNode* l1, ListNode* l2);
	ListNode* test1_addtwolink();

	ListNode* addEndTwoNumbers(ListNode* l1, ListNode* l2);
	ListNode* test2_addtwolink();

	bool isSameTree(TreeNode* p, TreeNode* q);
	bool isScramble(string s1, string s2);

	bool isScramble1(string s1, string s2);
	bool helper(string& a, int sa, int ea, string& b, int sb, int eb);

	void transit_money();
	int _strlen(const char *str);

	void fstropen();
	void testcoutcin();
	void multiplyBigInt();
	void multiplyBigIntEx();
	void head_insert(NodePtr& head, int the_number);

	void demo_head_insert();
	void do_stack();
	void do_queue();

	void do_vector();
	void do_vector2();

	void create_tree();

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


void check_crash_point();

void check_crash_point2();

void check_size();//测试指向字符数组的指针大小和指向字符的指针的大小
static void fnn();//声明静态函数

struct STest {
	int i;
	int * p;
};


struct PTest{
	char c;
	char *pc;
};
	

#define MIN2(A,B) ((A)>=(B)?(A):(B))
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

void sort(string& s);
bool isScreamble(string s1, string s2);
bool checkstr(string s1, string s2);

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


//	int vac = 3;

struct teststr{
	int aa;
	char a[3];
	teststr(){
		int i = 0;
	};
	~teststr(){

	};
};

template <class T>
int getArrayLen(T& array)
{
	return (sizeof(array) / sizeof(array[0]));
}


//static pthread_t thread_a_id;

void* printA(void* pA);
void* changeA(void* pA);
//	int removeDuplicates(vector<int>& nums);
//	vector<int> twoSum(vector<int>& nums, int target);

}