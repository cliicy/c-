#ifndef Currency_
#define Currency_
#pragma once
namespace curr1{

typedef enum opts_sign { plus, minus }sign;

class Currency
{
public:
	Currency(sign s = plus, unsigned long d = 0, unsigned int c = 0);
	~Currency(){};
	bool Set(sign s, unsigned long d, unsigned int c);
	bool Set(float a);
	sign Sign() const 
	{ if (amount < 0) return minus;
	else return plus; }
	unsigned long Dollars() const 
	{
		if (amount < 0) return (-amount)/100;
		else return amount/100;
	}
	unsigned int Cents() const 
	{
		if (amount < 0) return -amount-Dollars()*100;
		else return amount - Dollars() * 100;
	}
	Currency Add(const Currency& x) const;
	Currency& Increment(const Currency& x)
	{
		amount += x.amount;
		return *this;
	}
	void Output() const;
public:
private:
    long amount;
	
};
}
#endif