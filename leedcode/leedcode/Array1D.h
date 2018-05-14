#ifndef Array1D_HH
#define Array1D_HH

template<class T>
class Array1D {
public :
	Array1D(int size = 0);
	Array1D(const Array1D<T>& v); // 复制构造函数
	~Array1D() { delete[] element; }
	T& operator[](int i) const;
	int Size() { return size; }
	Array1D<T>& operator=(const Array1D<T>& v);
	Array1D<T> operator+() const; // 一元加法操作符
	Array1D<T> operator+(const Array1D<T>& v) const;
	Array1D<T> operator-() const; // 一元减法操作符
	Array1D<T> operator-(const Array1D<T>& v) const;
	Array1D<T> operator*(const Array1D<T>& v) const;
	Array1D<T>& operator+=(const T& x);
	void ReSize(const int size);
private :
	int size;
	T *element; //一维数组
};


template<class T>
void Array1D<T>::ReSize(const int sz)
{
	delete[] element;
	size = sz;
	element = new T[size];
}


template<class T>
Array1D<T>::Array1D(int sz)
{// 一维数组的构造函数
	if (sz < 0) throw;// BadInitializers();
	size = sz;
	element = new T[sz];
}

template<class T>
Array1D<T>::Array1D(const Array1D<T>& v)
{//一维数组的复制构造函数
	size = v.size;
	element = new T[size]; // 申请空间
	for (int i = 0; i < size; i++) // ¸´ÖÆÔªËØ
		element[i] = v.element[i];
}


template<class T>
T& Array1D<T>::operator[](int i) const
{// 返回指向第i个元素的引用
	if (i < 0 || i >= size) throw OutOfBounds();
	return element[i];
}

template<class T>
Array1D<T>& Array1D<T>::operator=(const Array1D<T>& v)
{// 重载赋值操作符=
	if (this != &v) {// 不是自我赋值
		size = v.size;
		delete[] element; // 释放原空间
		element = new T[size]; // 申请空军
		for (int i = 0; i < size; i++) //复制元素
			element[i] = v.element[i];
	}
	return *this;
}

template<class T>
Array1D<T> Array1D<T>::operator-(const Array1D<T>& v) const
{// 返回 w = (*this) - v
	if (size != v.size) throw;// SizeMismatch();
	// 创建结果数组 w
	Array1D<T> w(size);
	for (int i = 0; i < size; i++)
		w.element[i] = element[i] - v.element[i];
	return w;
}
template<class T>
Array1D<T> Array1D<T>::operator-() const
{// 返回 w = -(*this)
	// 创建结果数组 w
	Array1D<T> w(size);
	for (int i = 0; i < size; i++)
		w.element[i] = -element[i];
	return w;
}
template<class T>
Array1D<T>& Array1D<T>::operator+=(const T& x)
{
	// 把x 加到(*this)的每个元素上
		for (int i = 0; i < size; i++)
			element[i] += x;
	return *this;
}


#endif