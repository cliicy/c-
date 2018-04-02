#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <assert.h>
#include<Windows.h>


/*
*/
#include "..\t1\Node.h"
#include "..\t1\stack.h"
#include "..\t1\queue.h"
#include "..\t1\test_class.h"
#include "..\t1\ListNode.h"
#include "..\t1\tree.h"
#include "..\t1\common.h"

//using namespace std;
//using namespace linkedlistofclasses;
//using namespace stacksavitch;
//using namespace queuesavitch;
//using namespace linkedNodeofclasses;
//using namespace treetask;
//using namespace EmployeeTreeFiled;

using namespace solution;




int main() {

	char aa[20] = {};
	HANDLE handle = NULL;
	LPWIN32_FIND_DATA lpdata=NULL;
	handle=FindFirstFile("..\..\README.md", lpdata);
	cout << handle << endl;
	return 0;

	/*
	
	int arr[] = { 1, 10, 0, 4, 5 };
	int n = sizeof(arr) / sizeof(arr[0]);
	sort(arr, arr + n, greater<int>());
	for (int i = 0; i < n; i++)
		cout << arr[i] << "";

	return 0;

	fn();
	return 0;
*/
	//fn();
	//fn();
	//fn();

	/*extern int nA; 静态局部变量作用域消失了
	cout << nA << endl*/;

	return 0;

	//test //
	//A a;
	//B b;
	//C c;
	//A *Ptr;
	//B *PtrB;

	////base class ptr  
	//Ptr = &a;
	//Ptr->printSelf();
	//Ptr = &b;
	//Ptr->printSelf();
	//Ptr = &c;
	//Ptr->printSelf();

	//PtrB = &b;
	//PtrB->printSelf();
	//PtrB->printSelf2();
	//PtrB = &c;
	//PtrB->printSelf();
	//PtrB->printSelf2();


	//return 0;
	//test //


	InitEmployeeTree();
	return 0;

	int nSum = recur_sum(100);
	cout << "1+2+3+....100= " << nSum << endl;
	system("pause");
	return 0;
	//teststr t1;
	//return 0;

	//PrintTest(0);
	//return 0;

	InitTree();
	return 0;

	//test1();
	//test2();
   //  test3("acdefghi89");

	//transit_money();


	//return 0;

//	check_crash_point();
//	return 0;

	check_crash_point2();
	return 0;


	//测试指向字符数组的指针大小和指向字符的指针的大小
	/*
	check_size();
		return 0;
	return 0;
	//测试指向字符数组的指针大小和指向字符的指针的大小
	*/

	//测试函数指针
	/*
	int(*p1) (int, int);
	int a, b, m;
	p1 = max;

	cin >> a >> b;
	m = p1(a, b);

	cout << "max = "<< m << endl;
	return 0;
	*/
	//测试函数指针

	//测试指向结构体的指针
	/*
	S s;
	int *p = &s.i;
	p[0] = 4;
	p[1] = 3;
	s.p = p;
	s.p[1] = 1;
	s.p[2] = 1;
	s.p[10] = 2;

	return 0;
	*/
	//测试指向结构体的指针

	//测试指针参数和参数的引用
/*
	int a = 1, b = 2, c = 3;
	change(&a, b, c);
	cout << a << b << c;
	return 0;
*/
	//测试指针参数和参数的引用


//	testcoutcin();
//	fstropen();
//	multiplyBigInt();
//	demo_head_insert();
//	do_stack();
//	do_queue();

//	CExample A(100);
//	CExample B = A;
//	B.Show();

//	CA A(10, "hello!");
//	CA B = A;

//	do_vector();

//	do_vector2();

/*
	//test del duplicate number in a vector
	vector<int> vt = { 1, 1, 2,2,3,4,4,5 };
	removeDuplicates(vt);
	//test del duplicate number in a vector
*/

	//add two number in two different array relatively
	/*
	
	vector<int> vt = { 1, 2, 3, 4, 5, 6, 7, 8 };
	int target = 9;

	vector<int> vr;
	vr = twoSum(vt, target);
	*/
	//add two number in two different array relatively

	//add two numbers in the two linked 
	/*

	
	Node* node1 = new Node(2,NULL);
	head_insert(node1, 4);
	head_insert(node1, 3);

	Node* node2 = new Node(5, NULL);
	head_insert(node2, 6);
	head_insert(node2, 4);

	Node* nResult= addTwoNumbers(node1, node2);
*/
	//add two numbers in the two linked 
	/*test case 1 start */
//	test1_addtwolink();
	/*test case 1 end */

	/* test case2 start*/
//	test2_addtwolink();
	/* test case2 end*/

	//is the same tree?
	/*
	TreeNode* p = new TreeNode(1);
	TreeNode* pleft = new TreeNode(2);
	TreeNode* pright = new TreeNode(3);
	p->left = pleft;
	p->right = pright;

	TreeNode* q = new TreeNode(1);
	TreeNode* qleft = new TreeNode(2);
	TreeNode* qright = new TreeNode(3);
	q->left = qleft;
	q->right = qright;
	bool bresult = isSameTree(p, q);
	cout << "Is the same tree: " << bresult<< endl;
	*/
	//is the same tree?

/*
	
	string str1 = "ef";
	string str2 = "fe";
	isScramble1(str1, str2);


*/
    //测试传递字符数组时类型的size
	//在C语言中，数组作为参数，进行传递时，传递的是指针 ，换句话说，字符数组作为参数，
	//进行传递时，传递的是字符数组的起始地址，相当于一个字符指针
	/*
	char var[] = { 0 };
	int b = sizeof(var);
	int ret=test(var);
	return 0;
	*/
	//测试传递字符数组时类型的size


	//测试类型的size
	/*
	int** a1[3][4];
	int nsize = sizeof(a1);

	char** a2[3][4];
	int ncsize = sizeof(a2);

	return 0;
	*/
	//测试类型的size

	//测试指向数组的指针的内容
	/*
	int m = 3;
	int arr[] = { 6, 7, 8, 9, 10 };
	int na = sizeof(arr);
	int ni = sizeof(int);
	int sizeay = na / ni;
	int  *ptr = arr;
	int ntmp = *ptr;
	(*ptr++) += 123;
	ntmp = *ptr;
	//int ntmp2 = ++ptr;
	printf("%s.%s\n", "a", "b");
	printf("%d.%d\n", *ptr, *(++ptr));
	return 0;
	//*/
	//测试指向数组的指针的内容

	


	//int nret=_strlen("abcdefgt");

	//Test1
	//Test2();
//	Test3();

	//LoopMove("abcdefghi", 2);
	//LoopMove2("abcdefghi", 2);

/*
WAVEFORMAT waveFormat;
char* buffer = new char;
memcpy(&waveFormat, buffer, sizeof(WAVEFORMAT));
*/

//string str="aaa";
//string astr = "bbb";
//str = astr;



    return 0;
}



void sort(string& s){
	for (unsigned int i = 0; i < s.length(); i++){
		for (unsigned int k = 1; k < s.length(); k++)
		{
			if (s[i]>s[k])
			{
				char c = s[i];
				s[i] = s[k];
				s[k] = c;
			}
		}
	}
}

bool checkstr(string s1, string s2){
	sort(s1);
	sort(s2);
	return (s1 == s2);
}

bool isScreamble(string s1, string s2){
	if (s1 == "") return s2 == "";
	if (checkstr(s1, s2) == false) return false;
	int len = s1.length();
	if (len == 1)return true;

	for (unsigned int i = 1; i < s1.length(); i++){
		string left = s1.substr(0, i);
		string right = s1.substr(i);
		if (isScreamble(left, s2.substr(i)) && isScreamble(right, s2.substr(i)) || \
			isScreamble(left, s2.substr(len - i)) && isScreamble(right, s2.substr(len - i)))
			return true;

	}
	return false;
}


		