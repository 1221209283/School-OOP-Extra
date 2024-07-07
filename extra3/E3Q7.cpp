#include<iostream>
using namespace std;

class CarProduct{
  string mo;
  int qty;

public:
  CarProduct() {
    cout<<"----Generating----"<<endl;
  }

  ~CarProduct() {
    cout<<"----The end----"<<endl;
  }

  void setdata(string m, int q) {
    mo = m;
    qty = q;
  }

  string get_mo() {
    return mo;
  }

  int get_qty() {
    return qty;
  }
};

int main(){
  string mo[5]= { "Jan", "Feb", "Mac", "Apr", "Mei"};
  int i, q[5] = { 43, 65, 4, 0, 14};
  CarProduct M1[5];

  for( i=0; i<5; i++) {
    M1[i].setdata(mo[i], q[i]);
  }

  i=0;

  while(i<5){ //2.1 c) write your answer on your answer booklet
    int ten = 0, one = 0;
    cout << "Month " << M1[i].get_mo() << ':';

    ten = (int) M1[i].get_qty() / 10;
    one = M1[i].get_qty() % 10;

    if((ten + one) < 1) cout << " No production";

    for(int i = 0;i < ten;i++) cout << " *";
    for(int i = 0;i < one;i++) cout << " #";
    cout << endl;

    i++;

    cout << endl;
  }

  return 0;
}
