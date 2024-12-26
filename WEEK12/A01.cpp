#include <iostream>
#include <string>

using namespace std;


class Array{
private:
	double* ptr;
	int size;
public:
	Array(int size);  //size크기를 갖는 배열 동적 생성
    Array(const Array& aarr); // 복사 생성자
	~Array(); //소멸자
    void show();
    //[]연산자와 = 연산자 함수 
    double &operator[](int index) const;
    double &operator[](int index);
    Array &operator=(const Array& aarr);
};

Array::Array(int size) : size{size}, ptr{new double[size]} {}

Array::Array(const Array& aarr) : size{aarr.size}, ptr{new double[aarr.size]} {
    for (int i = 0; i < size; ++i) {
        ptr[i] = aarr.ptr[i];
    }
}

Array::~Array(){delete[] ptr;}

void Array::show() {
    for (int i = 0; i < size; ++i) {
        cout << ptr[i] << "  ";
    }
    cout << endl << endl;
}

double& Array::operator[](int index) const{
    if (index < 0 || index >= size) {
        cout << "(const)Index is out of range. Program terminates."<<endl;
        exit(1);
    }
    return ptr[index];
}
double& Array::operator[](int index){
    if (index < 0 || index >= size) {
        cout << "Index is out of range. Program terminates."<<endl;
        exit(1);
    }
    return ptr[index];
}

Array &Array::operator=(const Array& aarr) {
    if (this != &aarr) {
        delete[] ptr;
        size = aarr.size;
        ptr = new double[size];
        for (int i = 0; i < size; ++i) {
            ptr[i] = aarr.ptr[i];
        }
    }
    return *this;
}

int main(){
    Array arr{5}, brr{5};
  
    for (int i = 0; i < 5; i++) {
        cout << i+1 <<") input>> ";
        cin >> arr[i];
    }
  
    cout<<"==== Value of arr===="<<endl;
    arr.show();
  
    brr = arr;
    brr[2] = 34.5;
    brr[4] = 56.3;
    cout<<"==== Value of brr===="<<endl;
    brr.show();
  
    cout<<"==== Value of arr===="<<endl;
    arr.show();
 
    return 0;
}
