#include<iostream>  
#include<algorithm>  
using namespace std;


namespace STLSamples{

	template <class T>
	bool next_permutation(T first, T last)
	{
		if (first == last) return false; /* 空区间 */
		T i = first;
		++i;
		if (i == last) return false;  /* 只有一个元素 */
		i = last;                    /* i指向尾端 */
		--i;
		for (;;)
		{
			T ii = i;
			--i;
			/* 以上锁定一组(两个)相邻元素 */
			if (*i < *ii)           /* 如果前一个元素小于后一个元素 */
			{
				T j = last; /* 令j指向尾端 */
				while (!(*i < *--j));     /* 由尾端往前找，直到遇到比*i大的元素 */
				iter_swap(i, j);          /* 交换i,j */
				reverse(ii, last);        /* 将ii之后的元素全部逆序重排 */
				return true;
			}
			if (i == first)       /* 进行至最前面了 */
			{
				reverse(first, last);    /* 全部逆序重排 */
				return false;
			}
		}
	}

	void do_nextPermutaion(){
		int ans[4] = { 1, 2, 3, 4 };
		int nsize = sizeof(int);
		sort(ans, ans + 4);    /* 这个sort可以不用，因为{1，2，3，4}已经排好序*/
		do                             /*注意这步，如果是while循环，则需要提前输出*/
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

	virtual int test(){ return 0; } //基类中存在虚函数，故在派生类中存在虚函数指针指向虚函数表。

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
	Derived* pD1 = dynamic_cast<Derived*>(p1);//p1没有真正指向派生类,pD1置为0

	Derived* pD2 = dynamic_cast<Derived*>(p2); //正确

	//Derived& pd1=dynamic_cast<Derived&>(*p1);//p1没有真正指向派生类，pd1抛出异常

	Derived& pd2 = dynamic_cast<Derived&>(*p2);//正确


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