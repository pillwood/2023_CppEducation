#include <iostream>
#include <vector>
#include <initializer_list>
#include <string>

using namespace std;

class Custom {
    string id;
    int mileage;
public:
    Custom(string id, int mileage);
    string getId() const; //id 반환
    void setMileage(int mileage); //매개변수로 받은 값만큼 마일리지 추가
    void write() const; //id와 mileage 출력
};

Custom::Custom(string id, int mileage) : id(id), mileage(mileage) {}

string Custom::getId() const { //id 반환
    return id;
}

void Custom::setMileage(int add) { //매개변수로 받은 값만큼 마일리지 추가
    mileage += add;
}

void Custom::write() const { //id와 mileage 출력
    cout << "[ id = " << id << ", mileage = " << mileage << " ]" << endl;
}

class Control {
    vector<Custom> cus;
    void list(); //벡터에 저장된 모든 데이터 출력
    void search(); //벡터에 저장된 Custom 객체에서 입력된 id와 일치하는 객체의 마일리지 변경
public:
    Control(initializer_list<Custom> custom);
    void start(); //list(), search() 호출
};

Control::Control(initializer_list<Custom> custom) : cus(custom) {}

void Control::list() { //벡터에 저장된 모든 데이터 출력
    cout << "===== vector에 저장된 모든 Custom 객체를 출력합니다 =====" << endl;
    for (const auto& cu : cus) {
        cu.write();
    }
}

void Control::search() { //벡터에 저장된 Custom 객체에서 입력된 id와 일치하는 객체의 마일리지 변경
    string searchId;
    int mileageToAdd;
    cout << "===== vector에 저장된 id를 검색하여 mileage를 추가합니다 =====" << endl;
    cout << "검색할 id를 입력하세요 >> ";
    cin >> searchId;
    for (auto& cu : cus) {
        if (cu.getId() == searchId) {
            cout << "추가할 mileage를 입력하세요 >> ";
            cin >> mileageToAdd;
            cu.setMileage(mileageToAdd);
            cu.write();
            return;
        }
    }
    cout << searchId << "가 존재하지 않습니다." << endl;
}

void Control::start() { //list(), search() 호출
    list();
    search();
}

int main() {
    Control con {Custom{"hallym", 40}, Custom{"bigdata", 30}, Custom{"computer", 35}, Custom{"Jerry", 90}};
    con.start();
}