#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class MyClass{
    int size;
    int *element;
    public:
    MyClass(int size);
    MyClass(const MyClass &my);
    MyClass(MyClass &&my)noexcept;
    ~MyClass();
    void change(int,int);
    void write(const string&&);
};

MyClass::MyClass(int size) : size(size), element(new int[size]){
    for(auto i=0; i<size; i++){
        element[i] = 0;
    }
}

void MyClass::change(int index, int value){
    element[index] = value;
}

void MyClass::write(const string&& message){
    cout<< "==== " << message << " ====" << endl;
    for(int i=0; i<size; i++){
        cout << setw(4) << element[i];
    }
    cout << endl;
}

MyClass::MyClass(const MyClass &my){
    size = my.size;
    element = new int[size];
    for(auto i=0; i<size; i++){
        element[i] = my. element[i];
    }
}

MyClass::MyClass(MyClass &&my)noexcept{
    size = my.size;
    element = my.element;
    my.size=0;
    my.element = nullptr;
    
};

MyClass::~MyClass(){
    if(!element){
        delete[] element;
    }
}

void print(MyClass &&my, string &&message){
    //move(my).write(move(message));
    my.write(move(message));    
}

int main(){
    MyClass my{5};
    my.write("original(my)");
    my.change(2,30);
    my.change(4,15);
    my.write("change(my)");
    
    MyClass copy{my};   //MyClass copy{move(my)}로 수정 후 실행 결과
    copy.write("copy after");
    my.write("original(my)");
    copy.change(1,23);
    copy.change(4,61);
    print(move(copy), "change(copy)");
}