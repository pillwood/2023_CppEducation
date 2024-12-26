#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Student {
    string name;
    int id;
public:
    Student() = default;
    Student(string name, int id) : name(name), id(id) {}
    void show(){
        cout << "name: " << name << ",    id: " << id << endl;
    }
};

class Manager {
    vector<Student> vec;
public:
    void run();
    void print();
    void save();
};

void Manager::run() { 
    save();
    print();
}

void Manager::print(){
    cout << endl << ">>> 벡터에 저장된 모든 학생 데이터를 출력합니다 <<<" << endl;
    for (auto& student : vec) {
        student.show();
    }
}

void Manager::save() {
    string name;
    int id;
    int count=0;
    cout << ">>> 벡터에 학생 데이터를 저장합니다 <<<" << endl;
    cout << "학생의 이름을 입력해주세요 (종료하려면 'fin'을 입력): " << endl;
    while (true) {
        cout << "name >>";
        cin >> name;
        if (name == "fin") {
            cout << count << "명의 학생이 저장되었습니다.";
            break;
        }
        cout << "id >>";
        cin >> id;
        vec.emplace_back(Student(name, id));
        count ++;
    }
}

int main() {
    Manager man;
    man.run();
    return 0;
}