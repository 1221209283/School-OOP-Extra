#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

const int SIZE = 5;

template <typename T>

void log(T items, string prefix)
{
  cout << prefix << fixed << setprecision(2) <<  items << endl;
}

class Shoes
{
protected:
  string type;
  string material;

public:
  void setShoes(string t, string m)
  {
    type = t;
    material = m;
  }
  virtual void setSales()
  {
  }
};

class DesignerShoes : public Shoes
{
private:
  string name;
  string month[SIZE];
  float sales[SIZE];
  float total;

public:
  DesignerShoes(string n, string t, string m)
  {
    name = n;
    setShoes(t, m);
    total = 0;
    string temp[SIZE] = {"Jan", "Feb", "Mac", "Apr", "May"};
    for (int i = 0; i < SIZE; i++)
    {
      month[i] = temp[i];
    }
  }
  void setSales()
  {
    for (int i = 0; i < SIZE; i++)
    {
      cout << "Enter Sales " << month[i] << ": ";
      cin >> sales[i];
      total+= sales[i];
    }
  }
  void display()
  {
    log(name, "Name: ");
    log(type, "Type: ");
    log(material, "Material: ");
    log(total, "Total: ");
  }
  float friend Average(DesignerShoes *t);
};

float Average(DesignerShoes *t)
{
  float temp = 0;
  for(int i = 0 ; i < SIZE; i++){
    temp+=t->sales[i]; 
  }
  return temp/5;
}


int main(){
  DesignerShoes *p = new DesignerShoes("Bedazzled-Stone101","Evening","Synthetic");
  p->setSales();
  DesignerShoes *q = new DesignerShoes("Summer","Casual","Cotton");
  q->setSales();
  DesignerShoes *r = new DesignerShoes("BeautifulDay","Casual","Leather");
  r->setSales();
  p->display();
  log(Average(p),"Average :");
  q->display();
  log(Average(q),"Average :");
  r->display();
  log(Average(r),"Average :");

}