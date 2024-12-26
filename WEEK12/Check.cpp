#include <iostream>
#include <string>

using namespace std;


class Human{
    string name;
    int age;
    public:
    Human(string name, int age) : name{name}, age{age}{}
    string getName() const{return name;}
    int getAge() const{return age;}
};

class Student : public Human{
    
    string major;
    public:
    Student(string name, int age, string major) : Human(name, age), major{major}{}
    string getMajor() const{return major;}
};

class Manage{
    public:
    static void print(Student std){
        cout << "name >> " << std.getName() << endl;
        cout << "age >> " << std.getAge() << endl;
        cout << "major >> " << std.getMajor() << endl;
    }
};

int main(){
    Student std1{"펭수", 10, "software"};
    Student std2{"둘리",20,"computer"};

    Manage::print(std1);
    Manage::print(std2);
}