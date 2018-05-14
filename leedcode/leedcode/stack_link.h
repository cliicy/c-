#ifndef StackLink_HH
#define StackLink_HH
//Page 183

template <class T>
struct Node{
	T data;
	Node<T>* link;
};


template<class T>
class LinkedStack{
public:
	LinkedStack() { top = 0; }
	~LinkedStack();
	bool IsEmpty() const { return top == 0; }
	bool IsFull() const;
	T Top() const;
	LinkedStack<T>& Add(const T& x);
	LinkedStack<T>& Delete(T& x);
private:
	Node<T>* top;//ָ��ջ���ڵ�
};


template<class T>
LinkedStack<T>::~LinkedStack()
{// ��������
	Node<T> *next;
	while (top) {
		next = top->link;
		delete top;
		top = next;
	}
}

template<class T>
bool LinkedStack<T>::IsFull() const
{// ��ջ�Ƿ���?
	try {
		Node<T> *p = new Node<T>;
		delete p;
		return false;
	}
	catch (NoMem) { return true; }
}

template<class T>
T LinkedStack<T>::Top() const
{// ����ջ��Ԫ��
	if (IsEmpty()) throw OutOfBounds();
	return top->data;
}
template<class T>
LinkedStack<T>& LinkedStack<T>::Add(const T& x)
{// ���Ԫ��x
	Node<T> *p = new Node<T>;
	p->data = x;
	p->link = top;
	top = p;
	return *this;
}
template<class T>
LinkedStack<T>& LinkedStack<T>::Delete(T& x)
{// ɾ��ջ��Ԫ�أ�����������x
	if (IsEmpty()) throw OutOfBounds();
	x = top->data;
	Node<T> *p = top;
	top = top->link;
	delete p;
	return *this;
}
#endif