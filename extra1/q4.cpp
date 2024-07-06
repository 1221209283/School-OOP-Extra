#include <iostream>
using namespace std;
class House
{
protected:
  int id;
  float price;

public:
  void set()
  {
    id = 111;
    price = 355000;
  }
  void display(int id, float price) 
  {
    cout << "House Record:" << endl;
    cout << "House ID : " << id << endl;
    cout << "Price : RM " << price << endl;
  }
  virtual void display(){
    
  };
};
class Bungalow : public House
{
private:
  string name = "Elegent";
  float tax = 0.12, total;

public:
  void calculate()
  {
    total = price + (tax * price);
  }
  void display() override
  {
    cout << "Bungalow Record:" << endl;
    cout << "House name : " << name << endl;
    cout << "House ID : " << id << endl;
    cout << "Price : RM " << price << endl;
    cout << "Total : RM " << total << endl;
  }
};
int main()
{
  House *h;
  h = new House();
  Bungalow *b;
  b = new Bungalow();
  b->set();
  b->calculate();
  h = b;
  h->display();
  b->display();
}
