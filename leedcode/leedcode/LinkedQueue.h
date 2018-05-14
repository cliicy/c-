#ifndef LinkedQueue_HH
#define LinkedQueue_HH

template <class T>
struct quNode{
	T data;
	quNode<T>* link;
};



template<class T>
class LinkedQueue {
	// FIFO对象
public:
	LinkedQueue() { front = rear = 0; } // 构造函数
	~LinkedQueue(); // 析构函数
	bool IsEmpty() const
	{
		return ((front) ? false : true);
	}
	bool IsFull() const;
	T First() const; // 返回第一个元素
	T Last() const; // 返回最后一个元素
	LinkedQueue<T>& Add(const T& x);
	LinkedQueue<T>& Delete(T& x);
private:
	quNode<T> *front; // 指向第一个节点
	quNode<T> *rear; //指向最后一个节点
};


template<class T>
LinkedQueue<T>:: ~LinkedQueue()
{// 队列析构函数，删除所有节点
	quNode<T> *next;
	while (front) {
		next = front->link;
		delete front;
		front = next;
	}
}
template<class T>
bool LinkedQueue<T>::IsFull() const
{// 判断队列是否已满
	quNode<T> *p;
	try {
		p = new quNode<T>;
		delete p;
		return false;
	}
	catch (exception) { return true; }
}

template<class T>
T LinkedQueue<T>::First() const
{// 返回队列的第一个元素
	// 如果队列为空，则引发异常O u t O f B o u n d s
	if (IsEmpty()) throw ;// OutOfBounds();
	return front->data;
}
template<class T>
T LinkedQueue<T>::Last() const
{// 返回队列的最后一个元素
	// 如果队列为空，则引发异常O u t O f B o u n d s
	if (IsEmpty()) throw ;// OutOfBounds();
	return rear->data;
}

template<class T>
LinkedQueue<T>& LinkedQueue<T>::Add(const T& x)
{// 把x 添加到队列的尾部
	// 补捕获可能由new引发的NoMem异常
	// 为新元素创建链表节点
	quNode<T> *p = new quNode<T>;
	p->data = x;
	p->link = 0;
	//在队列尾部添加新节点
	if (front) rear->link = p; //队列不为空
	else front = p; // 队列为空
	rear = p;
	return *this;
}

template<class T>
LinkedQueue<T>& LinkedQueue<T>::Delete(T& x)
{
// 删除第一个元素，并将其放入x x
	// 如果队列为空，则引发异常O u t O f B o u n d s
	if (IsEmpty()) throw ;// OutOfBounds();
	// 保存第一个节点中的元素
	x = front->data;
	//删除第一个节点
	quNode<T> *p = front;
	front = front->link;
	delete p;
	return *this;
}

#endif