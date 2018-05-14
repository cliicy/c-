#pragma once
namespace MyCommon{

	template<class T>
	struct STNode{
		T data;
		STNode<T>* link;
	};


template <class T>
class linkedStack
{
public:
	linkedStack() { top = 0; }
	~linkedStack();
	bool isEmpty();
	linkedStack<T>& push(const T& data);
	T Top() const;
	linkedStack<T>& pop(T& x);
private:
	STNode<T>* top;
};

template<class T>
bool linkedStack<T>::isEmpty(){
	return top == 0;
}

template<class T>
linkedStack<T>::~linkedStack(){
	STNode<T> *next;
	while (top) {
		next = top->link;
		delete top;
		top = next;
	}
}

template<class T>
linkedStack<T>& linkedStack<T>::pop(T& x){
	STNode<T> *node = top->link;
	x = top->data;
//	cout << top->data << endl;
	delete top;
	top = node;
	return *this;
}


template<class T>
linkedStack<T>& linkedStack<T>::push(const T& data){
	STNode<T> *node = new STNode < T >;
	node->data = data;
	node->link = top;
	top = node;
	return *this;
}



template<class T>
T linkedStack<T>::Top() const{
	if (top)
		return top->data;
	return 0;
}

}
