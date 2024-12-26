#include <iostream>
#include <string>

using namespace std;

class Point {
    int x, y;
public:
	Point(int x, int y) { 	this->x = x; this->y = y; }
	int getX() { return x; }
	int getY() { return y; }
protected:
	void move_up(int x, int y) { this->x += x; this->y += y; }
	void move_down(int x, int y) { this->x -= x; this->y -= y; }
};

class ColorPoint : public Point {
    string color; 
public:
    ColorPoint() : Point(0, 0), color("BLACK") {
        cout << "ZeroPoint 객체 출력" << endl;
        cout << color << "색으로 (" << getX() << ", " << getY() << ")에 위치한 점입니다." << endl;
    }

    ColorPoint(int x, int y, string color = "BLACK") : Point(x, y), color(color) {}
    

    void setPoint(int dx, int dy, char dir) {
        if (dir == '+') {
            move_up(dx, dy);
        } else if (dir == '-') {
            move_down(dx, dy);
        }
        cout << color << "색으로 (" << getX() << ", " << getY() << ")에 위치한 점입니다." << endl;
    }

    void setColor(string color) {
        this->color = color;
    }
};

int main() {
    ColorPoint zeroPoint; // BLACK에 (0, 0) 위치의 점
    ColorPoint blue(5, 5);

    cout << endl << "blue 객체 출력" << endl;
    cout << "현재 위치에서 x:+10, y:+20 위치로 이동합니다" << endl;
    blue.setPoint(10, 20, '+');
    
    ColorPoint red(50, 40, "RED");
    cout << endl << "red 객체 출력" << endl;
    cout << "현재 위치에서 x:-10, y:-20 위치로 이동합니다" << endl;
    red.setPoint(10, 20, '-');

    return 0;
}



