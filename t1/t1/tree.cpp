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

	// 前序遍历
	void Tree::preOrder()
	{
		cout << "前序遍历: ";
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

	//分配并初始化所有的树结点
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

	//释放所有节点的内存空间
	Tree::~Tree()
	{
		if (root != NULL)
			delete[] root;
	}

	//addNode将父子结点组对
	//如果父节点的firstChild==NULL, 则firstChild = node;
	//如果父节点的firstChild != NULL, 则
	void Tree::addNode(int i, int j)
	{
		TreeNode* parent = &root[i];
		TreeNode* node = &root[j];

		if (parent->left == NULL)
			parent->left = node;
		else
			addBrotherNode(parent->left, node);
	}

	//将节点插入到兄弟节点
	void Tree::addBrotherNode(TreeNode* bro, TreeNode* node)
	{
		if (bro->right == NULL)
			bro->right = node;
		else
			addBrotherNode(bro->right, node);
	}
}