#pragma once
namespace currency{

typedef enum opts_sign { plus, minus }sign;

class Currency
{
public:
	Currency(sign s = plus, unsigned long d = 0, unsigned int c = 0);
	~Currency(){};
	bool Set(sign s, unsigned long d, unsigned int c);
	bool Set(float a);
	sign Sign() const { return sgn; }
	unsigned long Dollars() const { return dollars; }
	unsigned int Cents() const { return cents; }
	Currency Add(const Currency& x) const;
	Currency& Increment(const Currency& x);
	void Output() const;
public:
private:
	sign sgn;
	unsigned long dollars;
	unsigned int cents;
	
};
}