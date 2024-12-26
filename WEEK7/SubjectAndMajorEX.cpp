#include <iostream>
#include <string>
#include <memory>

using namespace std;

class Subject
{
    string pname; // 과목명

public:
    Subject(){};
    Subject(string pname)
    {
        this->pname = pname;
    };

    string getName() const
    {
        return pname;
    };

    void setName(string pname)
    {
        this->pname = pname;
    };
};

class Major
{
    string fname;            // 전공
    unique_ptr<Subject[]> p; // Subject 배열을 가리키는 스마트 포인터
    int size;                // Subject 배열의 크기(전공과목 수)

public:
    Major(string fname, int size)
    { // size 개수(전공과목)만큼 Subject 배열 동적 생성
        this->fname = fname;
        this->size = size;
        p = unique_ptr<Subject[]>(new Subject[size]); // subject를 size 길이의 배열로 생성
    }

    void setName()
    { // Subject 배열 초기화
        string pname;
        for (int i = 0; i < size; i++)
        {
            cout << "과목명을 입력하세요 >> ";
            cin >> pname;
            p[i].setName(pname);
        }
    }

    void show()
    { // 전공 과목 출력
        for (int i = 0; i < size; i++)
        {
            cout << " " << p[i].getName() << endl;
        }
    }

    ~Major()
    { // Major 소멸자
        cout << endl
             << fname << " 소멸자 실행" << endl;
    }
};

int main()
{
    Major *major;
    int size;
    string name;

    cout << "전공 교과목 수를 입력하세요 >> ";
    cin >> size;
    cout << "전공명을 입력하세요 >> ";
    cin >> name;

    major = new Major(name, size); // 전공과 전공 과목 개수
    major->setName();
    cout << endl
         << name << " 전공과목은 " << size << "개 입니다." << endl;
    major->show();

    delete major;
    return 0;
}
