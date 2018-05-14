#include <iostream>
using namespace std;

/*
求二叉树的2个节点的最近公共祖先 start
*/
namespace BISearchTreeLCA{
	struct TreeNode {
		int val;
		TreeNode *left;
		TreeNode *right;
		TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	};

	bool ischild(TreeNode *pa, TreeNode *ch)
	{
		if (ch == pa || pa == nullptr)
			return false;
		if (pa->left == ch || pa->right == ch)
			return true;
		return ischild(pa->left, ch) || ischild(pa->right, ch);
	}
	TreeNode* find_pa(TreeNode* root, TreeNode*cur)
	{
		if (root->left == cur || root->right == cur)
			return root;
		if (ischild(root->left, cur))
			return find_pa(root->left, cur);
		else
			return find_pa(root->right, cur);
	}

	void destory(TreeNode * root)
	{
		if (root)
		{
			destory(root->left);
			destory(root->right);
			delete root;
			root = NULL;
		}
	}

	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (p == q)
			return q;
		if (ischild(p, q))
			return p;
		if (ischild(q, p))
			return q;
		TreeNode *p_pa = find_pa(root, p);
		TreeNode *q_pa = find_pa(root, q);
		if (ischild(p_pa, q_pa) || p_pa == q_pa)
			return p_pa;
		else if (ischild(q_pa, p_pa))
			return q_pa;
		else
			return lowestCommonAncestor(root, p_pa, q_pa);
	}

	void do_BILCA(){
		TreeNode* root = new TreeNode(5);
		TreeNode* left = new TreeNode(2);
		TreeNode* tmp = new TreeNode(7);
		TreeNode* sevenLeft = new TreeNode(3);
		tmp->left = sevenLeft;

		TreeNode* tmp1 = new TreeNode(6);
		left->left = tmp;
		left->right = tmp1;

		TreeNode* right = new TreeNode(-3);
		TreeNode* tmp2 = new TreeNode(1);
		right->left = tmp2;

		root->left = left;
		root->right = right;

		TreeNode* lcaNode = lowestCommonAncestor(root, sevenLeft, tmp2);
		cout << lcaNode->val << endl;
	}
}