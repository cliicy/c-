#include<iostream>  
#include<algorithm>  
using namespace std;


namespace STLSamples{

	template <class T>
	bool next_permutation(T first, T last)
	{
		if (first == last) return false; /* ������ */
		T i = first;
		++i;
		if (i == last) return false;  /* ֻ��һ��Ԫ�� */
		i = last;                    /* iָ��β�� */
		--i;
		for (;;)
		{
			T ii = i;
			--i;
			/* ��������һ��(����)����Ԫ�� */
			if (*i < *ii)           /* ���ǰһ��Ԫ��С�ں�һ��Ԫ�� */
			{
				T j = last; /* ��jָ��β�� */
				while (!(*i < *--j));     /* ��β����ǰ�ң�ֱ��������*i���Ԫ�� */
				iter_swap(i, j);          /* ����i,j */
				reverse(ii, last);        /* ��ii֮���Ԫ��ȫ���������� */
				return true;
			}
			if (i == first)       /* ��������ǰ���� */
			{
				reverse(first, last);    /* ȫ���������� */
				return false;
			}
		}
	}

	void do_nextPermutaion(){
		int ans[4] = { 1, 2, 3, 4 };
		int nsize = sizeof(int);
		sort(ans, ans + 4);    /* ���sort���Բ��ã���Ϊ{1��2��3��4}�Ѿ��ź���*/
		do                             /*ע���ⲽ�������whileѭ��������Ҫ��ǰ���*/
		{
			for (int i = 0; i<4; ++i)
				cout << ans[i] << " ";
			cout << endl;
		} while (next_permutation(ans, ans + 4));
	}

	void do_2nextPermutation(){
		/*
		string str;
		cin >> str;
		//string::iterator itb=str.begin();
		//string::iterator ite = str.end();
		sort(str.begin(), str.end());
		cout << str << endl;
		while (next_permutation(str.begin(), str.end()))
		{
			cout << str << endl;
		}*/
	}

	

#define MAX 100
	void do_cNextPermu(){

		int length;
		char str[MAX];
		gets(str);
		length = strlen(str);
		sort(str, str + length);
		puts(str);
		while (next_permutation(str, str + length))
		{
			puts(str);
		}
	}

class NoVirtualOne{

};

class Base
{
public:
	virtual void foo()
	{
		cout << "Base foo" << endl;
	}
};
class Derived : public Base
{
public:
	virtual void foo() override
	{
		cout << "Derived foo" << endl;
	}
	void bar()
	{
		cout << "Derived bar" << endl;
	}
};
void do_mainBase()
{
	Base *b = new Base();
	Base &&bref = Base();
	try{
		dynamic_cast<Derived&>(bref).bar(); // crash
	}
	catch (exception &e)
	{
		cout << e.what() << endl;
	}
	Derived* dptr = dynamic_cast<Derived*>(b);
	if (!dptr)
	{
		dptr->bar(); // doesn't crash
	}
	else
	{
		cout << "crash" << endl;
	}
}


class BaseX

{

public:

	virtual int test(){ return 0; } //�����д����麯���������������д����麯��ָ��ָ���麯����

};

class DerivedX :public BaseX

{

public:

	virtual int test(){ return 1; }

};

void do_checkCastX()
{
	NoVirtualOne one;
	int nL = sizeof(one);

	Base cbase;

	Derived cderived;

	Base *p1 = new Base;
	nL = sizeof(p1);

	Base *p2 = new Derived;
	nL = sizeof(p2);
	Derived* pD1 = dynamic_cast<Derived*>(p1);//p1û������ָ��������,pD1��Ϊ0

	Derived* pD2 = dynamic_cast<Derived*>(p2); //��ȷ

	//Derived& pd1=dynamic_cast<Derived&>(*p1);//p1û������ָ�������࣬pd1�׳��쳣

	Derived& pd2 = dynamic_cast<Derived&>(*p2);//��ȷ


}

class A{
private:
	int value;
public:
	A(int n) { value = n; }
	A(const A& other) { value = other.value; }
	void Print() { std::cout << value << std::endl; }
};

void do_checkClassA(){
	A a = 10;
	A b = a;
	b.Print();
}

void print(int x)
{
	cout << "int C++" << endl;
}

void print(char c)
{
	cout << "char C++" << endl;
}

void  do_overload()
{
	int n = 1;
	char ch = 'a';
	print(n);
	print(ch);

}

void do_matrix(){
	int matrix[][4] = { { 1, 2, 8, 9 }, { 2, 4, 9, 12 }, { 4, 7, 10, 13 }, { 6, 8, 11, 15 } };
	int columns = 4;
	int rows = 4;
	int row = 0;
	int number = 7;
	bool found = false;
	int column = columns - 1;
	int nTmp = -1;
	while (row < rows && column >= 0)
	{
		nTmp = row * columns + column;
		if (matrix[row][nTmp] == number)
		{
			found = true;
			break;
		}
		else if (matrix[row][nTmp] > number)
			--column;
		else
			++row;
	}
}

}