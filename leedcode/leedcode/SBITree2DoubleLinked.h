#include <iostream>  
#include <stdlib.h>  
#include <time.h>  
namespace Tree2DoubleLinked{
using std::cout;
using std::cin;
using std::endl;
struct BSNode
{
	//��������������Ľ��ṹ  
	BSNode *left;
	BSNode *right;
	int data;
};
//��������õ���������  
typedef BSNode* BSTree;
typedef BSNode* DList;
typedef BSNode DLNode;
//������������tree�в���ֵΪdata�Ľ��  
BSTree InsertNode(BSTree tree, int data);
//�Ѷ���������treeת����˫����������ͷ���  
DList BSTreeToList(BSTree tree);
//��������������tree�ĸ������,������ָ�����  
void ConvertNode(BSTree tree, BSNode **last_node);
//���Ҷ���������tree��������  
BSNode* FindLeftmostNode(BSTree tree);
//�������������������tree  
void PrintBiTree(BSTree tree);
//�������  
void PrintList(DList list);
BSTree InsertNode(BSTree tree, int data)
{
	if (tree == NULL)
	{
		//�ҵ�����㣬�����  
		tree = new BSNode;
		tree->left = NULL;
		tree->right = NULL;
		tree->data = data;
	}
	//����������������  
	else if (tree->data < data)
		tree->right = InsertNode(tree->right, data);
	//����������������  
	else if (tree->data > data)
		tree->left = InsertNode(tree->left, data);
	return tree;
}
DList BSTreeToList(BSTree tree)
{
	if (tree == NULL)
		return NULL;
	//�ҵ�����ߵĽ�㣬��ת���������ͷ���  
	DLNode *head = FindLeftmostNode(tree);
	BSNode *last_node = NULL;
	//����ת��  
	ConvertNode(tree, &last_node);
	return head;
}
BSNode* FindLeftmostNode(BSTree tree)
{
	if (tree == NULL)
		return NULL;
	while (tree->left != NULL)
		tree = tree->left;
	return tree;
}
void ConvertNode(BSTree tree, BSNode **last_node)
{
	if (tree == NULL)
		return;
	//��tree������������ת����last_node��ת�����������һ������ָ��  
	if (tree->left != NULL)
		ConvertNode(tree->left, last_node);
	//����tree��leftָ�룬ָ����һ�����  
	tree->left = *last_node;
	//����ָ�����һ����㣬rightָ����һ�����  
	if (*last_node != NULL)
		(*last_node)->right = tree;
	//����ָ���������һ������ָ��  
	*last_node = tree;
	//��tree������������ת����last_node��ת�����������һ������ָ��  
	if (tree->right != NULL)
		ConvertNode(tree->right, last_node);
}
void PrintBSTree(BSTree tree)
{
	if (tree == NULL)
		return;
	PrintBSTree(tree->left);
	cout << tree->data << " ";
	PrintBSTree(tree->right);
}
void PrintList(DList list)
{
	DLNode *node = list;
	while (node != NULL)
	{
		cout << node->data << " ";
		node = node->right;
	}
}
void do_Convert()
{
	BSTree tree = NULL;
	srand(time(NULL));
	cout << "Insert Data Order is:" << endl;
	for (int i = 0; i < 10; ++i)
	{
		//���������10���������ɶ���������  
		int data = rand() % 100;
		cout << data << " ";
		tree = InsertNode(tree, data);
	}
	cout << "\nThe BSTree is: " << endl;
	PrintBSTree(tree);
	//����ת��  
	tree = BSTreeToList(tree);
	cout << "\nBiTree To List: " << endl;
	PrintList(tree);
}


#include <stdio.h>
#include <stdlib.h>
struct BSTreeNode
{
	int m_iValue;
	BSTreeNode *m_pLeft;
	BSTreeNode *m_pRight;
};
BSTreeNode *pHead = NULL;   //ָ��˫�������ͷ���
BSTreeNode *pLast = NULL;    //�ڽ���˫������Ĺ����У�ʼ��ָ��˫����������һ���ڵ㡣

void AddBSTreeNode(BSTreeNode *&root, int value)  //��������������
{
	if (root == NULL)
	{
		root = new BSTreeNode;
		root->m_iValue = value;
		root->m_pLeft = NULL;
		root->m_pRight = NULL;
		return;
	}
	if (value<root->m_iValue)
		AddBSTreeNode(root->m_pLeft, value);
	else if (value > root->m_iValue)
		AddBSTreeNode(root->m_pRight, value);
}
void AdjustPointer(BSTreeNode *pCurrent)//Ҫ������ǰ�ڵ��ָ��
{
	if (pLast == NULL)  //���һ���ڵ㲻���ڣ�˵��˫������û�н���������
	{
		pHead = pCurrent;
	}
	else                       //���һ���ڵ����
		pLast->m_pRight = pCurrent;

	pCurrent->m_pLeft = pLast;
	pLast = pCurrent;
}

void MidTraverseBSTree(BSTreeNode *root)
{
	if (root == NULL)
		return;

	if (root->m_pLeft != NULL)
		MidTraverseBSTree(root->m_pLeft);

	AdjustPointer(root);

	if (root->m_pRight != NULL)
		MidTraverseBSTree(root->m_pRight);
}



void do_convert2()
{
	BSTreeNode *root = NULL;
	AddBSTreeNode(root, 10);
	AddBSTreeNode(root, 6);
	AddBSTreeNode(root, 14);
	AddBSTreeNode(root, 4);
	AddBSTreeNode(root, 8);
	AddBSTreeNode(root, 12);
	AddBSTreeNode(root, 16);

	MidTraverseBSTree(root);

	BSTreeNode *p;
	//��֤������˫������Ӧ�õ��ڶ�����������������
	for (p = pHead; p != NULL; p = p->m_pRight)
		printf("%d,", p->m_iValue);
	printf("\n");
}


}