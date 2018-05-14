#ifndef LinearList_HH
#define LinearList_HH
#pragma once
#include <iostream>
using namespace std;

namespace LineList{
	template<class T>
	class LinearList {
	public:
		LinearList(int MaxListSize = 10); //���캯��
		~LinearList() { delete[] element; } //��������
		bool IsEmpty() const { return length == 0; }
		int Length() const { return length; }
		bool Find(int k, T& x) const; //���ص�k��Ԫ����x��
		int Search(const T& x) const; // ����x����λ��

		LinearList<T>& Delete(int k, T& x); // ɾ����k��Ԫ�ز�����������x��
		LinearList<T>& Insert(int k, const T& x); // �ڵ�k��Ԫ��֮�����x

//		friend ostream& operator<<(ostream& out, const LinearList<T>& x);
		void Output(ostream& out) const;
		
	private:
		int length;
		int MaxSize;
		T *element; // һά��̬����
	};

	// �ڴ治��
class NoMem {
public:
	NoMem() {}
};

template<class T>
LinearList<T>::LinearList(int MaxListSize)
{
	MaxSize = MaxListSize;
	element = new T[MaxSize];
	length = 0;
}


template<class T>
bool LinearList<T>::Find(int k, T& x) const
{
	// �ѵ�k��Ԫ��ȡ��x��
	//��������ڵ�k��Ԫ���򷵻�f a l s e�����򷵻�t r u e
	if (k < 1 || k > length) return false; // �����ڵ�k��Ԫ��
	x = element[k - 1];
	return true;
}


template<class T>
int LinearList<T>::Search(const T& x) const
{
	// ����x������ҵ����򷵻�x���ڵ�λ��
	// ���x���ڱ��У��򷵻�0
	for (int i = 0; i < length; i++)
		if (element[i] == x) return ++i;
	return true;
}

template<class T>
LinearList<T>& LinearList<T>::Delete(int k, T& x)
{// �ѵ�k��Ԫ�ط���x�У�Ȼ��ɾ����k��Ԫ��
	// ��������ڵ�k��Ԫ�أ��������쳣O u t O f B o u n d s
	if (Find(k, x)) {// ��Ԫ��k+l, ...��ǰ�ƶ�һ��λ��
		for (int i = k; i < length; i++)
			element[i - 1] = element[i];
		length--;
		return *this;
	}
	else //throw OutOfBounds();
	{
		cerr << "An exception has occurred" << endl;
	}
	return *this;
}


template<class T>
LinearList<T>& LinearList<T>::Insert(int k, const T& x)
{// �ڵ�k��Ԫ��֮�����x
	// ��������ڵ�k��Ԫ�أ��������쳣O u t O f B o u n d s
	// ������Ѿ������������쳣N o M e m
	if (k < 0 || k > length) cerr << "An exception has occurred" << endl;
	if (length == MaxSize) throw NoMem();
	// ����ƶ�һ��λ��
		for (int i = length - 1; i >= k; i--)
			element[i + 1] = element[i];
	element[k] = x;
	length++;
	return *this;
}

template<class T>
void LinearList<T>::Output(ostream& out) const
{
	// �ѱ������������
	for (int i = 0; i < length; i++)
		out << element[i] << " ";
}


// ����< <
template <class T>
ostream& operator<<(ostream& out, const LinearList<T>& x)
{
	x.Output(out); return out;
}

}
#endif
