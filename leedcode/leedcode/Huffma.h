template<class T>
class Huffman {
	friend BinaryTree<int> HuffmanTree(T[], int);
public :
	operator T () const { return weight; }
private :
	BinaryTree<int> tree;
	T weight;
};

template <class T>
BinaryTree<int> HuffmanTree(T a[], int n)
{// ����Ȩ��a[1:n]�����������
// ����һ�����ڵ���������
	Huffman<T> *w = new Huffman<T> [n+1];
	BinaryTree<int> z, zero;
	for (int i = 1; i <= n; i++) {
	z.MakeTree(i, zero, zero);
	w[i].weight = a[i];
	w[i].tree = z;
	}
	// ��������һ����С�Ķ�
	MinHeap < Huffman<T> > H(1);
	H.Initialize ( w, n , n ) ;
	// �����е������Ϻϲ�
	Huffman<T> x, y;
	for (i = 1; i < n; i++) {
		H.DeleteMin ( x ) ;
		H.DeleteMin ( y ) ;
		z.MakeTree(0, x.tree, y.tree );
		x.weight += y.weight; x.tree = z;
		H.Insert ( x );
	}
	H.DeleteMin(x); // ������
	H.Deactivate ( );
	delete [] w;
	return x.tree;
}

