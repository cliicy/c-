#include <cstdlib>
#include <vector>
#include <list>

using namespace std;
namespace MultiTreeLCA{
	/*
	��ͨ����������Ĺ�������
	*/
	//Ѱ��·��
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

	//������·����Ѱ�����Ĺ����ڵ㣺
	mulTreeNode *GetLastCommonNode(const list<mulTreeNode*>&path1, const list<mulTreeNode*>&path2)
	{

		list<mulTreeNode*>::const_iterator iterator1 = path1.begin();

		list<mulTreeNode*>::const_iterator iterator2 = path2.begin();

		mulTreeNode* pLast = NULL;

		while (iterator1 != path1.end() && iterator2 != path2.end())

		{

			if (*iterator1 == *iterator2)//����ֵ��Ѱ�ң����ǽڵ㡣����ʵҲ�ǿ��԰��սڵ���Ѱ�ҵ�

				pLast = *iterator1;//���ﰴ���ҵ���� ҲӦ��ֱ�Ӹ�ֵ û�н����� ��Ϊ�������������һ��ָ�밡

			++iterator1; ++iterator2;

		}
		return pLast;

	}

	//Ѱ����С��������
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