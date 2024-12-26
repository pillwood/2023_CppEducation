#include <iostream>

using namespace std;

class Fraction{
	int numer;  //분자
	int denom;   //분모
public:
	Fraction(int num, int den); //매개변수가 있는 생성자
	Fraction(); //디폴트 생성자
	~Fraction();
	
	int getNumer() const;  //접근자
	int getDenom() const;
	
	void setNumer(int num); //설정자
	void setDenom(int den);
	void print() const;  //분수 출력
private:
	void normalize();  //gcd() 함수를 사용하여 기약분수로 처리
	int gcd(int n, int m); //분모와 분자의 최대 공약수
};

Fraction::Fraction(int num, int den)
{//매개변수 받아서 분자 분모에 집어넣기
    this -> numer = num;
    this -> denom = den;
    normalize();
}

Fraction::Fraction()
{//디폴트 생성자
    this -> numer = 1;
    this -> denom = 2; 
}

Fraction::~Fraction() {} //소멸자

int Fraction::getNumer() const 
{//분자 접근자
    return numer;
}

int Fraction::getDenom() const 
{//분모 접근자
    return denom;
}

void Fraction::setNumer(int num) 
{//분자 설정자 노말라이즈가 프라이빗이라 여기서 사용
    numer = num;
    normalize();
}

void Fraction::setDenom(int den) 
{//분모 설정자 노말라이즈가 프라이빗이라 여기서 사용
    denom = den;
    normalize();
}

void Fraction::print() const {
    cout << numer << '/' << denom;
}

void Fraction::normalize() 
{//gcd() 함수를 사용하여 기약분수로 처리
    int GCD = gcd(numer, denom);
    numer /= GCD;
    denom /= GCD;
}

int Fraction::gcd(int n, int m) 
{//재귀함수 이용한 GCD
    if (m == 0) {
        return n;
    }else{
        return Fraction::gcd(m, n % m);
    }
}

void write(Fraction&& fract) {
    fract.print();
    cout << endl;
}

Fraction& multiplyFract(const Fraction& fract1, const Fraction& fract2, Fraction& result) {
    result.setNumer(fract1.getNumer()*fract2.getNumer());
    result.setDenom(fract1.getDenom()*fract2.getDenom());
    return result;
}

Fraction& addFract(const Fraction& fract1, const Fraction& fract2, Fraction& result) {
    result.setNumer((fract1.getNumer()*fract2.getDenom())+(fract1.getDenom()*fract2.getNumer()));
    result.setDenom(fract1.getDenom()*fract2.getDenom());
    return result;
}

int main(){
    Fraction fract1(12, 15);
    Fraction fract2(6, 9);
    Fraction product{};

    cout << "\n== 다음과 같은 분수에 대하여 산술연산을 합니다.=="<<endl;
    cout << "fract1: ";
    write(move(fract1));
    cout << "fract2: ";
    write(move(fract2));
  
    cout << endl<<"The result of multiplying is: ";
    multiplyFract(fract1, fract2, product).print();

    cout << endl<< "The result of adding is: ";
    addFract(fract1, fract2, product).print();
}
