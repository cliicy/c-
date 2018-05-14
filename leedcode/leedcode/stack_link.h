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
	Node<T>* top;//指向栈顶节点
};


template<class T>
LinkedStack<T>::~LinkedStack()
{// 析构函数
	Node<T> *next;
	while (top) {
		next = top->link;
		delete top;
		top = next;
	}
}

template<class T>
bool LinkedStack<T>::IsFull() const
{// 堆栈是否满?
	try {
		Node<T> *p = new Node<T>;
		delete p;
		return false;
	}
	catch (NoMem) { return true; }
}

template<class T>
T LinkedStack<T>::Top() const
{// 返回栈顶元素
	if (IsEmpty()) throw OutOfBounds();
	return top->data;
}
template<class T>
LinkedStack<T>& LinkedStack<T>::Add(const T& x)
{// 添加元素x
	Node<T> *p = new Node<T>;
	p->data = x;
	p->link = top;
	top = p;
	return *this;
}
template<class T>
LinkedStack<T>& LinkedStack<T>::Delete(T& x)
{// 删除栈顶元素，并将其送入x
	if (IsEmpty()) throw OutOfBounds();
	x = top->data;
	Node<T> *p = top;
	top = top->link;
	delete p;
	return *this;
}
#endif