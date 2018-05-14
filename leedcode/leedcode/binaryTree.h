#ifndef BinaryTree_HH
#define BinaryTree_HH

#include "BItreenode.h"

template<class T>
class BinaryTree {
public:
	BinaryTree() { root = 0; };
	~BinaryTree() { };
	bool IsEmpty() const
	{
		reurn((root) ? false : true);
	}
	bool Root(T& x) const;
	void MakeTree(const T& element, BinaryTree<T>& left, BinaryTree<T>& right);
	void BreakTree(T& element, BinaryTree<T>& left, BinaryTree<T>& right);
	void PreOrder(void(*Output) (BinaryTreeNode<T> *u))
	{
		PreOrder(Output, root);
	}
	void Inorder(void(*Output) (BinaryTreeNode<T> *u))
	{
		InOrder(Output, root);
	}
	void PostOrder(void(*Output) (BinaryTreeNode<T> *u))
	{
		Postorder(Output, root);
	}

	void LevelOrder(void(*Output) (BinaryTreeNode<T> *u));

private:
	BinaryTreeNode<T> *root; // 根节点指针
	void PreOrder(void(*Output) (BinaryTreeNode<T> *u), BinaryTreeNode<T> *t);
	void InOrder(void(*Output) (BinaryTreeNode<T> *u), BinaryTreeNode<T> *t);
	void PostOrder(void(*Output) (BinaryTreeNode<T> *u), BinaryTreeNode<T> *t);
	void ct(BinaryTreeNode<T> *t);
};

template<class T>
void BinaryTree<T>::ct(BinaryTreeNode<T> *t) {
	//count++; 
}

template<class T>
bool BinaryTree<T>::Root(T& x) const
{// 取根节点的data域，放入x
	// 如果没有根节点，则返回f a l s e
	if (root) {
		x = root->data;
		return true;
	}
	else return false; // 没有根节点
}

template<class T>
void BinaryTree<T>::MakeTree(const T& element, BinaryTree<T>& left, BinaryTree<T>& right)
{// 将left, right和element 合并成一棵新树
	// left, right和t h i s必须是不同的树
	// 创建新树
	root = new BinaryTreeNode <T>
		(element, left.root, right.root);
	// 阻止访问left 和right
	left.root = right.root = 0;
}

template<class T>
void BinaryTree<T>::BreakTree(T& element, BinaryTree<T>& left, BinaryTree<T>& right)
{// left, right和t h i s必须是不同的树
	// 检查树是否为空
	if (!root) throw BadInput(); // 空树
	// 分解树
	element = root->data;
	left.root = root->LeftChild;
	right.root = root->RightChild;
	delete root;
	root = 0;
}


template<class T>
void BinaryTree<T>::PreOrder(void(*Output) (BinaryTreeNode<T> *u), BinaryTreeNode<T> *t)
{// 前序遍历
	if (t) {
		Output(t);
		PreOrder(Output, t->LeftChild);
		PreOrder(Output, t->RightChild);
	}
}
template <class T>
void BinaryTree<T>::InOrder(void(*Output) (BinaryTreeNode<T> *u), BinaryTreeNode<T> *t)
{// 中序遍历
	if (t) {
		InOrder(Output, t->LeftChild);
		Output(t);
		InOrder(Output, t->RightChild);
	}
}
template <class T>
void BinaryTree<T>::PostOrder(void(*Output) (BinaryTreeNode<T> *u), BinaryTreeNode<T> *t)
{// 后序遍历
	if (t) {
		PostOrder(Visit, t->LeftChild);
		PostOrder(Visit, t->RightChild);
		Output(t);
	}
}


template<class T>
void BinaryTree<T>::LevelOrder(void(*Output) (BinaryTreeNode<T> *u))
{// 逐层遍历
	LinkedQueue <BinaryTreeNode<T>*> Q;
	BinaryTreeNode<T> *t;
	t = root;
	while (t) {
		Output(t);
		if (t->LeftChild) Q.Add(t->LeftChild);
		if (t->RightChild) Q.Add(t->RightChild);
		try { Q.Delete(t); }
		catch (OutOfBounds) { return; }
	}
}

template<class T>
static void Output(BinaryTreeNode<T> *t)
{
	cout << t->data << ' ';
}

#endif