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
		for (i = 0; i < num - 3; i++)
			cout << " ";

		for (; i < num - 2; ++i)
			cout << "|";
		for (; i < num; ++i)
			cout << "_";
	}

	void Tree::print(TreeNode* node, int num)
	{
		if (node != NULL){
			printSpace(num);
			cout << node->element << endl;
			print(node->left, num + 4);
			print(node->right, num);
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
			preOrder(parent->left);
			preOrder(parent->right);
		}
	}

	//���䲢��ʼ�����е������
	Tree::Tree(int node_num)
	{
		int charsize = sizeof(char);
		int nodesize = sizeof(TreeNode);
		root = new TreeNode[node_num];

		char ch = 'A';

		for (int i = 0; i < node_num; ++i){
			root[i].element = ch + i;
			root[i].left = NULL;
			root[i].right = NULL;
		}

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

		if (parent->left == NULL)
			parent->left = node;
		else
			addBrotherNode(parent->left, node);
	}

	//���ڵ���뵽�ֵܽڵ�
	void Tree::addBrotherNode(TreeNode* bro, TreeNode* node)
	{
		if (bro->right == NULL)
			bro->right = node;
		else
			addBrotherNode(bro->right, node);
	}
}