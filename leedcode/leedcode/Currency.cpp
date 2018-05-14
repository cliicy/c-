#include "Currency.h"
#include <iostream>
using namespace std;

namespace currency{
	Currency::Currency(sign s, unsigned long d, unsigned int c)
	{// ����һ��C u r r e n c y����
		if (c > 99)
		{
			// ������Ŀ����
			cerr << "Cents should be < 100" << endl;
			exit(1);
		}
		sgn = s; dollars = d; cents = c;
	}

	bool Currency::Set(sign s, unsigned long d, unsigned int c){
		if (c > 99) return false;
		sgn = s; dollars = d; cents = c;
		return true;
	}

	bool Currency::Set(float a){
		if (a < 0){ 
			sgn = opts_sign::minus; a = -a;
		}
		else {
			sgn = plus;
			dollars =(unsigned long)a;//��ȡ��������
			//��ȡ����С��λ
			cents = static_cast<unsigned int>(a + 0.005 - dollars) * 100;
		}
		return true;
	}

	Currency Currency::Add(const Currency& x) const
	{//��x�ۼӵ�*this
		long a1, a2, a3;
		Currency ans;
		//�ѵ�ǰ����ת���ɴ����ŵ�����
		a1 = dollars * 100 + cents;
		if (sgn == minus) a1 = -a1;

		// ��xת���ɴ����ŵ�����
		a2 = x.dollars * 100 + x.cents;
		if (x.sgn == minus) a2 = -a2;
		a3 = a1 + a2;
		// ת����currency ��ʽ
		if (a3 < 0) { ans.sgn = minus; a3 = -a3; }
		else ans.sgn = plus;
		ans.dollars = a3 / 100;
		ans.cents = a3 - ans.dollars * 100;
		return ans;
	}

	Currency& Currency::Increment(const Currency& x)
	{// ������x .
		*this = Add(x);
		return *this;
	}
	void Currency::Output() const
	{// ���currency ��ֵ
		if (sgn == minus) cout << '-';
		cout << '$' << dollars << '.';
		if (cents < 10) cout << "0";
		cout << cents;
	}
}