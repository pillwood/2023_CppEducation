#include <iostream>

class Square {
protected: // 파생 클래스에서 접근할 수 있도록 protected로 선언
    double side;

public:
    // 생성자
    Square(double side) : side(side) {
        std::cout << "Square with side " << side << " is created." << std::endl;
    }

    // 소멸자
    virtual ~Square() {
        std::cout << "Square with side " << side << " is destroyed." << std::endl;
    }

    // 둘레를 구하는 멤버 함수
    double getPerimeter() const {
        return 4 * side;
    }

    // 넓이를 구하는 멤버 함수
    double getArea() const {
        return side * side;
    }
};

class Cube : public Square {
public:
    // Cube 클래스의 생성자는 Square 클래스의 생성자를 호출하여 side를 초기화한다.
    Cube(double side) : Square(side) {
        std::cout << "Cube with side " << side << " is created." << std::endl;
    }

    // 소멸자
    ~Cube() {
        std::cout << "Cube with side " << side << " is destroyed." << std::endl;
    }

    // 겉넓이를 구하는 멤버 함수
    double getSurface() const {
        return 6 * getArea(); // Square의 getArea() 함수를 사용
    }

    // 부피를 구하는 멤버 함수
    double getVolume() const {
        return side * side * side;
    }
};

int main() {
    // 정사각형 객체 생성 및 테스트
    Square square(4.0);
    std::cout << "Perimeter of Square: " << square.getPerimeter() << std::endl;
    std::cout << "Area of Square: " << square.getArea() << std::endl;

    // 정육면체 객체 생성 및 테스트
    Cube cube(4.0);
    std::cout << "Surface area of Cube: " << cube.getSurface() << std::endl;
    std::cout << "Volume of Cube: " << cube.getVolume() << std::endl;

    return 0;
}