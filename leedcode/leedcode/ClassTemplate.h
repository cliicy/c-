#pragma once
#ifndef ClassTemplate_HH
#define ClassTemplate_HH

template<typename T1>

class myClass{

private:
	T1 I;

public:
	myClass(T1 a);//Constructor
	void show();
};


template <typename T1>

myClass<T1>::myClass(T1 a) :I(a){}



//’‚ «void show();

template <typename T1>

void myClass<T1>::show()
{
	cout << "I=" << I << endl;
}

#endif