#ifndef BITree_HH
#define BITree_HH

#include <iostream>
using namespace std;

//Page 276
template <class T>
class BinaryTreeNode {

public:
	BinaryTreeNode() 
	{ 
		LeftChild = RightChild = 0; 
	}
	BinaryTreeNode(const T& e)
	{
		data = e;
		LeftChild = RightChild = 0;
	}
	BinaryTreeNode(const T& e, BinaryTreeNode *l,BinaryTreeNode *r)
	{
		data = e;
		LeftChild = l;
		RightChild = r;
	}
private:
	void NPreOrder(BinaryTreeNode<T> *t);
	void NPostOrder(BinaryTreeNode<T> *t);
	void NInOrder(BinaryTreeNode<T> *t);
	void NLevelOrder(BinaryTreeNode<T> *t);
public:
	BinaryTreeNode<T> *LeftChild, //������
		*RightChild; // ������
private:
	T data;

};



template <class T>
void BinaryTreeNode<T>::NPreOrder(BinaryTreeNode<T> *t)
{// ��* t����ǰ�����
	if (t) {
		Visit(t); // ���ʸ��ڵ�
		NPreOrder(t->LeftChild); // ǰ�����������
		NPreOrder(t->RightChild); // ǰ�����������
	}
}


template <class T>
void BinaryTreeNode<T>::NInOrder(BinaryTreeNode<T> *t)
{// ��* t�����������
	if (t) {
		NInOrder(t->LeftChild); // �������������
		Visit(t); // ���ʸ��ڵ�
		NInOrder(t->RightChild); // �������������
	}
}

template <class T>
void BinaryTreeNode<T>::NPostOrder(BinaryTreeNode<T> *t)
{// ��* t���к������
	if (t) {
		NPostOrder(t->LeftChild); // �������������
		NPostOrder(t->RightChild); // �������������
		Visit(t); // ���ʸ��ڵ�
	}
}

template <class T>
void BinaryTreeNode<T>::NLevelOrder(BinaryTreeNode<T> *t)
{// ��*t������
	LinkedQueue <BinaryTreeNode<T>*> Q;
	while (t) {
		Visit(t); // ����t
		// ��t���Һ��ӷ������
		if (t->LeftChild) Q.Add(t->LeftChild);
		if (t->RightChild) Q.Add(t->RightChild);
		//������һ���ڵ�
		try { Q.Delete(t); }
		catch (OutOfBounds) { return; }
	}
}

template<class T>
static void Visit(BinaryTreeNode<T> *t)
{
	cout << t->data << ' ';
}

#endif