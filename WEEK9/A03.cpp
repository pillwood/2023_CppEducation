#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

class Dept {
	int size;       // scores 배열의 크기
	int* scores;    // 동적 할당 받을 정수 배열의 주소
public:
	Dept(int size);             //매개변수로 받은 배열 크기만큼 scores 배열 생성 
	Dept(Dept& dept);           //복사 생성자
	~Dept();                    //소멸자
	int getSize();              //배열 크기 반환
	void read();                // size 만큼 키보드에서 정수를 읽어 scores 배열에 저장
	bool isOver60(int index);   // index의 학생의 성적이 60보다 크면 true 리턴
};

Dept::Dept(int size) : size(size), scores(new int[size]) 
{//매개변수로 받은 배열 크기만큼 scores 배열 생성 
	for (int i = 0; i < size; i++) {
		scores[i] = 0;
	}
}

Dept::Dept(Dept& dept) : size(dept.size), scores(new int[dept.size]) 
{//복사 생성자
	for (int i = 0; i < size; i++) {
		scores[i] = 0;
	}
}

Dept::~Dept() 
{//소멸자
	delete[] scores;
}

int Dept::getSize() 
{//배열 크기 반환
	return size;
}

void Dept::read() 
{// size 만큼 키보드에서 정수를 읽어 scores 배열에 저장
	cout << size << "개 점수 입력 >>" << endl;
	for (int i = 0; i < size; i++) {
		cout << i + 1 << "] ";
		cin >> scores[i];
	}
}

bool Dept::isOver60(int index) 
{// index의 학생의 성적이 60보다 크면 true 리턴
    if(scores[index] >= 60){
        return true;
    }else{
        return false;
    }
}

int countPass(Dept& dept) 
{//학과에 60점 이상으로 통과한 학생의 수를 리턴
	int cnt = 0;
	for (int i = 0; i < dept.getSize(); i++) {
		if (dept.isOver60(i)) {
			cnt++;
		}
	}
	return cnt;
}

int main() {
	Dept *com;
	int cnt;
	cout << "학생 수를 입력하세요 >> ";
	cin >> cnt;
	com = new Dept(cnt);        //입력한 학생 수만큼 scores 배열 생성
	com->read();                //학생들의 성적을 키보드로부터 읽어 scores 배열에 저장
	int n = countPass(*com);    // com 학과에 60점 이상으로 통과한 학생의 수를 리턴
	cout << "60점 이상은 " << n << "명" << endl;
	delete com;
}