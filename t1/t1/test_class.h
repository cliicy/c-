#include <iostream>

using namespace std;


class CExample {
private:
	int a;
public:
	CExample(int b){
		a = b;
	}

	CExample(const CExample& C) {
		a = C.a;
	}
	void Show()
	{
		cout << a << endl;
	}
};


class CA {
public:
	CA(int b, char* cstr){
		a = b;
		str = new char[b];
		strcpy(str, cstr);
	}

	CA(const CA& C) {
		a = C.a;
		str = new char[a];
		if (str != 0)
			strcpy(str, C.str);

	}

	void Show(){
		cout << str << endl;
	}

	~CA() {
		delete str;
	}

private:
	int a;
	char* str;
};