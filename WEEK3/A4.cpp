#include <iostream>
using namespace std;
enum class NUM
{
  OCT = 8,
  DEC = 10,
  HEX = 16,
};
bool check(int input)
{
  if (input == 10 || input == 16 || input == 8)
    return true;
  else
    return false;
}
int main()
{
  int value;
  int input;

  cout << "여러 진법으로 출력 하기 oct(8), hex(16), dec(10)" << endl;

  while (true)
  {
    cout << "해당 진법 입력 : ";
    cin >> input;
    if (check(input) == false)
    {
      cout << "해당 진법이 없습니다."<<endl;
      break;
    }

    cout << "데이터 입력 : ";
    cin >> value;

    switch (static_cast<NUM>(input))
    {
    case NUM::OCT:
      cout << "=> 8진법 : " << "0" <<oct << value << endl;
      break;
    case NUM::DEC:
      cout << "=> 10진법 : " << dec << value << endl;
      break;
    case NUM::HEX:
      cout << "=> 16진법 : " <<"0x"<< hex << value << endl;
      break;
    }
  }
  cout << "program stop" << endl;
  return 0;
}
