#ifndef Stack_HH
#define Stack_HH
template<class T>
class Stack{
	// LIFO对象
public :
	Stack(int MaxStackSize = 10);
	~Stack() { delete[] stack; }
	bool IsEmpty() const { return top == -1; }
	bool IsFull() const { return top == MaxTop; }
	T Top() const;
	Stack<T>& Add(const T& x);
	Stack<T>& Delete(T& x);
private :
	int top; // 栈顶
	int MaxTop; // 最大的栈顶值
	T *stack; // 堆栈元素数组
};


template<class T>
Stack<T>::Stack(int MaxStackSize)
{// Stack 类构造函数
	MaxTop = MaxStackSize - 1;
	stack = new T[MaxStackSize];
	top = -1;
}
template<class T>
T Stack<T>::Top() const
{// 返回栈顶元素
	if (IsEmpty()) throw OutOfBounds();
	else return stack[top];
}
template<class T>
Stack<T>& Stack<T>::Add(const T& x)
{
	//添加元素x
	if (IsFull()) throw exception();// NoMem();
	stack[++top] = x;
	return *this;
}
template<class T>
Stack<T>& Stack<T>::Delete(T& x)
{//删除栈顶元素，并将其送入x
	if (IsEmpty()) throw exception();
	x = stack[top--];
	return *this;
}

#endif