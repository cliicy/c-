#include "Curr1.h"
#include <iostream>
using namespace std;

namespace curr1{
	Currency::Currency(sign s, unsigned long d, unsigned int c)
	{// 创建一个C u r r e n c y对象
		if (c > 99)
		{
			// 美分数目过多
			cerr << "Cents should be < 100" << endl;
			exit(1);
		}
		amount = d * 100 + c;
		if (s == minus) amount = -amount;
	}

	bool Currency::Set(sign s, unsigned long d, unsigned int c){
		if (c > 99) return false;
		amount = d * 100 + c;
		if (s == minus) amount = -amount;
		return true;
	}

	bool Currency::Set(float a){
		sign sgn;
		if (a < 0)	{ sgn = minus; a = -a; }
		else {
			sgn = plus;
		}
		amount = (long)(a + 0.001) * 100;
		if (sgn == minus) amount = -amount;
		return true;
	}

	Currency Currency::Add(const Currency& x) const
	{//把x累加到*this
		Currency y;
		y.amount = amount + x.amount;
		return y;
	}

	void Currency::Output() const
	{// 输出currency 的值
		long a = amount;
		if (a < 0) {cout << '-'; a = -a;}
		long d=a/100;
		cout << '$' << d << '.';
		int c = a - d * 100;
		if (c < 10) cout << "0";
		cout << c;
	}
}