#include <iostream>
#include <memory>
#include <string>

using namespace std;

class Employee {
    int year;      // 입사 년도
    string name;   // 이름
    string dept;   // 소속

public:
    void setEmployee(string name, string dept, int year) {
        this->name = name;
        this->dept = dept;
        this->year = year;
    }

    int getYear() const {
        return year;
    }

    string getName() const {
        return name;
    }

    string getDept() const {
        return dept;
    }

    void disPlay() {
        cout << "name: " << name << ", dept: " << dept << ", year: " << year << endl;
    }

    ~Employee() {
        cout << name << " 객체 소멸" << endl;
    }
};

class Manager {
    unique_ptr<Employee[]> p;  // Employee 배열을 가리키는 스마트 포인터
    int size;                 // 배열의 크기

public:
    Manager(int size) : size(size) {
        p = make_unique<Employee[]>(size);
        for (int i = 0; i < size; i++) {
            string name, dept;
            int year;
            cout << "사원 " << i + 1 << "의 이름과 소속 입사연도를 입력하세요 >> ";
            cin >> name >> dept >> year;
            p[i].setEmployee(name, dept, year); // Employee 객체 초기화
        }
    }

    ~Manager() {
        cout << "Manager 객체 소멸" << endl;
    }

    void searchByName() {
        string targetName;
        cout << "검색하고자 하는 사원의 이름 >> ";
        cin >> targetName;

        for (int i = 0; i < size; i++) {
            if (p[i].getName() == targetName) {
                cout << "name: " << p[i].getName() << ", dept: " << p[i].getDept() << ", year: " << p[i].getYear() << endl;
                return; // 이름을 찾았으면 종료
            }
        }

        cout << "해당 이름을 가진 사원이 없습니다." << endl;
    }

    void searchByYear() {
        int targetYear;
        cout << "입사 연도를 입력하세요 >> ";
        cin >> targetYear;

        int count = 0;

        for (int i = 0; i < size; i++) {
            if (p[i].getYear() >= targetYear) {
                cout << i + 1 << " ]  name: " << p[i].getName() << ", dept: " << p[i].getDept() << ", year: " << p[i].getYear() << endl;
                count++;
            }
        }

        cout << targetYear << "년도 이후에 입사한 사원은 " << count << "명 입니다." << endl;
    }
};

int main() {
    int size;
    cout << "사원수를 입력하세요 >> ";
    cin >> size;

    if (size <= 0) {
        cout << "양수를 입력하세요." << endl;
        return 0;
    }

    Manager manager(size);

    manager.searchByName();
    manager.searchByYear();

    return 0;
}