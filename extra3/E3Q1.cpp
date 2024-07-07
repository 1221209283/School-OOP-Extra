#include <iostream> 

using namespace std; 

class PassCode {
private: 

  unsigned int num; 

public: 
  int create_LockAcc(int key) {
      if(key == 0 || key == 1) {
        return key; 
      }else{
        return create_LockAcc(key - 1) + create_LockAcc(key - 1);
      } 
  } 

}; 

int main() {	
  int key, num; 

  cout << "How many Lock-Access want to create? "; 

  cin >> num; 

  cout << endl; 

  PassCode* p;

  p = new PassCode[num];

  for(int i = 0;i < num;i++){

    cout << "Enter key   : ";

    cin >> key;

    cout << "Your Lock Access is: " << p[i].create_LockAcc(key) << endl;

    cout << endl;
  }

  delete [] p; 
  return 0;
} 
