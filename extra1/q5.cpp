#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
template <typename T>

void log(T items, string prefix)
{
  cout << prefix << items << endl;
}

class Guard_House
{
protected:
  string id;
  float hour, salary, net_salary, bonus, payment;

public:
  Guard_House()
  {
    cout << "Welcome to Guard House Salary System" << endl;
    id = "Invalid";
  }
  ~Guard_House()
  {
    cout << "Thank You" << endl;
  }
  virtual void set_data(string id, float extra_hour)
  {
    this->id = id;
    this->hour = extra_hour;
  }
  string getid()
  {
    return id;
  }
  float getbonus()
  {
    return bonus;
  }
  float getpayment()
  {
    return payment;
  }
  float getnetsalary()
  {
    return net_salary;
  }
  void display()
  {
    log<string>(id, "ID: ");
    log<float>(bonus, "Bonus: ");
    log<float>(payment, "Payment: ");
    log<float>(net_salary, "Net Salary: ");
  }
};

class normal_hour : public Guard_House
{
private:
  float salary = 1200;

public:
  void set_data(string id)
  {
    this->id = id;
  }
  void cal_net_salary()
  {
    this->bonus = salary * 1.2;
    this->net_salary = salary + this->bonus;
  }
};
class shift_hour : public Guard_House
{
private:
  float salary = 850;

public:
  void set_data(string id, float extra_hour)
  {
    this->hour = extra_hour;
    this->id = id;
  }
  void cal_net_salary()
  {
    this->bonus = salary * 1.2;
    this->payment = this->hour * 55;
    this->net_salary = this->payment + salary + this->bonus;
  }
};

class contract : public shift_hour
{
public:
  void repeat(string id, float hour)
  {
    set_data(id, hour);
    shift_hour::cal_net_salary();
  }
};

int main()
{
  string id;
  string type;
  float extra_hour;
  for (int i = 0; i < 3; i++)
  {

    cout << "Enter ID: ";
    getline(cin, id);
    cout << "Enter Type: ";
    getline(cin, type);
    if (type.compare("Normal") == 0)
    {
      normal_hour *nh = new normal_hour();
      nh->set_data(id);
      nh->cal_net_salary();
      log<float>(nh->getbonus(), "Bonus: ");
      log<float>(nh->getpayment(), "Payment: ");
      log<float>(nh->getnetsalary(), "Net Salary: ");
    }
    else if (type.compare("Shift") == 0)
    {
      shift_hour *sh = new shift_hour();
      cout << "Enter Extra Hour:";
      cin >> extra_hour;
      sh->set_data(id, extra_hour);
      sh->cal_net_salary();
      sh->display();
    }
    else if (type.compare("Contract") == 0)
    {
      contract *ch = new contract();
      cout << "Enter Extra Hour:";
      cin >> extra_hour;
      ch->set_data(id, extra_hour);
      ch->cal_net_salary();
      ch->display();
    }
    else
    {
      Guard_House gh;
      cout << "Invalid Type" << endl;
    }
  }
}