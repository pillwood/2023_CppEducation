#include <iostream>
#include <string>

using namespace std;

class Book {
    string title;
    int price, pages;
public:
    Book(string title = "", int price = 0, int pages = 0);
    void show();
    string getTitle();  //title 반환
    Book& operator+=(int num);
    Book& operator-=(int num);

    bool operator==(const int pr)const;
    bool operator==(const string ti)const;
    bool operator==(const Book& opb)const;
};
Book::Book(string title, int price, int pages){
    this -> title = title;
    this -> price = price;
    this -> pages = pages;
}

void Book::show(){
    cout << "title : " << title << ", price : " << price << ", pages : " << pages << endl;
}

string Book::getTitle(){
    return title;
}

Book& Book::operator+=(int num){
    price = price + num;
    return *this;
}
Book& Book::operator-=(int num){
    price = price - num;
    return *this;
}

bool Book::operator==(const int pr)const{
    return price==pr;
}
bool Book::operator==(const string ti)const{
    return title==ti;
}
bool Book::operator==(const Book& opb)const{
    return price == opb.price && title == opb.title && pages == opb.pages;
}

int main() {
    Book a("청춘", 20000, 300), b("미래", 30000, 500);
    a += 500;  // 책 a의 가격 500원 증가
    b -= 500;  // 책 b의 가격 500원 감소
    a.show(); 
    b.show();

    Book b1("명품 C++", 30000, 500), b2("고품 C++", 30000, 500);
    if (b1 == 30000) cout << "정가 30000원" << endl;          // price 비교
    if (b1 == "명품 C++") cout << "명품 C++ 입니다." << endl; // 책 title 비교
    if (b1 == b2) cout << "두 책이 같은 책입니다." << endl;     // title, price, pages 모두 비교 
}
