#include<iostream> // line 1
using namespace std; // line 2

class Coordinate{

private:
  double a,b;

public:
  Coordinate() {
    a = b = 0.0;
  }

  Coordinate(double a_arg, double b_arg) {
    a = a_arg;
    b = b_arg;
  }

  Coordinate operator+(const Coordinate& p) {
    return Coordinate(a + p.a, b + p.b);
  }

  void display() { 
    cout<<"a :"<<a<<", b :"<<b<<endl;
  }
};

int main() { 
  Coordinate ob1, ob2(1.5, 3.5), ob3(5.0, 7.0) ;
  ob1 = ob2 + ob3;
  ob1.display();
  ob2.display();
  return 0;
}
