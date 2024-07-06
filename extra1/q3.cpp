#include <iostream>
#include <iomanip>
using namespace std;
class fruit
{
private:
  string name;
  float weight, price, payment;

public:
  fruit()
  {
    cout << "Welome to the Fruit Record System" << endl;
  }

  ~fruit()
  {
    cout << "Thank You" << endl;
  }
  fruit(const fruit &f)
  {
    payment = f.payment;
  }
  void get_data()
  {
    cout << "Enter fruit name: ";
    cin >> name;
    cout << "Enter fruit weight: ";
    cin >> weight;
    cout << "Enter fruit price: ";
    cin >> price;
  }
  void calculate()
  {
    payment = weight * price;
  }
  void display()
  {
    cout << "Fruit Name: " << name << endl;
    cout << "Total Price: RM"  << price << endl;
    cout << "Total Payment : RM" << fixed << setprecision(2) << payment << endl;
  }

  friend void summary(fruit f);
};


class organic_fruit: public fruit{

  friend void summary(fruit f);
};

void summary(fruit f)
{
  f.get_data();
  f.calculate();
  f.display();
}
int main()
{
  fruit f;

  static int i = 0;
  do
  {
    i++;
    cout << "Record " << i << endl;
    summary(f);
  } while (i < 2);
}