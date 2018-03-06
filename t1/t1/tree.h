#pragma once

/* Definition for a binary tree node.
/* struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
*/
namespace treetask {
#define TYPE char
struct TreeNode{
	TYPE element;
	TreeNode* left;// firstChild;
	TreeNode* right;// nextSibling;
};

class Tree
{
	public:
		Tree(TreeNode* r = NULL) :root(r){}
		Tree(int node_num);

		~Tree();
		void addNode(int i, int j);
		void preOrder();
		void print();

private:
	void print(TreeNode* node, int num);
	void addBrotherNode(TreeNode* bro, TreeNode* node);
	void preOrder(TreeNode* parent);

private:
	TreeNode* root;
};
}


