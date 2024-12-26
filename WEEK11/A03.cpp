#include <iostream>
#include <string>

using namespace std;

class Matrix{
  int ar[4];

public:
    Matrix(int a1 = 0, int a2 = 0, int b1 = 0, int b2 = 0) {
        ar[0] = a1;
        ar[1] = a2;
        ar[2] = b1;
        ar[3] = b2;
    };
    void show(string matrix);
    Matrix operator+(const Matrix& op) const;
    Matrix& operator+=(const Matrix& op);
    Matrix& operator>>(int arr[4]);
    Matrix& operator<<(const int arr[4]);    
};

void Matrix::show(string matrix){
    cout << "====" << matrix << "====" << endl;
    cout << matrix << " = { " << ar[0] << " " << ar[1] << " " << ar[2] << " " << ar[3] << " }" << endl;
}

Matrix Matrix::operator+(const Matrix& op) const {
    Matrix temp;
    for (int i = 0; i < 4; i++) {
        temp.ar[i] = this->ar[i] + op.ar[i];
    }
    return temp;
}

Matrix& Matrix::operator+=(const Matrix& op) {
    for (int i = 0; i < 4; i++) {
        this->ar[i] += op.ar[i];
    }
    return *this;
}

Matrix& Matrix::operator>>(int ar[4]) {
    for (int i = 0; i < 4; i++) {
        ar[i] = this->ar[i];
    }
    return *this;
}

Matrix& Matrix::operator<<(const int ar[4]) {
    for (int i = 0; i < 4; i++) {
        this->ar[i] = ar[i];
    }
    return *this;
}


int main(){
  Matrix a(1, 2, 3, 4), b(2, 3, 4, 5), c;
  c = a + b;
  a += b;
  a.show("matrix a");
  b.show("matrix b");
  c.show("matrix c");

  int x[4], y[4] = {5, 6, 7, 8};
  a >> x; // a의 각 원소를 배열 x에 복사. 
  b << y; // 배열 y의 원소 값을 b의 각 원소에 설정

  cout << ">> 배열 x의 원소 출력 << " << endl;
  for (int i = 0; i < 4; i++)
    cout << x[i] << ' '; // x[] 출력
  cout << endl;
  cout << ">> 배열 y값을 객체(b)에 복사 << " << endl;
  b.show("matrix b");
}


