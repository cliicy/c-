template<class E, class K>
class BSTree : public BinaryTree<E> {
	public :
	bool Search(const K& k, E& e) const;
	BSTree<E, K>& Insert(const E& e);
	BSTree<E, K>& Delete(const K& k, E& e);
	void Ascend() { InOutput(); }
};


template<class E, class K>
bool BSTree<E, K>::Search(const K& k, E &e) const
{// 搜索与k匹配的元素
	// 指针p 从树根开始进行查找
	BinaryTreeNode<E> *p = root;
	while (p) // 检查p - > d a t a
		if (k < p->data) p = p->LeftChild;
		else if (k > p->data) p = p->RightChild;
		else {// 找到元素
			e = p->data;
			return true;
		}
		return false;
}


template<class E, class K>
BSTree<E, K>& BSTree<E, K>::Insert(const E& e)
{// 如果不出现重复，则插入e
		BinaryTreeNode<E> *p = root, // 搜索指针
		*pp = 0; // p的父节点指针
	// 寻找插入点
	while (p) {// 检查p - > d a t a
		pp = p;
		// 将p移向孩子节点
		if (e < p->data) p = p->LeftChild;
		else if (e > p->data) p = p->RightChild;
		else throw BadInput(); // 出现重复
	}
	// 为e 建立一个节点，并将该节点连接至to pp
	BinaryTreeNode<E> *r = new BinaryTreeNode<E>(e);
	if (root) {// 树非空
		if (e < pp->data) pp->LeftChild = r;
		else pp->RightChild = r;
	}
	else // 插入到空树中
		root = r;
	return *this;
}

/* page 345
while (p) {
pp = p;
if (e <= p->data) p = p->LeftChild;
else p = p->RightChild;
}
*/

template<class E, class K>
BSTree<E, K>& BSTree<E, K>::Delete(const K& k, E& e)
{// 删除关键值为k 的元素，并将其放入e
	// 将p 指向关键值为k的节点
	BinaryTreeNode<E> *p = root, // 搜索指针
		*pp = 0; // p的父节点指针
	while (p && p->data != k){// 移动到p的孩子
		pp = p;
		if (k < p->data) p = p->LeftChild;
		else p = p->RightChild;
	}
	if (!p) throw BadInput(); // 没有关键值为k的元素
	e = p->data; // 保存欲删除的元素
	// 对树进行重构
	// 处理p有两个孩子的情形
	if (p->LeftChild && p->RightChild) {// 两个孩子
		// 转换成有0或1个孩子的情形
		// 在p 的左子树中寻找最大元素
		BinaryTreeNode<E> *s = p->LeftChild, *ps = p; // s的父节点
		while (s->RightChild) {// 移动到较大的元素
			ps = s;
			s = s->RightChild;
		}
		// 将最大元素从s移动到p
		p->data = s->data;
		p = s;
		pp = ps;
	}
	// p 最多有一个孩子
	// 在c 中保存孩子指针
	BinaryTreeNode<E> *c;
	if (p->LeftChild) 
		c = p->LeftChild;
	else 
		c = p->RightChild;
	// 删除p
	if (p == root)
		root = c;
	else {// p 是p p的左孩子还是p p的右孩子?
		if (p == pp->LeftChild)
			pp->LeftChild = c;
		else pp->RightChild = c;
	}
	delete p;
	return *this;
}





