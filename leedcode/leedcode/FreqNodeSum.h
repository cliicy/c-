#include <cstdlib>
#include <unordered_map>
#include <vector>

//找到出现频率最多的各个节点的和
namespace FreqTreeNodeSum{
	struct TreeNode {
		int val;
		TreeNode *left;
		TreeNode *right;
		TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	};

	int helper(TreeNode *rootIn, unordered_map<int, int> &tables) {
		if (!rootIn) {
			return 0;
		}

		int tmp = rootIn->val + helper(rootIn->left, tables) + helper(rootIn->right, tables);
		unordered_map<int, int>::const_iterator fitem = tables.find(tmp);
		unordered_map<int, int>::const_iterator tab = tables.end();
		if (tables.find(tmp) != tables.end()) {
			++tables[tmp];
		}
		else {
			tables[tmp] = 1;
		}

		return tmp;
	}

	vector<int> findFrequentTreeSum(TreeNode* root) {
		unordered_map<int, int> tables; //用散列表实现散列函数
		vector<int> res; //保存输出结果
		int sameTime = 0; //记录有多少个相同最高频率和
		int max = INT_MIN; //记录当前的最高频率

		if (!root) {
			return res;
		}

		helper(root, tables);

		for (auto n : tables) {
			if (n.second > max) {
				max = n.second;
				sameTime = 1;
			}
			else if (n.second == max) {
				++sameTime;
			}
		}

		res.resize(sameTime, 0);//res里保存的是出现频率最多的sum
		sameTime = 0;

		for (auto n : tables) {
			if (n.second == max) {
				res[sameTime++] = n.first;
			}
		}

		return res;
	}



	/*
	void freeTreeNode(TreeNode* treeNode){

		if (treeNode)
		{
			delete treeNode;
			treeNode = NULL;
		}
	}

	void destoryTree(TreeNode* root){
		if (root)
		{
			freeTreeNode(root->left);
			freeTreeNode(root->right);
			freeTreeNode(root);

		}

	}*/

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

	void do_subTreeSum(){
		TreeNode* root = new TreeNode(5);
		TreeNode* left = new TreeNode(2);
		TreeNode* right = new TreeNode(-3);
		root->left = left;
		root->right = right;
		findFrequentTreeSum(root);
		destory(root);
	}

	void do_subTreeSum2(){
		TreeNode* root = new TreeNode(5);
		TreeNode* left = new TreeNode(2);
		TreeNode* right = new TreeNode(-5);
		root->left = left;
		root->right = right;
		findFrequentTreeSum(root);
		destory(root);
	}
}