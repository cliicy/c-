#include "Curr2.h"

namespace curr2{
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
		amount =(long) (a + 0.001) * 100;
		if (sgn == minus) amount = -amount;
		return true;
	}

	Currency Currency::operator+(const Currency& x) const
	{// 把x 累加至* t h i s .
		Currency y;
		y.amount = amount + x.amount;
		return y;
	}

	void Currency::Output(ostream& out) const
	{// 将currency 的值插入到输出流
		long a = amount;
		if (a < 0) { out << '-'; a = -a; }
		long d = a / 100; // 美元
		out << '$' << d << '.';
		int c = a - d * 100; // 美分
		if (c < 10) out << "0";
		out << c;
	}

	// 重载< <
	ostream& operator<<(ostream& out, const Currency& x)
	{
		x.Output(out); return out;
	}
}