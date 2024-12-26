#include <iostream>
#include <string>

using namespace std;

class Point {
    int x, y;
public:
    Point(int xp = 0, int yp = 0) :x(xp), y(yp) {}
    void show(string obj) {
        cout << obj << "=> x: " << x << ", y: " << y << endl;
    }
    Point operator+(const Point& op) const;

    friend ostream& operator<<(ostream& out, const Point& op);
    friend istream& operator>>(istream& in, Point& op);
    friend Point operator*(Point& op1, Point &op2);
};

Point Point::operator+(const Point& op)const{
    Point temp;
    temp.x = this->x + op.x;
    temp.y = this->y + op.y;
    return temp;
}

ostream& operator<<(ostream& out, const Point& op){
    out << " => " << "x : " << op.x << "y : " << op.y << endl;
    return out;
}
istream& operator>>(istream& in, Point& op){
    int x,y;
    cout << "input(x,y) >> " << endl;
    in >> op.x >> op.y;
    return in;
}
Point operator*(Point& op1, Point& op2){
    Point temp;
    temp.x = op1.x * op2.x;
    temp.y = op1.y * op2.y;
    return temp;
}

int main(){
    Point p1{}, p2{5, 6};
    Point p3{};

    cin >> p1;  //외부 함수로 구현
    p3 = p1 + p2; //내부 함수로 구현 

    cout<<"p1 => ";
    cout<<p1;  //외부 함수로 구현
    p2.show("p2");
    p3.show("P1+p2");
    p3 = p1 * p2; //외부함수로 구현
    p3.show("P1*p2");
}

