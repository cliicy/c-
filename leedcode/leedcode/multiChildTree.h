#include <cstdlib>
#include <vector>
#include <list>

using namespace std;
namespace MultiTreeLCA{
	/*
	普通树中求最近的公共祖先
	*/
	//寻找路经
	struct mulTreeNode {
		int val;
		vector<mulTreeNode*> m_vChildren;
		mulTreeNode(int x) : val(x){}
	};
	bool GetNodePath(mulTreeNode *pRoot, mulTreeNode *pNode, list<mulTreeNode*>&path){

		if (pRoot == pNode)

			return true;

		path.push_back(pRoot);

		bool found = false;

		vector<mulTreeNode*>::iterator i = pRoot->m_vChildren.begin();

		while (!found && i != pRoot->m_vChildren.end())

		{
			found = GetNodePath(*i, pNode, path); ++i;
		}

		if (!found)

			path.pop_back();

		return found;

	}

	//在两个路经中寻找最后的公共节点：
	mulTreeNode *GetLastCommonNode(const list<mulTreeNode*>&path1, const list<mulTreeNode*>&path2)
	{

		list<mulTreeNode*>::const_iterator iterator1 = path1.begin();

		list<mulTreeNode*>::const_iterator iterator2 = path2.begin();

		mulTreeNode* pLast = NULL;

		while (iterator1 != path1.end() && iterator2 != path2.end())

		{

			if (*iterator1 == *iterator2)//按照值在寻找，而非节点。。其实也是可以按照节点来寻找的

				pLast = *iterator1;//这里按照我的理解 也应该直接赋值 没有解引用 因为迭代器本身就是一个指针啊

			++iterator1; ++iterator2;

		}
		return pLast;

	}

	//寻找最小公共祖先
	mulTreeNode *GetLastCommonParent(mulTreeNode* pRoot, mulTreeNode* pNode1, mulTreeNode* pNode2)
	{
		if (pRoot == NULL || pRoot == pNode1 || pRoot == pNode2)
			return pRoot;

		if (pNode1 == pNode2)  return pNode1;

		list<mulTreeNode*> path1, path2;

		GetNodePath(pRoot, pNode1, path1);

		GetNodePath(pRoot, pNode2, path2);

		return GetLastCommonNode(path1, path2);
	}
}