#include "Curr2.h"

namespace curr2{
	Currency::Currency(sign s, unsigned long d, unsigned int c)
	{// ����һ��C u r r e n c y����
		if (c > 99)
		{
			// ������Ŀ����
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
	{// ��x �ۼ���* t h i s .
		Currency y;
		y.amount = amount + x.amount;
		return y;
	}

	void Currency::Output(ostream& out) const
	{// ��currency ��ֵ���뵽�����
		long a = amount;
		if (a < 0) { out << '-'; a = -a; }
		long d = a / 100; // ��Ԫ
		out << '$' << d << '.';
		int c = a - d * 100; // ����
		if (c < 10) out << "0";
		out << c;
	}

	// ����< <
	ostream& operator<<(ostream& out, const Currency& x)
	{
		x.Output(out); return out;
	}
}