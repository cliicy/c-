#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <assert.h>

#include "..\t1\Node.h"
#include "..\t1\stack.h"
#include "..\t1\queue.h"
#include "..\t1\test_class.h"
#include "..\t1\ListNode.h"
#include "..\t1\tree.h"
#include "..\t1\common.h"


using namespace std;
using namespace linkedlistofclasses;
using namespace stacksavitch;
using namespace queuesavitch;
using namespace linkedNodeofclasses;
using namespace treetask;

#define common_dir "..\\..\\common\\"
#define infile "infile.txt"
#define outfile "outfile.txt"


template <class T>
int getArrayLen(T& array)
{
	return (sizeof(array)/sizeof(array[0]));
}


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

int removeDuplicates(vector<int>& nums);
vector<int> twoSum(vector<int>& nums, int target);

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
int vac = 3;

int test(char var[])
{
	int a = sizeof(char);
	int b = sizeof(var);
	return sizeof(var);
};

struct S {
	int i;
	int * p;
};

int max(int x, int y){
	int z;

	z = (x > y) ? x : y;

	return z;
}

//int a , b, c;
void change(int* a, int &b, int c)
{
		c = *a;
		b = 3;
		*a = 2;
}

struct {
	char c;
	char *pc;
} a;

void test1()
{
	char string[11];
	char* str1 = "0123456789";
	strcpy(string, str1);
}

void test2(){
	char string[10], str1[10];
	int i;
	for (i = 0; i < 10; i++){
		str1[i] = 'a';
	}
	strcpy(string, str1);
}


void test3(char* str1)
{
	char string[10];
	if (strlen(str1) <= 10)
	{
		strcpy(string, str1);
	}

}


int main() {

	//test1();
	//test2();
   //  test3("acdefghi89");

	//transit_money();


	//return 0;

	/*
	
	char *p = &a.c;
	p[0] = 0;
	p[1] = 0;
	p[2] = 0;
	p[3] = 0;
	p[4] = 0;
	p[5] = 0;
	a.pc = p;
	a.pc[5] = 0; 
	a.pc[4] = 0;
	a.pc[3] = 0;
	a.pc[2] = 0;
	a.pc[1] = 0;
	a.pc[0] = 0;
	return 0;
	*/

	/*
	
	S s;

	int *p = &s.i;

	p[0] = 4;

	p[1] = 3;

	s.p = p;

	s.p[1] = 1;//执行完该句后s.p指向地址为1的地方，s.p[0]是地址1中存放的内容。所以不能输出s.p[1]， //同样也不能对s.p[]赋值

	s.p[0] = 2;
	return 0;
	*/


	//测试指向字符数组的指针大小和指向字符的指针的大小
	/*
	char str[] = "world", *pstr = "world";
	printf("%d %d", sizeof(str), sizeof(pstr));
	getchar();
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

	
/*

	Tree tree(16);//分配十六个节点
//	Tree tree(3);//分配十六个节点

	tree.addNode(0, 1);
	tree.addNode(0, 2);	
	tree.addNode(0, 3);
	tree.addNode(0, 4);
	tree.addNode(0, 5);
	tree.addNode(0, 6);
	tree.addNode(3, 7);
	tree.addNode(4, 8);
	tree.addNode(4, 9);
	tree.addNode(5, 10);
	tree.addNode(5, 11);
	tree.addNode(5, 12);
	tree.addNode(6, 13);
	tree.addNode(9, 14);
	tree.addNode(9, 15);

	cout << "Tree1: " << endl;
	tree.preOrder();
	tree.print();

	Tree tree2(9);
	tree2.addNode(0, 1);
	tree2.addNode(0, 2);
	tree2.addNode(1, 3);
	tree2.addNode(1, 4);
	tree2.addNode(2, 5);
	tree2.addNode(3, 6);
	tree2.addNode(5, 7);
	tree2.addNode(5, 8);

	cout << "Tree2: " << endl;
	tree2.preOrder();
	tree2.print();
*/

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

string str="aaa";
string astr = "bbb";
str = astr;



    return 0;
}

void LoopMove(char* pstr, int steps){
	int n = strlen(pstr) - steps;
	char tmp[256];
	strcpy(tmp, pstr + n);
	strcpy(tmp + steps, pstr);
	*(tmp + strlen(pstr)) = '\0';
	//strcpy(pstr, tmp);
	pstr = tmp;
	int i = 0;
}

void LoopMove2(char* pstr, int steps){
	int n = strlen(pstr) - steps;
	char tmp[256];
	memcpy(tmp, pstr + n, steps);
	memcpy(tmp + steps, pstr, n);
	//memcpy(pstr, tmp, steps);
	//strcpy(tmp, pstr + n);
	//strcpy(tmp + steps, pstr);
	//*(tmp + strlen(pstr)) = '\0';
	//strcpy(pstr, tmp);
	memcpy(pstr, tmp, steps);
	//string s = tmp;
	int i = 0;
}

void Func_size(char str[100]){
	int nsize = sizeof(str);
	cout << nsize << endl;
}


void swap(int* p1, int* p2){
	int p;
	p = *p1;
	*p1 = *p2;
	*p2 = p;
}

void GetMemory1(char* p){
	p = (char*)malloc(100);
}

void Test1(){
	char* str = NULL;
	GetMemory1(str);
	strcpy(str, "hello world");
	printf(str);
}

char* GetMemory2() {
	char p[] = "hello world";
	return p;
}

void Test2() {
	char* str = NULL;
	str = GetMemory2();
	printf(str);
}

void GetMemory3(char**p,int num) {
	*p = (char*)malloc(num);
	assert(*p != NULL);
	/*
	if (*p == NULL)
	{

	}
	*/
}

void Test3() {
	char* str = NULL;
	GetMemory3(&str,100);
	strcpy(str, "hello");
	printf(str);
}

void my_strcpy(char *strdest, const char *strsrc){
	assert(strsrc != NULL && strdest !=NULL);
	while (*strsrc++ != '\0') {
		*strdest++ = *strsrc++;
	}
}

char * _tstrcpy(char *strdest, const char *strsrc) 
{ 
	assert((strdest != NULL) && (strsrc != NULL));
	char *address = strdest; 
	while ((*strdest++ = *strsrc++) != '\0'); 
	return address;
}

int _strlen(const char *str) //输入参数 const 试题 4：
{
	assert(str != NULL);
	int len=0;
	while ((*str++) != '\0') {
		len++;
	}
	return len;
}

void test() 
{ 
	char *str = new char;;
	strcpy(str, "hello world"); 
	printf(str); 
}

bool isScramble1(string s1, string s2) {
	int n1 = s1.size();
	int n2 = s2.size();
	return helper(s1, 0, n1 - 1, s2, 0, n2 - 1);
}

bool helper(string& a, int sa, int ea, string& b, int sb, int eb) {
	int len = ea - sa + 1;
	if (len != eb - sb + 1) return false;
	if (len == 0) return true;
	if (len == 1) return a[sa] == b[sb];
	vector<int> count(256, 0);
	//count 会自动把a[i]字符装换成对应的ASCII码
	for (int i = sa; i <= ea; ++i){
		char ta = a[i];
		count[a[i]]++;
	}	
	for (int i = sb; i <= eb; ++i) {
		char tb = b[i];
		count[b[i]]--;
	}
		
	for (int i = 0; i < 256; ++i) {
		if (count[i] != 0) 
			return false;
	}
	

	
	for (int i = 0; i < len - 1; ++i) {
		if ((helper(a, sa, sa + i, b, sb, sb + i) && helper(a, sa + i + 1, ea, b, sb + i + 1, eb)) ||
			(helper(a, sa, sa + i, b, eb - i, eb) && helper(a, sa + i + 1, ea, b, sb, eb - i - 1))) {
			return true;
		}
	}


	return false;
}

bool isXScramble(string s1, string s2) {
	return true;
}

bool isScramble(string s1, string s2)
{
	if (s1.length() != s2.length())
		return false;
	int len = s1.length();
	if (s1 == s2)
		return true;
	int tmp1 = 0;
	int tmp2 = 0;

	int table1[26] = { 0 }, table2[26] = { 0 };
	for (int i = 0; i < len; i++)
	{
		tmp1 = s1[i] - 'a';
		tmp2 = s2[i] - 'a';
		table1[tmp1] ++;
		table2[tmp2] ++;
	}
	if (memcmp(table1, table2, 26 * sizeof(int)))
		return false;
	if (len <= 3)
		return true;
	for (int i = 1; i < len; i++)
	{
		if (isScramble(s1.substr(0, i), s2.substr(0, i)) &&
			isScramble(s1.substr(i, len - i), s2.substr(i, len - i)))
			return true;
		if (isScramble(s1.substr(0, i), s2.substr(len - i, i)) &&
			isScramble(s1.substr(i, len - i), s2.substr(0, len - i)))
			return true;
	}
	return false;
}

bool isSameTree(TreeNode* p, TreeNode* q) {

	if (p == NULL || q == NULL) return (p == q);
	return (p->element == q->element && isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
//	cout << p->val << endl;

	bool bsame = true;
	while (p != NULL && q != NULL) {
		if (p->element == q->element){
			if (isSameTree(p->left, q->left)) {
				isSameTree(p->right,q->right);
			}		
			else
				bsame = false;
		}
		else
			bsame = false;
	}
	if (p == NULL || q == NULL) return (p == q);

	return bsame;

}
ListNode* test2_addtwolink() {
	ListNode* n1 = new ListNode(5);
	ListNode* na1 = new ListNode(5);
	ListNode* pNode = addEndTwoNumbers(n1, na1);
	while (pNode){
		cout << pNode->val;
		pNode = pNode->next;
	}
	return pNode;
}

ListNode* test_addtwolink() {
	ListNode* n1 = new ListNode(2);
	ListNode* n2 = new ListNode(4);
	n1->next = n2;
	ListNode* n3 = new ListNode(3);
	n2->next = n3;

	ListNode* na1 = new ListNode(5);
	ListNode* na2 = new ListNode(6);
	na1->next = na2;
	ListNode* na3 = new ListNode(4);
	na2->next = na3;
	ListNode* pNode = addxTwoNumbers(n1, na1);
	while (pNode){
		cout << pNode->val;
		pNode = pNode->next;
	}
	return pNode;
}

//insert node from end if the new node doesn't exist
ListNode* addEndTwoNumbers(ListNode* l1, ListNode* l2) {
	int carry = 0;
	int tval = 0;
	ListNode* pHead = NULL;
	ListNode* pTmpHead = NULL;

	while (l1 != NULL || l2 != NULL){
		int x = (l1 != NULL) ? l1->val : 0;
		int y = (l2 != NULL) ? l2->val : 0;
		int sum = x + y + carry;
		carry = sum / 10;
		tval = sum % 10;

		ListNode* tNode = new ListNode(tval);
		if (!pHead){
			pHead = tNode;
		    pTmpHead = pHead;
		}
		else {
			pTmpHead->next = tNode;
			pTmpHead = tNode;
		}

		if (l1 != NULL) l1 = l1->next;
		if (l2 != NULL) l2 = l2->next;
	}
	if (carry>0)
	{
		ListNode* tNode = new ListNode(carry);
		pTmpHead->next = tNode;
		pTmpHead = tNode;
	}
	return pHead;

}
//insert node from end if the new node doesn't exist


//insert node from head
ListNode* addxTwoNumbers(ListNode* l1, ListNode* l2) {
	int carry = 0;
	int tval = 0;
	ListNode* pHead = NULL;// = new ListNode(0);
	
	while (l1 != NULL || l2 != NULL){
		int x = (l1 != NULL) ? l1->val : 0;
		int y = (l2 != NULL) ? l2->val : 0;
		int sum = x + y+carry;
		carry = sum / 10;
		tval = sum % 10;

		ListNode* tNode = new ListNode(tval);
		tNode->next = pHead;
		pHead = tNode;
	
		
		if(l1!=NULL) l1 = l1->next;
		if(l2!=NULL) l2 = l2->next;
	}
	if (carry>0)
	{
		ListNode* tNode = new ListNode(tval);
		tNode->next = pHead;
		pHead = tNode;
	}
	return pHead;

}

Node* addTwoNumbers(Node* n1, Node* n2){
	Node* nHead = new Node(0,NULL);
	int value = 0;
	int carry = 0;
	int tmpvalue = 0;
	Node* curr = nHead;
	while (n1 != NULL || n2 != NULL) {
		int x = (n1 != NULL) ? n1->getData() : 0;
		int y = (n2 != NULL) ? n2->getData() : 0;
		int sum = carry + x + y;
		carry = sum / 10;
		head_insert(nHead, sum % 10);
		
		if (n1 != NULL) n1 = n1->getLink();
		if (n2 != NULL) n2 = n2->getLink();
	}
	if (carry > 0) {
		Node* cNode = new Node(carry, curr->getLink());
		nHead = cNode;
	}
	return nHead;
}

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/


/*

void Node* addTwoNumbers(Node* l1, Node* l2) {
		Node result = new Node();
		Node* p = l1;
		Node* q = l2;

		int sum = 0;
		int tmpsum = 0;
		int res = 0;
		int carry = 0;

		while (p->next){
			while (q->next){
				tmpsum = (p->val + q->val);
				res = tmpsum % 10 + carry;
				carry = tmpsum / 10;
				p = p->next;
				q = q->next;
			}
		}

	}
};

*/

vector<int> twoSum(vector<int>& nums, int target) {
	vector<int> result;
	for (unsigned int i = 0; i < nums.size(); i++)
	{
		for (unsigned int k = i + 1; k < nums.size(); k++)
		{
			if (nums[i] + nums[k] == target)
			{
				result.push_back(i);
				result.push_back(k);
			}

		}
	}
	return result;
}


int removeDuplicates(vector<int>& nums) {
	vector<int>::iterator iter;
	/*
	
	for (iter = nums.begin(); iter < nums.end(); iter++)
	{
		cout << *iter << endl;
		
	}
*/
	for (unsigned int i = 0; i < nums.size(); i++){
		int tmp = nums[i];
		for (unsigned int k = i+1; k < nums.size(); k++){
				if (tmp == nums[k])
				{
					nums.erase(nums.begin() + k);
					k--;
				}
		}
	}
	return nums.size();
}


void do_vector() {
	vector<int> vt;
	cout << "Enter a list of positive numbers.\n"
		<< "Place a negative number number at the end.\n";

	int next;
	cin >> next;
	while (next > 0) {
		vt.push_back(next);
		cout << next << " added. ";
		cout << "vt.size() = " << vt.size() << endl;
		cin >> next;
	}


/*	
	
	for (int i = 0; i < 5; i++) {
		vt.push_back(i);
	}
*/
	cout << "will pop the value one by one: ";
	for (unsigned int j = 0; j < vt.size(); j++){
		cout << vt[j] << " ";
	}

}

void do_vector2() {
	vector<char> vt;
	cout << "Enter a list of positive numbers.\n"
		<< "Place a negative number number at the end.\n";

	char next;
	cin >> next;
	while (next != '@') {
		vt.push_back(next);
		cout << next << " added. ";
		cout << "vt.size() = " << vt.size() << endl;
		cin >> next;
	}

	cout << "will pop the value one by one: ";
	for (unsigned int j = 0; j < vt.size(); j++){
		cout << vt[j] << " ";
	}

}


void do_queue() {
	Queue q;
	char next, ans;
	do {
		cout << "Enter a word: ";
		cin.get(next);
		while (next != '\n'){
			q.add(next);
			cin.get(next);
		}
		cout << "you entered: ";
		while (!q.empty())
			cout << q.remove();
		cout << endl;

		cout << "Again?(Y/n): ";
		cin >> ans;
		cin.ignore(1000, '\n');
	} while (ans != 'n' && ans != 'N' );
}


void do_stack(){
	Stack s;
	char next, ans;
	do {
		cout << "enter a word: ";
		cin.get(next);
		while (next != '\n')
		{
			s.push(next);
			cin.get(next);
		}
		cout << "Written backward that is: ";
		while ( !s.empty() ) {
			cout << s.pop();
		}
		cout << endl;

		cout << "Again?(y/n): ";
		cin >> ans;
		cin.ignore(10000, '\n');
	} while (ans != 'n' && ans != 'N');

}


void head_insert(NodePtr& head, int the_number) {
	NodePtr tempNode = new Node(the_number, head);
	head = tempNode;
}

void demo_head_insert() {
	NodePtr head, tmp;
	head = new Node(0, NULL);
	for (int i = 1; i < 5; i++){
		head_insert(head, i);
	}

	//Iterate through the list and display each value
	tmp = head;
	while (tmp != NULL)
	{
		cout << tmp->getData() << endl;
		tmp = tmp->getLink();
	}

	//Delete all nodes in the list before exiting
	tmp = head;
	while (tmp != NULL){
		NodePtr nodeToDel = tmp;
		tmp = tmp->getLink();
		delete nodeToDel;
	}
}

void testcoutcin() {
	int n_25(0), n_10(0), n_5(0), n_total(0), cost_per_person(0);
	cout << n_25 << " " << n_10 << " " << n_5 << " " << cost_per_person << endl;
	cout << "Please input the number of 25 cents:\n";
	cin >> n_25;
	cout << "Please input the number of 10 cents:\n";
	cin >> n_10;
	cout << "Please input the number of 5 cents:\n";
	cin >> n_5;

	n_total = n_25 * 25 + n_10 * 10 + n_5 * 5;
	cout << "The total number of cents:";
	cout << n_total;

	cout << "\njust wait for moment and please input how many seconds to wait!\n";

	cout << "Enter the cost per person: $";
	cin >> cost_per_person;

	cout << "Please input tab and return char:" << "\\t" << "\\n";
}

void fstropen(){
	ifstream in_stream;
	string infiledir = common_dir;

	string in_file = infile;
	string in_dir = common_dir + in_file;
	in_stream.open(in_dir);
	
	ofstream out_stream;
	string out_file = outfile;
	out_stream.open(common_dir + out_file);

	int data1(0), data2(0), data3(0);
	in_stream >> data1 >> data2 >> data3;
	out_stream << data1 + data2 + data3;
	in_stream.close();
	out_stream.close();


}

void multiplyBigInt(){
	float fInt1(0),fInt2(0);
	cout << "Please input big Integer1:" << endl;
	cin >> fInt1;
	cout << "Please input big Integer2:" << endl;
	cin >> fInt2;
	cout << "The result is: " << fInt1*fInt2 << endl;
	cout << "Please check.....";
}

//如何求2个大数的乘积
void multiplyBigIntEx(){
	//char num1[100];
	//char num2[100];

	int num1[100];
	int num2[100];
	int tempRes[100] = { 0 };
	cout << "Please input big Integer1:" << endl;
	cin >> num1[0];
	cout << "Please input big Integer2:" << endl;
	cin >> num2[0];
	int nlen1 = getArrayLen(num1);
	int nlen2 = getArrayLen(num2);
	int tempResLen = nlen1;
	int ncarry = 0;
	cout << "num1's length:" <<nlen1;
	cout << "num2's length:" << nlen2;
	/**
	for (int p2 = nlen2 - 1; p2 >= 0; p2--) {
		for (int p1 = nlen1 - 1; p1 >= 0;p1--) {
			int res = num1[p2] * num1[p1] + ncarry;
			tempRes[tempResLen--] = res % 10;
			ncarry = res / 10;
		}
		//tempRes[tempResLen] = Char(ncarry);
		//tempResLen = nlen1;
		//ncarry = 0;
	}
	**/
	cout << "Please check.....";
}

//a b 2个对象的子对象以及继承关系



//设计一个转账交易的小程序

//对不知道大小的数组进行排序，如何找到最大的数




string num2str(double i)

{

	stringstream ss;

	ss << i;

	return ss.str();

}

//字符串转数字：

int str2num(string s)

{

	int num;

	stringstream ss(s);

	ss >> num;

	return num;

}

void transit_money(){
	char* custerm1ID = "luo";
	char* custerm2ID = "juice";

	string transSum;
	cin >> transSum;

	char chr;
	cin >> chr;

	char* pcha=new char;
	cin >> pcha;


	int ntrasSum;
	cin >> ntrasSum;

	char* balance1 = "80000";
	int nbalance1 = 80000;



	char* balance2 = "90000";
	int nbalance2 = 90000;

	//balance2 += transSum;

	nbalance2 += ntrasSum;

	cout << nbalance2 << endl;
}


/*
String BigNumMultip(String bigNum1, String bigNum2){

	if (bigNum1 == null || bigNum2 == null){
		return "输入有误";
	}
	if (bigNum1 == "0" || bigNum2 == "0"){
		return "0";
	}

	//将传进来的字符串参数转为字符数组并反转数组
	char[] num1 = new StringBuffer(bigNum1).reverse().toString().toCharArray();
	char[] num2 = new StringBuffer(bigNum2).reverse().toString().toCharArray();

	for (int i = 0; i<num1.length; i++){
	>'9'){
		return "输入的数字不能含有非法字符";
	}
	}
	for (int i = 0; i<num2.length; i++){
	>'9'){
		return "输入的数字不能含有非法字符";
	}
	}

	int resultLen = num1.length + num2.length; //结果的长度
	int[] result = new int[resultLen];

	for (int j = 0; j<num1.length; j++){
		i = "0;i<num2.length;i++){" int = "" resultstr = "new" stringbuffer = "" >= 0; i--){
			resultStr.append(result[i]);
		}

		return resultStr.toString();
	}< / num1.length; j++){>< / num2.length; i++){>< / num1.length; i++){>
	*/