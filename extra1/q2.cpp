#include <iostream>
using namespace std;

const float price = 10.50;
class simcard
{
private:
  string name, ic;
  float payment;
  int quantity;

public:
  void display()
  {
    cout << "Enter your name : ";
    getline(cin, name);
    cout << "Enter your IC : ";
    getline(cin, ic);
    cout << "Enter simcard quantity : ";
    cin >> quantity;
      }
void calculate()
{
  cout <<  quantity * 18;
}
  };

int main()
{
  simcard person1;
  person1.display();
  person1.calculate();
}
