#include <iostream>
#include <array> 
#include <algorithm> 
using namespace std;


//void swap(int *a, int& b);
//void swap(int &a, int b);
//void swap(int a, int b);
//void swap(int a, int *b);
void swap(int &a, int &b);

int main(){
    int a1=60, b1=90;
    //swap(a1,b1);
    //cout<<"1번   >>   a(원래 값 60) : "<<a1<<",    b(원래 값 90) : "<<b1<<endl;

    int a2=60, b2=90;
    //swap(a2,b2);
    //cout<<"2번   >>   a(원래 값 60) : "<<a2<<",    b(원래 값 90) : "<<b2<<endl;

    int a3=60, b3=90;
    //swap(a3,b3);
    //cout<<"3번   >>   a(원래 값 60) : "<<a3<<",    b(원래 값 90) : "<<b3<<endl;

    int a4=60, b4=90;
    //swap(a4,b4);
    //cout<<"4번   >>   a(원래 값 60) : "<<a4<<",    b(원래 값 90) : "<<b4<<endl;

    int a5=60, b5=90;
    swap(a5,b5);
    cout<<"5번   >>   a(원래 값 60) : "<<a5<<",    b(원래 값 90) : "<<b5<<endl;


}