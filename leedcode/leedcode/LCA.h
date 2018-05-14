/**
* 本参考程序来自九章算法，由 @九章算法 提供。版权所有，转发请注明出处。
* - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
* - 现有的面试培训课程包括：九章算法班，系统设计班，算法强化班，Java入门与基础算法班，Android 项目实战班，
* - Big Data 项目实战班，算法面试高频题班, 动态规划专题班
* - 更多详情请见官方网站：http://www.jiuzhang.com/?source=code
*/
#include <cstdlib>
#include <algorithm>

/**
* 本参考程序来自九章算法，由 @九章算法 提供。版权所有，转发请注明出处。
* - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
* - 现有的面试培训课程包括：九章算法班，系统设计班，算法强化班，Java入门与基础算法班，Android 项目实战班，
* - Big Data 项目实战班，算法面试高频题班, 动态规划专题班
* - 更多详情请见官方网站：http://www.jiuzhang.com/?source=code
*/ 

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param root: The root of the binary search tree.
     * @param A and B: two nodes in a Binary.
     * @return: Return the least common ancestor(LCA) of the two nodes.
     */
    int Atop, Btop, top;
    TreeNode *a[100000], *b[100000], *ans[100000];
    bool find;
    void inorder(TreeNode *node, TreeNode *A, int flag) { 
        if (find==true)
            return;
        if (node == NULL)
            return;
        ans[++top] = node;
        if (A == node) {
            find = true;
            if (flag == 0) {
                Atop = top;
                for (int i = 1; i <= top; ++i)
                    a[i] = ans[i];
            } else {
                Btop = top;
                for (int i = 1; i <= top; ++i)
                    b[i] = ans[i];
            }
            return;
        }

        inorder(node->left, A, flag);
        if (find) return;
            
        inorder(node->right, A, flag);
        if (find) return;
          
        top --;
        
    }
    TreeNode *leastCommonAncestor(TreeNode *root, TreeNode *A, TreeNode *B) {
        // write your code here
        top = 0; find = false;
        inorder(root, A, 0);

        top = 0; find = false;
        inorder(root, B, 1);
  
        Atop = min(Atop, Btop);
        Btop = Atop;

        while (a[Atop] != b[Btop]) {
            Atop --;
            Btop --;
        }
        return a[Atop];
    }
};

// Definition of TreeNode:
 class TreeNode {
 public:
     int val;
     TreeNode *left, *right;
     TreeNode(int val) {
         this->val = val;
         this->left = this->right = NULL;
     }
 };

class Solution {
public:
	/**
	* @param root: The root of the binary search tree.
	* @param A and B: two nodes in a Binary.
	* @return: Return the least common ancestor(LCA) of the two nodes.
	*/
	int Atop, Btop, top;
	TreeNode *a[100000], *b[100000], *ans[100000];
	bool find;
	void inorder(TreeNode *node, TreeNode *A, int flag) {
		if (find == true)
			return;
		if (node == NULL)
			return;
		ans[++top] = node;
		if (A == node) {
			find = true;
			if (flag == 0) {
				Atop = top;
				for (int i = 1; i <= top; ++i)
					a[i] = ans[i];
			}
			else {
				Btop = top;
				for (int i = 1; i <= top; ++i)
					b[i] = ans[i];
			}
			return;
		}

		inorder(node->left, A, flag);
		if (find) return;

		inorder(node->right, A, flag);
		if (find) return;

		top--;

	}
	TreeNode *leastCommonAncestor(TreeNode *root, TreeNode *A, TreeNode *B) {
		// write your code here
		top = 0; find = false;
		inorder(root, A, 0);

		top = 0; find = false;
		inorder(root, B, 1);

		Atop = min(Atop, Btop);
		Btop = Atop;

		while (a[Atop] != b[Btop]) {
			Atop--;
			Btop--;
		}
		return a[Atop];
	}
};