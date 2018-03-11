#include <assert.h>
#include <iostream>
#include "EmployeeTree.h"


using namespace std;

namespace EmployeeTreeFiled {
	EmployeeTree::EmployeeTree()
	{
	}


	EmployeeTree::~EmployeeTree()
	{
	}

	EmployeeTree::EmployeeTree(EmployeeNode* pNode){

	}

	void EmployeeTree::createTree(int nTotalSum){
		assert(nTotalSum > 0);
		root = new EmployeeNode[nTotalSum];

		char* chTemp = "cliicy_company";
		string sName = "";
		for (int i = 0; i < nTotalSum; i++){
			char* nameBuff=NULL;
			char* chTmp = _itoa(i, nameBuff,i);
			sName = strcat(chTemp, chTmp);
			root[i].chName = sName;
			root[i].pmfkey = i;
			root[i].chFiles[0] = "";
			root[i].chFiles[1] = "";
			root[i].chFiles[2] = "";
			root[i].left = NULL;
			root[i].right = NULL;
		}
	}

	//addNode将父子结点组对
	//如果父节点的firstChild==NULL, 则firstChild = node;
	//如果父节点的firstChild != NULL, 则
	void EmployeeTree::createChildTree(int i, int j){
		EmployeeNode* parent = &root[i];
		EmployeeNode* node = &root[j];

		if (parent->left == NULL)
			parent->left = node;
		else
			addBrotherNode(parent->left, node);
	}


	//将节点插入到兄弟节点
	void EmployeeTree::addBrotherNode(EmployeeNode* bro, EmployeeNode* node)
	{
		if (bro->right == NULL)
			bro->right = node;
		else
			addBrotherNode(bro->right, node);
	}

	void EmployeeTree::print_employees(EmployeeNode & head){

	}

	void EmployeeTree::print_Employee(int nFileType){

	}
	void EmployeeTree::resignation(const char pmfkey){

	}
	void EmployeeTree::promote(const char pmfkey){

	}

	void EmployeeTree::printSpace(int nSpace){
		int i;
		for (i = 0; i < nSpace - 2; ++i){
			cout << " " ;
		}

		for (; i < nSpace - 1; ++i){
			cout << "|";
		}

		for (; i < nSpace; ++i) {
			cout << "_";
		}
	}

	void EmployeeTree::print_test(int nSpace)
	{
	/*	int i = 1;
		do{
			if (i>2) break;
			printSpace(nSpace);
			cout << "hello" << endl;
			print_test(nSpace + 4);
			i++;
		} while (true);*/

	}
}

/*
int i = 0;
for (i = 0; i < num - 3; i++)
	cout << " ";

for (; i < num - 2; ++i)
	cout << "|";
for (; i < num; ++i)
	cout << "_";
	
	*/
