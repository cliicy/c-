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
{// 根据权重a[1:n]构造霍夫曼树
// 创建一个单节点树的数组
	Huffman<T> *w = new Huffman<T> [n+1];
	BinaryTree<int> z, zero;
	for (int i = 1; i <= n; i++) {
	z.MakeTree(i, zero, zero);
	w[i].weight = a[i];
	w[i].tree = z;
	}
	// 把数组变成一个最小的堆
	MinHeap < Huffman<T> > H(1);
	H.Initialize ( w, n , n ) ;
	// 将堆中的树不断合并
	Huffman<T> x, y;
	for (i = 1; i < n; i++) {
		H.DeleteMin ( x ) ;
		H.DeleteMin ( y ) ;
		z.MakeTree(0, x.tree, y.tree );
		x.weight += y.weight; x.tree = z;
		H.Insert ( x );
	}
	H.DeleteMin(x); // 最后的树
	H.Deactivate ( );
	delete [] w;
	return x.tree;
}

