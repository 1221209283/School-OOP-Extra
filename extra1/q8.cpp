#include <iostream>
#include <iomanip>
using namespace std;
class Calculate
{
private:
  int total;
  float price_per_cm;

public:
  Calculate(int ttl)
  {
    total = ttl;
    price_per_cm = 2.00;
  }

  void Display()
  {
    cout << "Perimeter (cm) : " << total << endl;
    cout << "Ribbon price per cm(RM) : " << fixed
         << setprecision(2) << price_per_cm << endl;
    cout << "Total ribbon price (RM) : " << fixed
         << setprecision(2) << total * price_per_cm << endl;
  }
};

class Trapezium
{
private:
  int perimenter;

public:
  Calculate operator+(const Trapezium t)
  {
    return Calculate(this->perimenter + t.perimenter);
  }
  void setPerimeter(){
    cout << "Enter trapezium perimeter: ";
    cin >> perimenter;
  }
};
int main()
{
  Trapezium a,b;
  a.setPerimeter();
  b.setPerimeter();
  Calculate c = a+b ;
  c.Display();
}