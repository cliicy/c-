
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
	T *heap; // Ԫ������
};

template<class T>
MaxHeap<T>::MaxHeap(int MaxHeapSize)
{// ���캯��
	MaxSize = MaxHeapSize;
	heap = new T[MaxSize + 1];
	CurrentSize = 0;
}


template<class T>
MaxHeap<T>& MaxHeap<T>::Insert(const T& x)
{// ��x ���뵽������
	if (CurrentSize == MaxSize)
		throw NoMem(); // û���㹻�ռ�
	/ / ΪxѰ��Ӧ����λ��
		// i ���µ�Ҷ�ڵ㿪ʼ��������������
		int i = ++CurrentSize;
	while (i != 1 && x > heap[i / 2]) {
		// ���ܹ���x ����h e a p [ i ]
		heap[i] = heap[i / 2]; // ��Ԫ������
		i /= 2; // ���򸸽ڵ�
	}
	heap[i] = x;
	return *this;
}


template<class T>
MaxHeap<T>& MaxHeap<T>::DeleteMax(T& x)
{// �����Ԫ�ط���x �����Ӷ���ɾ�����Ԫ��
	// �����Ƿ�Ϊ��
	if (CurrentSize == 0)
		throw OutOfBounds(); // ���п�
	x = heap[1]; // ���Ԫ��
	// �ع���
	T y = heap[CurrentSize--]; // ���һ��Ԫ��
	// �Ӹ���ʼ��Ϊy Ѱ�Һ��ʵ�λ��
	int i = 1, // �ѵĵ�ǰ�ڵ�
		ci = 2; // i�ĺ���
	while (ci <= CurrentSize) {
		// heap[ci] Ӧ��i�Ľϴ�ĺ���
		if (ci < CurrentSize &&
			heap[ci] < heap[ci + 1]) ci++;
		// �ܰ�y ����h e a p [ i ]��?
		if (y >= heap[ci]) break; // ��
		// ����
		heap[i] = heap[ci]; // ����������
		i = ci; //����һ��
		ci *= 2;
	}
	heap[i] = y;
	return *this;
}

template<class T>
void MaxHeap<T>::Initialize(T a[], int size, int ArraySize)
{// �����ѳ�ʼ��Ϊ����a .
	delete[] heap;
	heap = a;
	CurrentSize = size;
	MaxSize = ArraySize;
	// ����һ������
	for (int i = CurrentSize / 2; i >= 1; i--) {
		T y = heap[i]; // �����ĸ�
		// Ѱ�ҷ���y��λ��
		int c = 2 * i; // c�ĸ��ڵ���y��Ŀ��λ��
		while (c <= CurrentSize) {
			// heap[c] Ӧ�ǽϴ��ͬ���ڵ�
			if (c < CurrentSize &&
				heap[c] < heap[c + 1]) c++;
			// �ܰ�y ����h e a p [ c / 2 ]��?
			if (y >= heap[c]) break; // ��
			// ����
			heap[c / 2] = heap[c]; // ����������
			c *= 2; // ����һ��
		}
		heap[c / 2] = y;
	}
}

template<class T>
void MaxHeap<T>::Deactivate() { heap = 0; }