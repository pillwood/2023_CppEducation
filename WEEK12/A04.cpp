#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Circle {
	int radius;
public:
	Circle(int radius = 0) { this->radius = radius; }
	int getRadius() { return radius; }
	void setRadius(int radius) { this->radius = radius; }
	double getArea() { return 3.14*radius*radius; };
};

// Circle 클래스를 상속받은 NamedCircle 클래스
class NamedCircle : public Circle {
    string name;
public:
    NamedCircle(int radius = 0, string name = "") : Circle(radius), name(move(name)) {}

    void set(int radius, string name) {
        setRadius(radius);
        this->name = move(name);
    }

    const string& getName() const { return name; }

    //int size(const NamedCircle c[]){
    //    int arrayLength = sizeof(c) / sizeof(c[0]);
    //    return arrayLength;
    //}
};

string biggest(NamedCircle c[], int size) {
    int index = 0;
    double maxArea = 0;
    for (int i = 0; i < size; ++i) {
        if (c[i].getArea() > maxArea) {
            maxArea = c[i].getArea();
            index = i;
        }
    }
    return c[index].getName();
};


int main() {
    NamedCircle c[5];
    cout << "5 개의 정수 반지름과 원의 이름을 입력하세요" << endl;
    for (int i = 0; i < 5; i++) {
        int r;
        string name;
        cout << i + 1 << ">> ";
        cin >> r;
        getline(cin, name);
        if (r <= 0) {
            cout << "다시 입력하세요" << endl;
            i--;
            continue;
        }
        c[i].set(r, name);
    }
    int arrayLength = sizeof(c) / sizeof(c[0]);
    cout << "가장 면적이 큰 피자는 " << biggest(c, arrayLength) << "입니다" << endl; 
    return 0;
}