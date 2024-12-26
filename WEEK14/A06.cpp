#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Book {
    string title; // 책 이름
    string author; // 저자
    int year;  // 출판년도
public:
    Book(string title, string author, int year);
    string getAuthor();
    int getYear();
    void show();  // 도서 정보 출력
};

Book::Book(string title, string author, int year) : title(title), author(author), year(year) {}

string Book::getAuthor(){
    return author;
}

int Book::getYear(){
    return year;
}

void Book::show(){
    cout << year << "년도 , " << title << " , " << author << endl;
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
    string author;
    cout << "검색하고자 하는 저자 이름을 입력하세요 >> ";
    cin >> author;
    bool found = false;
    for (auto& book : v) {
        if (book.getAuthor() == author) {
            book.show();
            found = true;
        }
    }
    if (!found) cout << "입력하신 저자를 찾을 수 없습니다." << endl;
}

void BookManager::searchByYear() {
    int year;
    cout << "검색하고자 하는 년도를 입력하세요 >> ";
    cin >> year;
    bool found = false;
    for (auto& book : v) {
        if (book.getYear() == year) {
            book.show();
            found = true;
        }
    }
    if (!found) cout << "입력하신 년도에는 출판된 책이 없습니다." << endl;
}

void BookManager::bookIn(){
    string title, author;
    int year;
    int count;
    cout << "입고할 책을 입력하세요. 년도에 -1을 입력하면 입고를 종료합니다." << endl;
    while (true) {
        cout << "년도 >> ";
        cin >> year;
        if (year == -1){
            cout << "총 입고된 책은 " << count << "권 입니다." << endl;
            break;
        }
        //https://unluckyjung.github.io/cpp/2020/02/14/cin.ignore/ 에서 참고...
        //cin 으로 받고나서 개행문자를 그냥 받아버리는 문제가 있어서 그걸 날리기 위해 사용.
        cin.ignore();
        cout << "책이름 >> ";
        getline(cin, title);
        cout << "저자 >> ";
        getline(cin, author);
        v.emplace_back(Book(title, author, year));
        count ++;
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