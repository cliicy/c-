#include <stdio.h>
#include <iostream>
#include <sstream>
#include <exception>
#include <vector>
#include "leedcode\Currency.h"
#include "leedcode\Curr2.h"
#include "leedcode\linerlist.h"
#include "leedcode\ClassTemplate.h"
#include "leedcode\chain.h"
#include "leedcode\Array1D.h"
#include "leedcode\Array2D.h"
#include "leedcode\stack_link.h"
#include "leedcode\stack.h"
#include "leedcode\LinkedQueue.h"
#include "leedcode\BItreenode.h"
#include "leedcode\binaryTree.h"
#include "leedcode\Common.h"
#include "leedcode\ListNode.h"
#include "leedcode\TrinaryTreeLCA.h"
#include "leedcode\BISearchTreeLCA.h"
#include "leedcode\FreqNodeSum.h"
#include "leedcode\amaProCen.h"

using namespace TrinaryTreeLCA;
using namespace BISearchTreeLCA;
using namespace FreqTreeNodeSum;
using namespace amazonStorageCenter;

using namespace MyCommon;

using namespace std;
const int MaxLength = 100; // �����ַ�������

//about tree search
#include "leedcode\biTreeSearch.h"
void do_BITreeSearch(){
//��ͼ��ʾ�Ķ����������������,������'#'��ʾ���������������������
	char data[15] = { 'A', 'B', 'D', '#', '#', 'E', '#', '#', 'C', 'F', '#', '#', 'G', '#', '#' };
	Tree tree;
	treeNodeConstructor(tree, data);
	printf("������ȱ������������: ");
	depthFirstSearch(tree);
	printf("\n\n������ȱ������������: ");
	breadthFirstSearch(tree);
}
//about tree search

void t_currency1(){
	using namespace currency;
	Currency g, h(opts_sign::plus, 3, 50), i, j;
	g.Set(opts_sign::minus, 2, 25);
	i.Set((float)-6.45);
	j = h.Add(g);
	j.Output(); cout << endl;
	i.Increment(h);
	i.Output(); cout << endl;
	j = i.Add(g).Add(h);
	j.Output(); cout << endl;
	j = i.Increment(g).Add(h);
	j.Output(); cout << endl;
	i.Output(); cout << endl;
}


void t_curr2(){
	using namespace curr2;
	Currency g, h(opts_sign::plus, 3, 50), i, j;
	g.Set(opts_sign::minus, 2, 25);
	i.Set((float)-6.45);
	j = h + g;
	cout << j << endl;


	i += h;
	cout << i << endl;
	j = i + g + h;
	cout << j << endl;
	j = (i += g) + h;
	cout << j << endl;
	cout << i << endl;
}


void t_linearList(){
	using namespace LineList;
	try {
		cout << "aaa" << endl;
		LinearList<int> L(5);
		
		cout << "IsEmpty = " << L.IsEmpty() << endl;
		L.Insert(0, 2).Insert(1, 6);
		cout << "List is " << L << endl;
		cout << "IsEmpty = " << L.IsEmpty() << endl;
		int z;
		L.Find(1, z);
		cout << "First element is " << z << endl;
		cout << "Length = " << L.Length() << endl;
		L.Delete(1, z);
		cout << "Deleted element is " << z << endl;
		cout << "List is " << L << endl;
		
	}
	catch (...) {
		
	}
}


void t_myclass(){
	myClass<int> class1(3);
	class1.show();

	myClass<int> class2(3);
	class2.show();

	myClass<double> class3(2.90);
	class3.show();
}

void chain_iterator()
{
	/*
	int *x;
	ChainIterator<int> c;
	x = c.Initialize(x);
	while (x) {
		cout << *x << ' ';
		x = c.Next();
	}
	cout << endl;*/
}

void do_chain(){
	Chain<int> L;
	L.Insert(0, 10).Insert(1, 20).Insert(2,15);
}

void do_Array1D(){
	Array1D<int> arry1D(5);
	int nL = arry1D.Size();

	Array1D<int> b1D(arry1D);
	Array1D<int> p1D(5);
	Array1D<int> c1D = p1D;

	Array1D<int> a1D(5);
	a1D += 2;
	c1D = a1D;
	Array1D<int> aT=a1D - arry1D;

	Array1D<int> temp = -a1D;

}


void do_Array2D()
{
	Array2D<int> arry2D(2,4);
//	int nL = arry2D.Size();

//	Array2D<int> b2D(arry2D);
//	Array2D<int> p2D(5);
//	Array2D<int> c2D = p2D;

//	Array2D<int> a2D(5);
//	a2D += 2;
//	c2D = a2D;
//	Array2D<int> aT = a2D - arry2D;

//	Array2D<int> temp = -a2D;

}


void PrintMatchedPairs(char *expr)
{// ����ƥ��
	Stack<int> s(MaxLength);
	int j, length = strlen(expr);
	// �ӱ��ʽexpr ������( ��)
	for (int i = 1; i <= length; i++) {
		if (expr[i - 1] == ' ( ') s.Add(i);
		else if (expr[i - 1] == ' ) ')
		try{ s.Delete(j);
		cout << j << ' ' << i << endl; }
		catch (exception)
		{
			cout << "No match for right parenthesis" << " at " << i << endl;
		}
	}
	// ��ջ����ʣ�µ�(����δƥ���
	while (!s.IsEmpty()) {
		s.Delete(j);
		cout << "No match for left parenthesis at " << j<< endl;
	}
}

void do_expr(){
	char expr[MaxLength];
	cout << "Type an expression of length at most " << MaxLength << endl;
	cin.getline(expr, MaxLength);
	cout << "The pairs of matching parentheses in" << endl;
	puts(expr);
	cout << "are" << endl;
	PrintMatchedPairs(expr);
}


void do_linkedQueue(){
	LinkedQueue<int> que;
	que.IsEmpty();
	que.Add(2).Add(4).Add(6);
	que.IsFull();
	que.IsEmpty();
	que.First();
	que.Last();
	int val;
	que.Delete(val);
}


void do_tree(){

	BinaryTree<char*> a, x, y, z;
	
	y.MakeTree("Luo", a, a);
	z.MakeTree("Juice", a, a);
	x.MakeTree("Zhang", y, z);
	y.MakeTree("Zhang Wei", x, a);

}


void do_reverseString()
{
	linkedStack<char> p;
	string str = "Hello! World";
	string::iterator it = str.begin();
	for (it; it != str.end(); ++it){
		p.push(*it);
	}
	//cout << "are" << endl;
	char pItem;
	while (p.Top()){
		p.pop(pItem);
		cout << pItem ;
	}
	cout << endl;

}

/*
Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".
*/
string  do_reverseStr3(string s){
//	string s1 = "Hello! Luo";
//	reverse(s1.begin(), s1.end());
//	cout << s1.c_str() << endl;

	
	string ss;
	int idex = s.length() - 1;
	while (idex >= 0){
		while (idex >= 0 && s[idex] == ' '){
			idex--;
		}
		if (idex < 0) break;
		if (ss.length() != 0)
			ss.push_back(' ');
		string temp;
		for (; idex >= 0 && s[idex] != ' ';idex--){
			temp.push_back(s[idex]);
		}
		//cout << temp.c_str() << endl;
		reverse(temp.begin(), temp.end());
		//cout << temp.c_str() << endl;
		ss.append(temp);
	}
	s = ss;
	cout << s.c_str() << endl;
	return s;
}

string  do_reverseStr2(string s){
	string ss;
	int i = s.length() - 1;
	while (i >= 0)
	{
		while (i >= 0 && s[i] == ' ')
		{
			i--;
		}
		if (i<0) break;
		if (ss.length() != 0)
			ss.push_back(' ');
		string temp;
		for (; i >= 0 && s[i] != ' '; i--)
			temp.push_back(s[i]);
		reverse(temp.begin(), temp.end());
		ss.append(temp);
	}
	s = ss;
	cout << s.c_str() << endl;

	return s;
}
/*
����һ���������� nums ��һ������ k���������飨���ƶ����� nums �е�Ԫ�أ���ʹ�ã�

����С��k��Ԫ���Ƶ����
���д��ڵ���k��Ԫ���Ƶ��ұ�
�������黮�ֵ�λ�ã��������е�һ��λ�� i������ nums[i] ���ڵ��� k��
*/
int do_separateArray()
{
	int nArr[8] = { 7, 9, 10, 4, 5, 6, 7, 8 };
	cout << "Before moving:" <<endl ;
	linkedStack<int> nLargArry, nSmallArry;
	int k = 5;
	int nPos = -1;
	int nL = sizeof(nArr) / sizeof(int);
	for (int i = 0; i < nL; i++)
	{
		cout << nArr[i] << " ";
		if (nArr[i] >= k){
			if (nPos == -1)
				nPos = i;
		}
	}

	for (int i = nL-1; i >= 0; i--){
		if (nArr[i] >= nArr[nPos]){
			nLargArry.push(nArr[i]);
		}
		else {
			nSmallArry.push(nArr[i]);
		}
	}
	int i = 0;
	while (nSmallArry.Top()){
		nSmallArry.pop(nArr[i++]);
	}
	while (nLargArry.Top()){
		nLargArry.pop(nArr[i++]);
	}
	cout << "after moving:"<<endl;
	for (int i = 0; i < nL; i++)
	{
		cout << nArr[i] << " ";
	}
	return nPos;
}

int partitionArray(vector<int> &nums, int k) {
	int i = 0, j = nums.size() - 1;
	while (i <= j) {
		while (i <= j && nums[i] < k) i++;
		while (i <= j && nums[j] >= k) {
			j--;
		}
		if (i <= j) {
			int temp = nums[i];
			nums[i] = nums[j];
			nums[j] = temp;
			i++;
			j--;
		}
	}

	for (int i = 0; i < (int)nums.size(); i++)
		cout << nums[i] << " ";

	return i;
}

int parArray(vector<int> &nums, int k){
	if (nums.empty()) return -1;
	if (nums.size() == 1) return 0;

	cout << "Before setpart...." << endl;
	vector<int>::iterator it = nums.begin();

	vector<int> biggerT, smallerT;
	int nPos = -1,nloc=-1;
	for (it; it != nums.end(); it++)
	{
		nloc++;
		cout << *it << " ";
		if (*it > k){
			biggerT.push_back(*it);
			if (nPos == -1)
				nPos = nloc;
		}
			
		else
			smallerT.push_back(*it);
	}
	cout << endl;
	cout << "After then, array will be separated from: " << nPos << " "<<endl;

	for (vector<int>::iterator it = smallerT.begin(); it != smallerT.end(); it++){
		cout << *it << " ";
	}
	for (vector<int>::iterator it = biggerT.begin(); it != biggerT.end(); it++){
		cout << *it << " ";
	}
	cout << endl;

	return -1;
}

int do_partitionArray(){
	vector<int> nums;
	nums.push_back(7);
	nums.push_back(9);
	nums.push_back(10);
	nums.push_back(4);
	nums.push_back(5);
	nums.push_back(6);
	nums.push_back(7);
	nums.push_back(8);
	int nPos = -1;
	//nPos=parArray(nums, 5);
	nPos = partitionArray(nums, 5);
	return nPos;
}

void do_plus2Linked(){
	//vector<ChainNode>
}


/*
�������
����������������������������ÿ���ڵ����һ�����֡����ִ洢������ԭ���������෴��˳��
ʹ�õ�һ������λ������Ŀ�ͷ��д��һ������������������ӣ���������ʽ���غ͡�
������������ 3->1->5->null �� 5->9->2->null������ 8->0->8->null
*/

void printList(ListNode<int> * l1, ListNode<int> * l2, ListNode<int> * l3){
	ListNode<int> * p1 = l1;
	ListNode<int> * p2 = l2;
	ListNode<int> * p3 = l3;
	ListNode<int> *pTemp=NULL;
	while (p1){
		cout << p1->val << " ";
		pTemp = p1;
		p1 = p1->next;
		delete pTemp;
	}
	cout << endl;

	while (p2){
		cout << p2->val << " ";
		pTemp = p1;
		p2 = p2->next;
		delete pTemp;
	}
	cout << endl;
	while (p3){
		cout << p3->val << " ";
		pTemp = p1;
		p3 = p3->next;
		delete pTemp;
	}
	cout << endl;
}

ListNode<int>* AddList(ListNode<int> * l1, ListNode<int> * l2){
	ListNode<int> * p1 = l1;
	ListNode<int> * p2 = l2;
	ListNode<int> *pRetTop = NULL;
	ListNode<int> *pTemp = NULL;
	
	int nret(0), quotient(0), remainder(0);
	while (p1|| p2 ){
		if (p1 && p2)
			nret = p1->val + p2->val;
		else if (p1){
			nret=p1->val;
		}else if (p2)
			nret = p2->val;
		
		ListNode<int> *pItem = new ListNode<int>;
		pItem->next = NULL;

		
		pItem->val = nret + remainder;
		quotient = pItem->val % 10;//�õ�������������ʵ�����Ǽӷ��еõ���ֵ����ȥ��λ��
		remainder = pItem->val / 10;//�õ�������  ����ʵ�����Ǽӷ��еĽ�λ
		pItem->val = quotient;
			
		
		if (!pRetTop)
			pTemp=pRetTop = pItem;
		else{
			pTemp->next = pItem;
		}
		pTemp = pItem;
		
		if (p1)
			p1 = p1->next;
		if (p2)
			p2 = p2->next;

	}
	if (remainder){//���ǵ����Ľ�λ ҲҪ���뵽�����С�
		ListNode<int> *pRemainder = new ListNode<int>;
		pRemainder->val = 0;
		pRemainder->next = NULL;
		pTemp->next = pRemainder;
		pRemainder->val = remainder;
	}
	return pRetTop;
}

ListNode<int> * addTwoNumbers(ListNode<int> * l1, ListNode<int> * l2){
	ListNode<int>  *head = new ListNode<int>();
	ListNode<int>  *ptr = head;
	int carry = 0;
	while (true) {
		if (l1 != NULL) {
			carry += l1->val;
			l1 = l1->next;
		}
		if (l2 != NULL) {
			carry += l2->val;
			l2 = l2->next;
		}
		ptr->val = carry % 10;
		carry /= 10;
		// ��������ǿջ������н�λʱ��Ҫ�������㣬�����˳�ѭ��
		if (l1 != NULL || l2 != NULL || carry != 0) {
			ptr = (ptr->next = new ListNode<int>());
		}
		else break;
	}
	return head;
}
/*
�����β�����Ԫ��ʱ���ǵ�Ҫ�����һ����ӵ�Ԫ�ؽڵ��next����Ϊnull�� �����ͷ���Դʱ���쳣��
*/
void do_ListAddFromTail(int nA[],int nB[]){

	ListNode<int>* pL1 = new ListNode<int>;

	ListNode<int>* pL2 = new ListNode<int>;
	pL2->val = nA[1];//1;
	pL1->next = pL2;

	ListNode<int>* pL3 = new ListNode<int>;
	pL3->val = nA[2]; //5;
	pL3->next = NULL;
	pL2->next = pL3;
	ListNode<int>* top1 = pL1;

	ListNode<int>* pLB1 = new ListNode<int>;
	pLB1->val = nB[0];// 5;
	pLB1->next = NULL;

	ListNode<int>* pLB2 = new ListNode<int>;
	pLB2->val = nB[1];//9;
	pLB1->next = pLB2;

	ListNode<int>* pLB3 = new ListNode<int>;
	pLB3->val = nB[2];//2;
	pLB3->next = NULL;
	pLB2->next = pLB3;
	ListNode<int>* top2 = pLB1;

	ListNode<int>* pRul = AddList(top1, top2);
	printList(top1, top2,pRul);


}

void do_ListAddFromHead(int nA[],int nLa, int nB[],int nLb){


	ListNode<int>* pTopA = NULL;
	for (int i = 0; i < nLa; i++){
		ListNode<int>* pLA = new ListNode<int>;
		pLA->val = nA[i];
		pLA->next = pTopA;
		pTopA = pLA;
	}

	ListNode<int>* pTopB = NULL;
	for (int i = 0; i < nLb; i++){
		ListNode<int>* pLB = new ListNode<int>;
		pLB->val = nB[i];
		pLB->next = pTopB;
		pTopB = pLB;
	}


	//ListNode<int>* pRet = AddList(pTopA, pTopB);//���Լ�������
	ListNode<int>* pRet = addTwoNumbers(pTopA, pTopB);//�ٷ�������
	printList(pTopA, pTopB, pRet);

	/*
	ListNode<int>* pL1 = new ListNode<int>;
	pL1->val = 3;
	pL1->next = NULL;

	ListNode<int>* pL2 = new ListNode<int>;
	pL2->val = 1;
	pL2->next = pL1;

	ListNode<int>* pL3 = new ListNode<int>;
	pL3->val = 5;
	pL3->next = pL2;
	ListNode<int>* top1 = pL3;

	ListNode<int>* pLB1 = new ListNode<int>;
	pLB1->val = 5;
	pLB1->next = NULL;

	ListNode<int>* pLB2 = new ListNode<int>;
	pLB2->val = 9;
	pLB2->next = pLB1;

	ListNode<int>* pLB3 = new ListNode<int>;
	pLB3->val = 2;
	pLB3->next = pLB2;
	ListNode<int>* top2 = pLB3;	
	ListNode<int>* pRet = AddList(top1, top2);
	printList(top1, top2, pRet);
	*/
}

//�˻ʺ�����
static int gEightQueen[8] = { 0 }, gCount = 0;
void printQueen()//���ÿһ������������лʺ�İڷ����
{
	for (int i = 0; i < 8; i++)
	{
		int inner;
		for (inner = 0; inner < gEightQueen[i]; inner++)
			cout << "0";
		cout << "#";
		for (inner = gEightQueen[i] + 1; inner < 8; inner++)
			cout << "0";
		cout << endl;
	}
	cout << "==========================\n";
}
int check_pos_valid(int loop, int value)//����Ƿ�����ж���ʺ���ͬһ��/��/�Խ��ߵ����
{
	int index;
	int data;
	for (index = 0; index < loop; index++)
	{
		data = gEightQueen[index];
		if (value == data)//�ж��Ƿ�����ͬһ��
			return 0;
		if ((index + data) == (loop + value))//�ж��Ƿ��������Խǵ�б����
			return 0;
		if ((index - data) == (loop - value))//�ж��Ƿ����ڷ��Խǵ�б����
			return 0;
	}
	return 1;
}
void eight_queen(int index)
{
	int loop;
	for (loop = 0; loop < 8; loop++)
	{
		if (check_pos_valid(index, loop))
		{
			gEightQueen[index] = loop;
			if (7 == index)
			{
				gCount++, printQueen();
				//gEightQueen[index] = 0;
				return;
			}
			eight_queen(index + 1);
			//gEightQueen[index] = 0;
		}
	}
}
//�˻ʺ�����

void do_queenByUsual(){
	eight_queen(0);
	cout << "total=" << gCount << endl;
}

//�˻ʺ�����10�д���㶨
int N = 8, queen[8];
int dfs(int n, int result = 0) {
	if (n == N) return 1; else for (int i = 0, flag = 0; i < N; queen[n] = i, i++, result += (flag == 0 ? dfs(n + 1) : 0), flag = 0) for (int j = 0; j < n; j++) if (i - queen[j] == 0 || abs(n - j) == abs(i - queen[j])) flag = 1;
	return result;
}

#include <algorithm>
int queens(){
	int pos[] = { 0, 1, 2, 3, 4, 5, 6, 7 }, ans = 0;
	while (next_permutation(pos, pos + 8)){
		bool ok = true;
		for (int* p = pos; p<pos + 8; p++)
			if (count_if(pos, p, [=](int& j){return p - &j == *p - j || p - &j == j - *p; }))
				ok = false;
		ans += ok;
	}
	return ans;
}


//�˻ʺ�����10�д���㶨
void do_queenBy10Line(){
	std::cout << dfs(0) << std::endl;
}

void do_queenBy10Line2(){
	cout << queens();
}

string do_custmerShopping()
{
	string recorder[] = { "custA", "item1", "custB", "item1", "custA", "item2", "custB", "item3", "custC", "item1", "custC", "item3", "custD", "item2" };
	int nL = sizeof(recorder) / sizeof(recorder[0]);

	string buyItem = "item1";
	string custerID[] = { "NULL" };
	string buyItems[] = {"NULL"};
	bool bOnlyOneItem = false;

	for (int i = 0; i < nL;i+=2){
		if (buyItem.compare(recorder[i + 1])){
			custerID[i] = recorder[i];
		}
	}

	int nIDL = sizeof(custerID) / sizeof(custerID[0]);
	if (nIDL == 0)
		return "None";
	for (int i = 0; i < nIDL;i++){
		string stmp = custerID[i];
		for (int j = 0; j < nL; j+=2){
			if (stmp.compare(recorder[i])){
				buyItems[i] = recorder[i + 2];
			}
		}
		int nItems = sizeof(buyItems) / sizeof(buyItems[0]);
		if (nItems == 1){
			bOnlyOneItem = true;
		}
		else{
			for (int k = 0; k < nItems; k++){
				if (buyItems[k].compare(buyItem)){
					return buyItems[k];
				}
			}
		}
	}
	if (!bOnlyOneItem)
		return "None";

	return buyItem;
}


#include <map>
#include <set>
#include <cstring>
#include <cstdio>

char* findMostlyBroughtItem(char* shippingRecordArray[], int length, char* givenItem);

inline bool isSpace(char x){
	return x == ' ' || x == '\r' || x == '\n' || x == '\f' || x == '\b' || x == '\t';
}

char * rightTrim(char *str){
	int len = strlen(str);
	while (--len >= 0){
		if (isSpace(str[len])){
			str[len] = '\0';
		}
		else{
			break;
		}
	}
	return str;
}

char * getInputLine(char *buffer, int length){
	if (fgets(buffer, length, stdin) == NULL){
		return NULL;
	}
	rightTrim(buffer);
	if (strlen(buffer) <= 0){
		return NULL;
	}
	return buffer;
}


int splitAndConvert(char* strings, char* array[]){
	char *next_token = NULL;
	char*tokenPtr = strtok_s(strings, " ", &next_token);
	int i = 0;
	while (tokenPtr != NULL){
		array[i] = tokenPtr;
		i++;
		tokenPtr = strtok_s(NULL, " ", &next_token);
	}
	return i;
}

void do_amazonItem1(){
	char givenItem[1000] = { 0 };
	while (getInputLine(givenItem, 1000)){
		char line[1000];
		getInputLine(line, 1000);

		char* shoppingRecordArray[1000] = { 0 };

		int length = splitAndConvert(line, shoppingRecordArray);
		if (length == 0){
			break;
		}


		char * item = findMostlyBroughtItem(shoppingRecordArray, length, givenItem);
		if (NULL != item)
		{   // ԭ��ϵͳ�ṩ�Ĵ��롣����û��NULL�ж�
			cout << item << endl;
			free(item);  // �Լ��ӵ�
		}
	}

}

void
print(pair<string, int> p) {
	string pFirst = p.first;
	int pSecond = p.second;
	cout << pFirst.c_str() << pSecond << endl;
	cout << "print what....." << endl;
}

//your code is here 
//���������д����ĵط���������ϵͳ�Ѿ��Զ���������������ֻ��һ����޸ġ�

char* findMostlyBroughtItem(char* shoppingRecordArray[], int length, char* givenItem)
{
	if (NULL == shoppingRecordArray || NULL == givenItem)
		return NULL;

	string obj_item(givenItem);
	// ���û���Ϣ �� ������Ʒ��Ϣ ����multimap record
	multimap<string, string> record;
	for (int i = 0; i < length; i += 2)
	{
		string customer(shoppingRecordArray[i]);
		string item(shoppingRecordArray[i + 1]);

		record.insert(pair<string, string>(customer, item));
	}

	// ��ȡ��������obj_item��Ʒ�Ŀͻ����Ƽ��� customers
	set<string> customers;
	for (map<string, string>::iterator it = record.begin(); it != record.end(); it++)
	{
		if (0 == (*it).second.compare(obj_item))
		{
			customers.insert((*it).first);
		}
	}
	// ���������¼ multimap record
	// ���ͻ����� �� ����set customers ���ڣ�����Ʒ����map result
	map<string, int> result;
	for (map<string, string>::iterator it = record.begin(); it != record.end(); it++)
	{
		for (set<string>::iterator ic = customers.begin(); ic != customers.end(); ic++)
		{
			if (0 == (*it).first.compare(*ic))
			{
				/*
				if (result.end() != result.find((*it).second))
				{
				result[(*it).second] += 1;
				}
				else
				result.insert(pair<string, int>((*it).second, 1));
				*/
				result[(*it).second] += 1;
				break;
			}
		}

	}


	pair<string, int> top("None", 0);
	// ����map result, Ѱ����󣬶���obj_item����Ʒ����
	for (map<string, int>::iterator it = result.begin(); it != result.end(); it++)
	{
		if (0 == (*it).first.compare(obj_item))
			continue;
		if ((*it).second > top.second)
			top = make_pair((*it).first, (*it).second);
	}

	//cout << "Top: " << top.first << "\t" << top.second << endl;
	print(top);
	char *p = (char *)malloc(top.first.length() + 1);
	if (NULL != p)
	{
		strcpy(p, top.first.c_str());
		return p;
	}

	return NULL;
}

#include <stack>
char* calculateOperationSequence(int * originalArray, int * resultArray, int length)
{
	if (NULL == originalArray || NULL == resultArray || length <= 0)
		return NULL;
	//ʹ��һ��ջģ����ջ�ͳ�ջ������ok�ˡ�
	string str;
	stack<int> st;
	int i = 0;
	int j = 0;
	st.push(originalArray[i]);


	char tmp[5] = "\0";
	str.append("push");
	sprintf(tmp, "%d", originalArray[i]);
	str.append(tmp);
	str.append("|");

	i++;

	while (!st.empty())
	{
		if (j < length && st.top() == resultArray[j])
		{
			str.append("pop");
			sprintf(tmp, "%d", resultArray[j]);
			str.append(tmp);
			str.append("|");
			st.pop();
			j++;

			if (i < length)
			{
				st.push(originalArray[i]);
				str.append("push");
				sprintf(tmp, "%d", originalArray[i]);
				str.append(tmp);
				str.append("|");
				i++;
			}
		}
		else
		{
			if (i < length)
			{
				st.push(originalArray[i]);
				str.append("push");
				sprintf(tmp, "%d", originalArray[i]);
				str.append(tmp);
				str.append("|");
				i++;
			}
			else
				break;
		}
	}


	if (!st.empty())
		return NULL;

	char *p = (char *)malloc(1 + str.length());
	if (NULL != p)
	{
		strcpy(p, str.c_str());
		p[str.length() - 1] = '\0';
		return p;
	}

	return NULL;
}


char* MycalculateOperationSequence(int *originalArray, int *resultArray, int length) {
	vector<string> tmpArry;
	string strout,strpush,strpop;
	string spush = "push";
	string spop = "pop";
	string sOriTmp,sResul;
	bool bReserve = false;

	for (int i = 0; i < length; i++){
		sOriTmp = originalArray[i];
		sResul = resultArray[i];
		//oriArry.push_back(originalArray[i]);
		if (sOriTmp.compare(sResul) ==0){
			strpush = spush + sOriTmp;
			strpop = spop + sOriTmp;
			strout += strpush + "|" + strpop;
			bReserve = false;
		}
		else{
			for (int j = 0; j < length; j++){
				sResul = resultArray[j];
				if (sOriTmp.compare(sResul)){
					continue;
				}
				if (i + j == length - 1)
				{
					bReserve = true;
					strpush = spush + sOriTmp + "|";
					strpop = spop + sOriTmp + "|";
					tmpArry.push_back(strpop);

			
				}
				else{
					bReserve = false;
				}
			}
		}
	}
	if (bReserve){
		;
		for (vector<string>::iterator it = tmpArry.begin(); it!=tmpArry.end();it++){
			strout += strpush + "|" + *it;
		}
	}
	char* pOut=new char[strout.length()+1];
	strcpy(pOut, strout.c_str());
	return pOut;
}


int splitAndConvert(char* strings, int *array){
	char* next_token=NULL;
	char*tokenPtr = strtok_s(strings, " ",&next_token);
	int i = 0;
	while (tokenPtr != NULL){
		array[i] = atoi(tokenPtr);
		i++;
		tokenPtr = strtok_s(NULL, " ",&next_token);
	}
	return i;
}

void do_getPushPopSequence()
{
	char line[1000] = { 0 };
	while (getInputLine(line, 1000)){
		int originalArray[30] = { 0 };
		int originalArrayLength = splitAndConvert(line, originalArray);
		if (originalArrayLength == 0){
			break;
		}

		getInputLine(line, 1000);
		int resultArray[30] = { 0 };
		int resultArrayLength = splitAndConvert(line, resultArray);
		if (resultArrayLength == 0){
			break;
		}
		char *operationSequence = calculateOperationSequence(originalArray, resultArray, resultArrayLength);

		if (NULL != operationSequence)
		{   // ԭ��ϵͳ�ṩ�Ĵ��롣����û��NULL�ж�
			cout << operationSequence << endl;
			free(operationSequence); // �Լ��ӵ�
		}
		else
			cout << "None" << endl; // �Լ��ӵ�
	}
}


/*
���������2���ڵ������������� end
*/


/*
��ͨ����������Ĺ�������
*/
#include "leedcode\commonTree.h"
void do_CommonTreeLCA()
{
	using namespace CommonTreeLCA;
	Test1();
//	Test2();
//	Test3();
//	Test4();

}
/*
��ͨ����������Ĺ�������
*/

/*
2��ͨ����������Ĺ�������2
*/
#include "leedcode\multiChildTree.h"
void do_MultiChildTreeLCA()
{
	using namespace MultiTreeLCA;

}

struct tNode{
	int x;
	struct tNode *left;
	struct tNode *right;

};

int path1[10000], path2[10000];
int top1 = -1, top2 = -1;
void createTree(tNode *&root){
	int x;
	scanf("%d", &x);
	if (!x)
		root = NULL;
	else{
		root = new tNode;
		root->x = x;
		createTree(root->left);
		createTree(root->right);
	}
}

bool getPath(tNode *root, int x, int path[], int &top){
	path[++top] = root->x;
	if (root->x == x)
		return true;
	bool found = false;
	if (root->left)
		found = getPath(root->left, x, path, top);
	if (!found && root->right)
		found = getPath(root->right, x, path, top);
	if (!found)
		top--;
	return found;
}

int getCommonNode(int path1[], int path2[]){
	int x;
	int i = 0, j = 0;
	while (i <= top1 && j <= top2){
		if (path1[i] == path2[j])
			x = path1[i];
		i++; j++;
	}
	return x;
}

void destory(tNode *&root){
	if (root){
		destory(root->left);
		destory(root->right);
		delete root;
		root = NULL;
	}
}

void print(tNode *root){
	if (root){
		printf("%d ", root->x);
		print(root->left);
		print(root->right);
	}
}

void do_biCheck(){

	int n, a, b;
	while (scanf("%d", &n) != EOF){
		while (n--){
			tNode *root;
			createTree(root);
			scanf("%d %d", &a, &b);
			top1 = -1; top2 = -1;
			if (!getPath(root, a, path1, top1)){
				printf("My God\n");
				continue;
			}
			if (!getPath(root, b, path2, top2)){
				printf("My God\n");
				continue;
			}
			
			printf("%d\n", getCommonNode(path1, path2));
			destory(root);
		}
	}
}

/*
2��ͨ����������Ĺ�������2
*/



#include "leedcode\calulateArrayValue.h"
#include "leedcode\SBITree2DoubleLinked.h"
#include "leedcode\STLSamples.h"
#include "leedcode\MyString.h"

using namespace MyString;
using namespace CalArrayValue;
using namespace Tree2DoubleLinked;
using namespace STLSamples;

void do_myString(){
	CMyString str = "";
	str = NULL;
	str = "123";
	
	CMyString s2 = str;

}
int main(){
	do_matrix();
	return 0;

	do_overload();
	return 0;

	do_myString();
	return 0;

	do_checkClassA();
	return 0;

	do_mainBase();
	return 0;

	do_checkCastX();
	return 0;

	do_nextPermutaion();
	return 0;

	do_cNextPermu();
	return 0;

	do_2nextPermutation();
	return 0;



	do_convert2();
	return 0;

	do_Convert();
	return 0;

	do_FindBackthNode();
	return 0;

	int nNode=get_Knode();
	cout << nNode << endl;
	return 0;

	StrToInt("389");
	return 0;

	do_calArraySum();
	return 0;

	do_cal();
	return 0;

	do_biCheck();
	return 0;

//	do_MultiChildTreeLCA();
//	return 0;

	do_CommonTreeLCA();
	return 0;

	do_BILCA();
	return 0;

	do_getLCFather();
	return 0;

	do_subTreeSum2();
	return 0;

	do_subTreeSum();
	return 0;


	do_setStorageCenter();
	return 0;

	do_getPushPopSequence();
	return 0;

	do_amazonItem1();
	//do_custmerShopping();
	system("pause");
	return 0;

	string str;
	getline(cin, str);
	cout << str << endl;
	system("pause");
	return 0;

	//do_queenBy10Line2();
	//do_queenBy10Line();
	do_queenByUsual();
	system("pause");
	return 0;

//	int a[] = { 3, 1, 5 };
//	int b[] = { 5, 9, 2 };
//	do_ListAddFromTail(a,b);
//	int a1[] = { 3, 1, 5 };
//	int b1[] = { 5, 9, 6 };
//	do_ListAddFromTail(a1, b1);

	//int a[] = { 1,1,1,1,1 };
	//int b[] = { 8, 8, 8,8,9 };

	int a[] = { 2,5,2,5,4,6,9,2,8,2,8,2 };
	int b[] = { 5,5,7,8,1,5,6,5,9,8,5 };
	
	int La = sizeof(a) / sizeof(a[0]);
	int Lb = sizeof(b) / sizeof(b[0]);
	do_ListAddFromHead(a,La, b,Lb);
//	do_ListAddFromHead();
//	do_reverseStr3("haha owawa   !luo");
//	do_reverseStr2("haha owawa  !luo");
//	do_reverseStr2("Hello! World!");
//	do_plus2Linked();
//	do_partitionArray();
//	int npos=do_separateArray();
//	do_reverseString();
//	do_linkedQueue();
//	do_tree();

//	t_myclass();
//	t_linearList();

//	do_chain();

//	do_Array1D();

//	do_Array2D();

//	do_expr();

//	do_tree();

//	system("pause");
	//t_curr2();
	return 1;
}