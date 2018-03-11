#include "iostream"
#include "tree.h"
#include "cstdlib"

using namespace std;

namespace treetask {

	void Tree::print(){
		print(root, 0);
	}

	void printSpace(int num) {
		int i = 0;
		for (i = 0; i < num - 2; i++)
			cout << " ";

		for (; i < num - 1; ++i)
			cout << "|";
		for (; i < num; ++i)
			cout << "_";
	}

	void Tree::print(TreeNode* node, int num)
	{
		if (node != NULL){
			printSpace(num);
			cout << node->element << endl;
			print(node->firstChild, num + 4);
			print(node->nextSibling, num);
		}
	}

	// ǰ�����
	void Tree::preOrder()
	{
		cout << "ǰ�����: ";
		preOrder(root);
		cout << endl;
	}

	void Tree::preOrder(TreeNode* parent)
	{
		if (parent != NULL){
			cout << parent->element << " ";
			preOrder(parent->firstChild);
			preOrder(parent->nextSibling);
		}
	}

	//���䲢��ʼ�����е������
	Tree::Tree(int node_num)
	{
		int charsize = sizeof(char);
		int nodesize = sizeof(TreeNode);
		root = new TreeNode[node_num];
		int nroot = sizeof(root);

		memset(root, 0, nodesize*node_num);

		char* chName[14] = {"Steven","YuanNing","Wei Xiaojin","Fan Zhihe","Cliicy","��̫��","Ge Langtai","Jianjun","XiaoYu","Fengru",\
							"Alex","Shuan","Ellen","Luo"};
		string stmp = "";
		for (int i = 0; i < node_num; ++i){
			TreeNode node = root[i];
			stmp = chName[i];
			strcpy(root[i].element, stmp.c_str());
			cout << root[i].element << " " << i << endl;
		}

		//char ch = 'A';

		//for (int i = 0; i < node_num; ++i){
		//	root[i].element = ch + i;
		//	root[i].firstChild = NULL;
		//	root[i].nextSibling = NULL;
		//}

	}

	//�ͷ����нڵ���ڴ�ռ�
	Tree::~Tree()
	{
		if (root != NULL)
			delete[] root;
	}

	//addNode�����ӽ�����
	//������ڵ��firstChild==NULL, ��firstChild = node;
	//������ڵ��firstChild != NULL, ��
	void Tree::addNode(int i, int j)
	{
		TreeNode* parent = &root[i];
		TreeNode* node = &root[j];

		if (parent->firstChild == NULL)
			parent->firstChild = node;
		else
			addBrotherNode(parent->firstChild, node);
	}

	//���ڵ���뵽�ֵܽڵ�
	void Tree::addBrotherNode(TreeNode* bro, TreeNode* node)
	{
		if (bro->nextSibling == NULL)
			bro->nextSibling = node;
		else
			addBrotherNode(bro->nextSibling, node);
	}
}