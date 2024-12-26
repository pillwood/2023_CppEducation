#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

class Book{
    char *title;    //제목 문자열
    int price;      //가격
public:
    Book() = default;
    Book(const char *title, int price);
    Book(const Book &b);        //(3)정답. 깊은 복사, 복사 생성자 작성
    ~Book();
    Book(Book &&b)noexcept;
    void set(const char *title, int price);
    void show(){cout << title << ' ' << price << "원" << endl;}
};

Book::Book(const char *title, int price)
{   //(1)정답
    int len=strlen(title);
    this -> title = new char[len +1];
    strcpy(this -> title, title);
    this -> price = price;
}

Book::~Book()
{   //(1)정답
    if(title){
        cout << title << "소멸" << endl;
        delete[] title;
    }
}

Book::Book(Book &&b)noexcept
{   //(4)정답 : 이동 생성자
    price = b.price;
    title = b.title;
    b.title = nullptr;
    b.price = 0;
}

void Book::set(const char *title, int price)
{                                   //(1)정답
    if(this -> title){              //현재 객체에 title메모리가 할당되어 책 이름 저장
        delete[] this -> title;     //현재 title에 할당된 메모리 반환
    }
    int len=strlen(title);
    this -> title = new char[len + 1];      //새로 메모리 할당
    strcpy(this -> title, title);
    this -> price = price;
}

/*
Book::Book(Book& b){        //(2) 정답. 디폴트 복사 생성자
    title = b.title;
    price = b.price;

}
*/

Book::Book(const Book &b)
{       //(3) 정답. 깊은 복사 복사 생성자 작성
    int len = strlen(b.title);
    title = new char[len + 1];
    strcpy(title, b.title);
    price = b.price;
}

int main(){
    Book cpp("명품 C++", 10000);
    Book java = cpp;
    java.set("명품자바", 12000);
    cpp.show();
    java.show();

    vector<Book> b;
    b.push_back(Book("명품파이썬", 15000));
    b.at(0).show();
    Book book(Book{"명품스크립트",34000});
    book.show();
}