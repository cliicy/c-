#ifndef Chain_HH
#define Chain_HH
#pragma once

#include <iostream>
using namespace std;

//namespace ChainLink{

/*
template <class T>
class ChainNode {
public:
	friend Chain<T>;
private :
	T data;
	ChainNode<T> *link;
};
*/
template <class T>
struct ChainNode{
	T data;
	ChainNode<T> *link;
};

template<class T>
class Chain {
public :
	Chain() { first = 0; }
	~Chain();
	bool IsEmpty() const { return first == 0; }
	int Length() const;
	bool Find(int k, T& x) const;
	int Search(const T& x) const;
	Chain<T>& Delete(int k, T& x);
	Chain<T>& Insert(int k, const T& x);
	void Output(ostream& out) const;
	void Erase();
	Chain <T> & Append(const T& x);
private :
	ChainNode<T> *first; // 指向第一个节点的指针
};


template<class T>
Chain<T>::~Chain()
{// 链表的析构函数，用于删除链表中的所有节点
	ChainNode<T> *next; // 下一个节点
	while (first) {
		next = first->link;
		delete first;
		first = next;
	}
}


template<class T>
int Chain<T>::Length() const
{// 返回链表中的元素总数
	ChainNode<T> *current = first;
	int len = 0;
	while (current) {
		len++;
		current = current->link;
	}
	return len;
}

template<class T>
bool Chain<T>::Find(int k, T& x) const
{// 寻找链表中的第k个元素，并将其传送至x
	//如果不存在第k个元素，则返回f a l s e，否则返回t r u e
	if (k < 1) return false;
	ChainNode<T> *current = first;
	int index = 1; // current的索引
	while (index < k && current) {
		current = current->link;
		index++;
	}
	if (current) { x = current->data; return true; }
	return false; // 不存在第k个元素
}

template<class T>
int Chain<T>::Search(const T& x) const
{// 寻找x，如果发现x，则返回x的地址
	//如果x不在链表中，则返回0
	ChainNode<T> *current = first;
	int index = 1; // current的索引
	while (current && current->data != x) {
		current = current->link;
		index++;
	}
	if (current) return index;
	return 0;
}


template<class T>
void Chain<T>::Output(ostream& out) const
{// 将链表元素送至输出流
	ChainNode<T> *current;
	for (current = first; current; current = current->link)
		out << current->data << " ";
}

// 重载< <
template <class T>
ostream& operator<<(ostream& out, const Chain<T>& x)
{
	x.Output(out); return out;
}


template<class T>
Chain<T>& Chain<T>::Delete(int k, T& x)
{// 把第k个元素取至x，然后从链表中删除第k个元素
	// 如果不存在第k个元素，则引发异常OutOfBounds
	if (k < 1 || !first)//throw;OutOfBounds(); // 不存在第k个元素
	{
		cerr << "An exception has occurred" << endl;
	}
		
	// p最终将指向第k个节点
	ChainNode<T> *p = first;
	// 将p移动至第k个元素，并从链表中删除该元素
	if (k == 1) // p已经指向第k个元素
		first = first->link; // 删除之
	else ( // 用q指向第k - 1个元素
		ChainNode<T> *q = first;
	for (int index = 1; index < k - 1 && q; index++)
		q = q->link;
	if (!q || !q->link)		//throw;OutOfBounds(); //不存在第k个元素
	{
		cerr << "An exception has occurred" << endl;
	}
	p = q->link; // 存在第k个元素
	q->link = p->link;) // 从链表中删除该元素
		// 保存第k个元素并释放节点p
		x = p->data;
	delete p;
	return *this;
}


template<class T>
Chain<T>& Chain<T>::Insert(int k, const T& x)
{// 在第k个元素之后插入x
	// 如果不存在第k个元素，则引发异常O u t O f B o u n d s
		// 如果没有足够的空间，则传递N o M e m异常
	if (k < 0) // throw OutOfBounds();
	{
		cerr << "An exception has occurred" << endl;
	}
	// p最终将指向第k个节点
	ChainNode<T> *p = first;
	// 将p移动至第k个元素
	for (int index = 1; index < k && p; index++)
		p = p->link;
	if (k > 0 && !p) //throw OutOfBounds(); //不存在第k个元素
	{
		cerr << "An exception has occurred" << endl;
	}
	// 插入
	ChainNode<T> *y = new ChainNode<T>;
	y->data = x;
	if (k) {// 在p之后插入
		y->link = p->link;
		p->link = y;
	}
	else {// 作为第一个元素插入
		y->link = first;
		first = y;
	}
	return *this;
}

template<class T>
void Chain<T>::Erase()
{
	// 删除链表中的所有节点
		ChainNode<T> *next;
	while (first) {
		next = first->link;
		delete first;
		first = next;
	}
}

template < class T >
Chain <T> & Chain <T> ::Append(const T& x)
{
	// 在链表尾部添加x
	ChainNode< T > *y;
	y = new ChainNode< T >;
	y->data = x; y->link = 0;
	if (first) {//链表非空
		last->link = y;
		last = y;
	}
	else // 链表为空
		first = last = y;
	return *this;
}


template<class T>
class ChainIterator {
	public :
	T* Initialize(const Chain<T>& c)
	{
		location = c.first;
		if (location) return &location->data;
		return 0;
	}
	T* Next()
	{
		if (!location) return 0;
		location = location->link;
		if (location) return &location->data;
		return 0;
	}
	private :
	ChainNode<T> *location;
};

#endif
