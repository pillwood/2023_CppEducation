#include <iostream>
using namespace std;

class Fraction {
	int numer;  // 분자
	int denom;  // 분모

public:
	Fraction(int num, int den);
	Fraction();
	~Fraction();

	int getNumer() const;
	int getDenom() const;

	void setNumer(int num);
	void setDenom(int den);
	void print() const;

private:
	void normalize();
	int gcd(int n, int m);
};

Fraction::Fraction(int num, int den) : numer(num), denom(den) {
	normalize();
}

Fraction::Fraction() : numer(0), denom(1) {}

Fraction::~Fraction() {}

int Fraction::getNumer() const {
	return numer;
}

int Fraction::getDenom() const {
	return denom;
}

void Fraction::setNumer(int num) {
	numer = num;
	normalize();
}

void Fraction::setDenom(int den) {
	if (den != 0) {
		denom = den;
		normalize();
	}
}

void Fraction::print() const {
	cout << numer << '/' << denom;
}

void Fraction::normalize() {
	int divisor = gcd(numer, denom);
	numer /= divisor;
	denom /= divisor;
}

int Fraction::gcd(int n, int m) {
	if (m == 0) {
		return n;
	}
	return gcd(m, n % m);
}

Fraction& multiplyFract(const Fraction& f1, const Fraction& f2, Fraction& result) {
	int new_numer = f1.getNumer() * f2.getNumer();
	int new_denom = f1.getDenom() * f2.getDenom();
	result.setNumer(new_numer);
	result.setDenom(new_denom);
	return result;
}

Fraction& addFract(const Fraction& f1, const Fraction& f2, Fraction& result) {
	int new_numer = f1.getNumer() * f2.getDenom() + f2.getNumer() * f1.getDenom();
	int new_denom = f1.getDenom() * f2.getDenom();
	result.setNumer(new_numer);
	result.setDenom(new_denom);
	return result;
}

int main() {
	Fraction fract1(12, 15);
	Fraction fract2(6, 9);
	Fraction product;
	Fraction sum;

	cout << "\n== 다음과 같은 분수에 대하여 산술연산을 합니다. ==" << endl;
	cout << "fract1: ";
	fract1.print();
	cout << endl << "fract2: ";
	fract2.print();

	cout << endl << "The result of multiplying is: ";
	multiplyFract(fract1, fract2, product).print();

	cout << endl << "The result of adding is: ";
	addFract(fract1, fract2, sum).print();

	cout << endl;
}