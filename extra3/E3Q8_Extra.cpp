class Test{
  float a=0,b=0;
public:

  Test() = default;

  Test(float a,float b)
    :
    a(a),
    b(b)
  {}

  Test& operator=(const Test& x) { // there is no limition of return type (depends on situation)
    a = x.a;
    b = x.b;
    return *this; // return same type return is a must for multiple assignment 
  }

  Test operator-(const Test& x) const {
    return Test((a - x.a), (b - x.b));
  }

  Test operator+(const Test& x) const {
    return Test((a + x.a), (b + x.b));
  }
};

int main() {
  Test p1(4.0, 10.0);
  Test p2(6.0, 3.0);
  Test p3;
  p3 = p1 - p2 ;
  p3 = p1 + p2;
  return 0;
}
