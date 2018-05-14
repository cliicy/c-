
//page 300
template<class T>
class MaxHeap {
public :
	MaxHeap(int MaxHeapSize = 10);
	~MaxHeap() { delete[] heap; }
	int Size() const { return CurrentSize; }
	T Max() {
		if (CurrentSize == 0) throw OutOfBounds();
		return heap[1];
	}
	MaxHeap<T>& Insert(const T& x);
	MaxHeap<T>& DeleteMax(T& x);
	void Initialize(T a[], int size, int ArraySize);
	void Deactivate();
private :
	int CurrentSize, MaxSize;
	T *heap; // 元素数组
};

template<class T>
MaxHeap<T>::MaxHeap(int MaxHeapSize)
{// 构造函数
	MaxSize = MaxHeapSize;
	heap = new T[MaxSize + 1];
	CurrentSize = 0;
}


template<class T>
MaxHeap<T>& MaxHeap<T>::Insert(const T& x)
{// 把x 插入到最大堆中
	if (CurrentSize == MaxSize)
		throw NoMem(); // 没有足够空间
	/ / 为x寻找应插入位置
		// i 从新的叶节点开始，并沿着树上升
		int i = ++CurrentSize;
	while (i != 1 && x > heap[i / 2]) {
		// 不能够把x 放入h e a p [ i ]
		heap[i] = heap[i / 2]; // 将元素下移
		i /= 2; // 移向父节点
	}
	heap[i] = x;
	return *this;
}


template<class T>
MaxHeap<T>& MaxHeap<T>::DeleteMax(T& x)
{// 将最大元素放入x ，并从堆中删除最大元素
	// 检查堆是否为空
	if (CurrentSize == 0)
		throw OutOfBounds(); // 队列空
	x = heap[1]; // 最大元素
	// 重构堆
	T y = heap[CurrentSize--]; // 最后一个元素
	// 从根开始，为y 寻找合适的位置
	int i = 1, // 堆的当前节点
		ci = 2; // i的孩子
	while (ci <= CurrentSize) {
		// heap[ci] 应是i的较大的孩子
		if (ci < CurrentSize &&
			heap[ci] < heap[ci + 1]) ci++;
		// 能把y 放入h e a p [ i ]吗?
		if (y >= heap[ci]) break; // 能
		// 不能
		heap[i] = heap[ci]; // 将孩子上移
		i = ci; //下移一层
		ci *= 2;
	}
	heap[i] = y;
	return *this;
}

template<class T>
void MaxHeap<T>::Initialize(T a[], int size, int ArraySize)
{// 把最大堆初始化为数组a .
	delete[] heap;
	heap = a;
	CurrentSize = size;
	MaxSize = ArraySize;
	// 产生一个最大堆
	for (int i = CurrentSize / 2; i >= 1; i--) {
		T y = heap[i]; // 子树的根
		// 寻找放置y的位置
		int c = 2 * i; // c的父节点是y的目标位置
		while (c <= CurrentSize) {
			// heap[c] 应是较大的同胞节点
			if (c < CurrentSize &&
				heap[c] < heap[c + 1]) c++;
			// 能把y 放入h e a p [ c / 2 ]吗?
			if (y >= heap[c]) break; // 能
			// 不能
			heap[c / 2] = heap[c]; // 将孩子上移
			c *= 2; // 下移一层
		}
		heap[c / 2] = y;
	}
}

template<class T>
void MaxHeap<T>::Deactivate() { heap = 0; }