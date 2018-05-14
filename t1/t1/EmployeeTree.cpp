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

	EmployeeTree::EmployeeTree(int nTotal){
		char* chName[14] = { "Steven", "YuanNing", "Wei Xiaojin", "Fan Zhihe", "Cliicy", "灰太狼", "Ge Langtai", "Jianjun", "XiaoYu", "Fengru", \
			"Alex", "Shuan", "Ellen", "Luo" };
		int nL = sizeof(chName) / sizeof(char*);
		root = new EmployeeNode[14];
		memset(root, 0, sizeof(EmployeeNode)*nL);

		char* chFile[14][3] = { { "employ.txt", "company.jpg", "plan.txt" }, { "Ning.txt", "Ning.jpg" ,"NingDesign.txt"}, { "Xiaojin.txt", "Xiaojin.jpg","JinCode.txt" }, { "Zhihe.txt", "Zhihe.jpg" ,""},\
		{ "Cliicy.txt", "","" }, { "灰太狼.txt", "灰太狼.jpg" ,""}, { "Langtai.txt", "Langtai.jpg","" },{ "", "Jianjun.jpg","" },{ "XiaoYu.txt", "XiaoYu.jpg","" }, { "Fengru.txt", "Fengru.jpg","" },\
		{ "", "Alex.jpg","" }, { "Shuan.txt", "Shuan.jpg" ,"ShuanCode.txt"}, { "Ellen.txt", "Ellen.jpg","EllenBug.txt" }, { "Luo.txt", "Luo.jpg","LuoFix.txt" }};

		char* chID[14] = { "stev01", "yuan01", "xiaojin01", "fan01", "luocl01", "huilang01", "Langt02", "jjluo08", "xiaoyu01", "jifen01", \
			"alex01", "shuan01", "ellen06", "luoju01" };

		for (int i = 0; i < nL; i++){
			string sTmp = chName[i];
			string sKey = chID[i];
			strcpy(root[i].chName, sTmp.c_str());
			strcpy(root[i].pmfkey, sKey.c_str());
			for (int k = 0; k < 3; k++){
				string stmp = chFile[i][k];
				root[i].chFiles[k]=chFile[i][k];
			}
		}
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
			strcpy(root[i].chName,sName.c_str());
			//root[i].pmfkey = itoa(i);
			root[i].chFiles[0] = "";
			root[i].chFiles[1] = "";
			root[i].chFiles[2] = "";
			root[i].firstChild = NULL;
			root[i].nextSibling = NULL;
		}
	}

	//addNode将父子结点组对
	//如果父节点的firstChild==NULL, 则firstChild = node;
	//如果父节点的firstChild != NULL, 则
	void EmployeeTree::addChildNode(int i, int j){
		EmployeeNode* parent = &root[i];
		EmployeeNode* node = &root[j];

		if (parent->firstChild == NULL)
			parent->firstChild = node;
		else
			addBrotherNode(parent->firstChild, node);
	}


	//将节点插入到兄弟节点
	void EmployeeTree::addBrotherNode(EmployeeNode* bro, EmployeeNode* node)
	{
		if (bro->nextSibling == NULL)
			bro->nextSibling = node;
		else
			addBrotherNode(bro->nextSibling, node);
	}

	void EmployeeTree::print(){
		printEmployees(root, 0);

	}

	void EmployeeTree::printEmployees(const EmployeeNode* pNode, int nSpace){
		if (pNode == NULL) return;
		printSpace(nSpace);
		cout << pNode->chName << " " << pNode->pmfkey << "  (" << pNode->chFiles[0] << " " << pNode->chFiles[1] << " " << pNode->chFiles[0] << ")" << endl;
		//cout << pNode->chName << endl;
		printEmployees(pNode->firstChild, nSpace + 4);
		printEmployees(pNode->nextSibling, nSpace);
	}

	//void EmployeeTree::printEmployee(int nFileType){
	//	switch (nFileType)
	//	{
	//		case 0://document
	//			cout << "Will print node that owing documents files:" << endl;
	//			printDOCEmployees(root, 0);
	//			break;
	//		case 1://image
	//			cout << "Will print node that owing images files:" << endl;
	//			break;
	//	
	//	}


	//}

	void EmployeeTree::printEmployee(const EmployeeNode* pNode, int nFileType, int nSpace){
		if (pNode == NULL) return;
		bool bFind = false;
		string s1 = pNode->chFiles[0];
		string s2 = pNode->chFiles[1];
		string s3 = pNode->chFiles[2];

		if (nFileType == 0){
			int nP1 = s1.find(DOCF);
			int nP2 = s2.find(DOCF);
			int nP3 = s3.find(DOCF);

			if (nP1 != -1 || nP2 != -1 || nP3 != -1)
				bFind = true;
		}
		else if (nFileType == 1){
			int nP1 = s1.find(IMAGEF);
			int nP2 = s2.find(IMAGEF);
			int nP3 = s3.find(IMAGEF);

			if (nP1 != -1 || nP2 != -1 || nP3 != -1)
				bFind = true;
		}
		

		if (!bFind) return;

		printSpace(nSpace);
		cout << pNode->chName << "  (" << pNode->chFiles[0] << " " << pNode->chFiles[1] << " " << pNode->chFiles[2] << ")" << endl;
		//cout << pNode->chName << endl;
		printEmployee(pNode->firstChild, nFileType, nSpace + 4);
		printEmployee(pNode->nextSibling, nFileType, nSpace);
	}

	void EmployeeTree::print(int nFileType){
		printEmployee(root, nFileType, 0);
	}
	

	void EmployeeTree::resignation(const char* pmfkey){
		assert(root);
	
		string sRootkey(root[0].pmfkey);
		if (sRootkey.compare(pmfkey) == 0){
			cout << "Ignore we need keep the root node" << endl;
		}
		else{
			childresign(root, pmfkey);
		}

		
	}


int EmployeeTree::childresign(EmployeeNode* pNode, const char pmfkey[]){
	
	if (pNode != NULL){
		//printSpace(nSpace);
		string sNodekey = pNode->pmfkey;
		string sResign = pmfkey;

		if (sNodekey.compare(pmfkey) != 0){
			cout << pNode->chName << " " << pNode->pmfkey << endl;
			childresign(pNode->firstChild, pmfkey);
			childresign(pNode->nextSibling, pmfkey);
		}
		else if (sNodekey.compare(pmfkey) == 0){
			cout << pmfkey << " already quit" << endl;
			strcat(pNode->chName, " vacancy");
			cout << pNode->chName << endl;
			pNode->bResigned = true;
			return 1;
		}
		
	}
	return 0;
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

	static void Visit(EmployeeTree* pNode)
	{
		cout << "data" << endl;
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
