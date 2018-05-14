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
	BinaryTreeNode<T> *LeftChild, //左子树
		*RightChild; // 右子树
private:
	T data;

};



template <class T>
void BinaryTreeNode<T>::NPreOrder(BinaryTreeNode<T> *t)
{// 对* t进行前序遍历
	if (t) {
		Visit(t); // 访问根节点
		NPreOrder(t->LeftChild); // 前序遍历左子树
		NPreOrder(t->RightChild); // 前序遍历右子树
	}
}


template <class T>
void BinaryTreeNode<T>::NInOrder(BinaryTreeNode<T> *t)
{// 对* t进行中序遍历
	if (t) {
		NInOrder(t->LeftChild); // 中序遍历左子树
		Visit(t); // 访问根节点
		NInOrder(t->RightChild); // 中序遍历右子树
	}
}

template <class T>
void BinaryTreeNode<T>::NPostOrder(BinaryTreeNode<T> *t)
{// 对* t进行后序遍历
	if (t) {
		NPostOrder(t->LeftChild); // 后序遍历左子树
		NPostOrder(t->RightChild); // 后序遍历右子树
		Visit(t); // 访问根节点
	}
}

template <class T>
void BinaryTreeNode<T>::NLevelOrder(BinaryTreeNode<T> *t)
{// 对*t逐层遍历
	LinkedQueue <BinaryTreeNode<T>*> Q;
	while (t) {
		Visit(t); // 访问t
		// 将t的右孩子放入队列
		if (t->LeftChild) Q.Add(t->LeftChild);
		if (t->RightChild) Q.Add(t->RightChild);
		//访问下一个节点
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