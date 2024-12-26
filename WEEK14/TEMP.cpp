#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Book {
    wstring title; // 책 이름
    wstring author; // 저자
    int year;  // 출판년도
public:
    Book(wstring title, wstring author, int year);
    wstring getAuthor() const;
    int getYear() const;
    void show() const;  // 도서 정보 출력
};

Book::Book(wstring title, wstring author, int year) : title(title), author(author), year(year) {}

wstring Book::getAuthor() const {
    return author;
}

int Book::getYear() const {
    return year;
}

void Book::show() const {
    wcout << year << L"년도 , " << title << " , " << author << endl;
}

class BookManager {
    vector<Book> v; //Book 객체를 저장하기위한 vetor 객체 생성
    void searchByAuthor();  //저자로 검색, 동일한 저자 모두 출력
	void searchByYear(); //연도로 검색, 동일한 연도 모두 출력,
	void bookIn();  //벡터에 Book 정보 저장
    void finish();
public:
    void run(); 
};

void BookManager::searchByAuthor() {
    wstring author;
    wcout << L"검색하고자 하는 저자 이름을 입력하세요 >> ";
    wcin >> author;
    bool found = false;
    for (auto& book : v) {
        if (book.getAuthor() == author) {
            book.show();
            found = true;
        }
    }
    if (!found) wcout << L"입력하신 저자를 찾을 수 없습니다." << endl;
}

void BookManager::searchByYear() {
    int year;
    wcout << L"검색하고자 하는 년도를 입력하세요 >> ";
    wcin >> year;
    bool found = false;
    for (auto& book : v) {
        if (book.getYear() == year) {
            book.show();
            found = true;
        }
    }
    if (!found) wcout << L"입력하신 년도에는 출판된 책이 없습니다." << endl;
}

void BookManager::bookIn(){
    wstring title, author;
    int year;
    int count = 0;
    wcout << L"입고할 책을 입력하세요. 년도에 -1을 입력하면 입고를 종료합니다." << endl;
    while (true) {
        wcout << L"년도 >> ";
        wcin >> year;
        if (year == -1){
            wcout << L"총 입고된 책은 " << count << L"권 입니다." << endl;
            break;
        }
        wcin.ignore();
        wcout << L"책이름 >> ";
        getline(wcin, title);
        wcout << L"저자 >> ";
        getline(wcin, author);
        v.emplace_back(Book(title, author, year));
        count++;
    }
}

void BookManager::run() {
    bookIn(); // 입고
	searchByAuthor(); // 저자로 검색
	searchByYear(); // 년도로 검색
}

int main() {
    BookManager man;
    man.run();
}