#include<iostream>
using namespace std;

template <typename T>
void log(T items, string prefix) {
  cout << prefix << items << endl;
}

class Cake {
  private : 
	  string type;
	  float quantity;
	public:
	  void Purchase(string t, float q){
		  type = t;
		  quantity = q;
	  }
    string getType(){
      return type;
    }

    int getQuantity(){
      return quantity;
    }
};


int main()
{
    Cake *ck;
    int noCake, i, qty;
    string cakeType; 
    
    cout<<"Enter how many type of cake : ";
    cin>>noCake;
    
    Cake *arr = new Cake[noCake];
    
  for(i=0;i<noCake;i++){
    cout<<"\nEnter type of cake <fondant, sponge, meringue> : ";
    cin>>cakeType;
    cout<<"Enter quantity : ";
    cin>>qty;
    (arr+i)->Purchase(cakeType,qty); // arrow (->), read the question 
  }
    
  cout<<"\nYou have purchased : "<<endl;
  for(i=0;i<noCake;i++){
    log((*(arr+i)).getType(),"Type  :"); // the complier is smart to identify the typedef
    log((*(arr+i)).getQuantity(),"Quantity  :"); // unless you enforcing a type
  }
  
  delete [] arr; // remember to delete, the operating system maybe be merciful, but the lecture will not!!

	return 0;
}
