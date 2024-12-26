#include <iostream>
#include <memory>
#include <string>

using namespace std;

class Employee{
    int year;    // 입사 년도
    string name; // 이름
    string dept; // 소속

public:
    void setEmployee(string name, string dept, int year){// 입사 년도, 이름, 소속을 설정...생성자에서 넣을 필요 x
        this->name = name;
        this->dept = dept;
        this->year = year;
    }
    int getYear() const{ // 입사 년도 반환
        return year;
    }
    string getName() const{ // 이름 반환
        return name;
    }
    string getDept() const{ // 소속 반환
        return dept;
    }
    void disPlay(){  // 개인정보 출력
        cout << "name: " << name << ", dept: " << dept << ", year: " << year << endl;
    }
    ~Employee(){ // 소멸자
        cout << name << "객체 소멸" << endl;
    }
};

class Manager{
    unique_ptr<Employee[]> p; // Employee 배열을 가리키는 스마트포인터
    int size;                 // 배열의 크기

public:
    Manager(int size){ // size 크기의 Employee 배열 생성
        this->size = size;

        string name, dept;
        int year;
        p = unique_ptr<Employee[]>(new Employee[size]);

        for (int i = 0; i < size; i++){
            cout << "사원 " << i + 1 << "의 이름과 소속 입사연도를 입력하세요 >> ";
            cin >> name >> dept >> year;
            p[i].setEmployee(name, dept, year);
        }
    }

    ~Manager(){
        cout << "객체 소멸" << endl;
    }
    void searchByName(const string strn){ // 사용자로부터 이름을 입력 받아 소속과 입사 연도 출력
        for (int i=0; i<size; i++){
            if(p[i].getName() == strn){
                cout << "name: " << p[i].getName() << ", dept: " << p[i].getDept() << ", year: " << p[i].getYear() << endl;
            }
        }
    }

    void searchByYear(const int stry){ // 사용자로부터 입력 받은 년도 이후에 입사한 사원 정보 출력
        int cnt=0;
        for (int i = 0; i < size; i++) {
            if (p[i].getYear() >= stry) {
                cout << i + 1 << " ]  name: " << p[i].getName() << ", dept: " << p[i].getDept() << ", year: " << p[i].getYear() << endl;
                cnt ++;
            }
        }
        cout << stry << "년도 이후에 입사한 사원은 " << cnt << "명 입니다." << endl;
    }
};

int main(){
    Manager *pManager;
    cout << "사원수를 입력하세요 >> ";
    int size;
    cin >> size;
    if (size <= 0){
      cout << "양수를 입력하세요." << endl;
      return 0;
    }

    Manager man(size);
    string search_name;
    cout << "검색하고자 하는 사원의 이름 >> ";
    cin >> search_name;
    man.searchByName(search_name);
    int search_year;
    cout << "입사 연도를 입력하세요 >> ";
    cin >> search_year;
    man.searchByYear(search_year);
}