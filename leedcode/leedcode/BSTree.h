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
{// ������kƥ���Ԫ��
	// ָ��p ��������ʼ���в���
	BinaryTreeNode<E> *p = root;
	while (p) // ���p - > d a t a
		if (k < p->data) p = p->LeftChild;
		else if (k > p->data) p = p->RightChild;
		else {// �ҵ�Ԫ��
			e = p->data;
			return true;
		}
		return false;
}


template<class E, class K>
BSTree<E, K>& BSTree<E, K>::Insert(const E& e)
{// ����������ظ��������e
		BinaryTreeNode<E> *p = root, // ����ָ��
		*pp = 0; // p�ĸ��ڵ�ָ��
	// Ѱ�Ҳ����
	while (p) {// ���p - > d a t a
		pp = p;
		// ��p�����ӽڵ�
		if (e < p->data) p = p->LeftChild;
		else if (e > p->data) p = p->RightChild;
		else throw BadInput(); // �����ظ�
	}
	// Ϊe ����һ���ڵ㣬�����ýڵ�������to pp
	BinaryTreeNode<E> *r = new BinaryTreeNode<E>(e);
	if (root) {// ���ǿ�
		if (e < pp->data) pp->LeftChild = r;
		else pp->RightChild = r;
	}
	else // ���뵽������
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
{// ɾ���ؼ�ֵΪk ��Ԫ�أ����������e
	// ��p ָ��ؼ�ֵΪk�Ľڵ�
	BinaryTreeNode<E> *p = root, // ����ָ��
		*pp = 0; // p�ĸ��ڵ�ָ��
	while (p && p->data != k){// �ƶ���p�ĺ���
		pp = p;
		if (k < p->data) p = p->LeftChild;
		else p = p->RightChild;
	}
	if (!p) throw BadInput(); // û�йؼ�ֵΪk��Ԫ��
	e = p->data; // ������ɾ����Ԫ��
	// ���������ع�
	// ����p���������ӵ�����
	if (p->LeftChild && p->RightChild) {// ��������
		// ת������0��1�����ӵ�����
		// ��p ����������Ѱ�����Ԫ��
		BinaryTreeNode<E> *s = p->LeftChild, *ps = p; // s�ĸ��ڵ�
		while (s->RightChild) {// �ƶ����ϴ��Ԫ��
			ps = s;
			s = s->RightChild;
		}
		// �����Ԫ�ش�s�ƶ���p
		p->data = s->data;
		p = s;
		pp = ps;
	}
	// p �����һ������
	// ��c �б��溢��ָ��
	BinaryTreeNode<E> *c;
	if (p->LeftChild) 
		c = p->LeftChild;
	else 
		c = p->RightChild;
	// ɾ��p
	if (p == root)
		root = c;
	else {// p ��p p�����ӻ���p p���Һ���?
		if (p == pp->LeftChild)
			pp->LeftChild = c;
		else pp->RightChild = c;
	}
	delete p;
	return *this;
}





