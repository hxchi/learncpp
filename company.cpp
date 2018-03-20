// use new and delete

#include <iostream>
#include <string>

using std::cout; using std::endl; using std::string;

class Company{
public:
  Company(string theName);
  virtual void _printInfo();
  
private:
  string name;
};

class TechCompany : public Company{
public:
  TechCompany(string theName, string theProduct);
  virtual void _printInfo();
private:
  string product;
};


// member function
Company::Company(string theName)
{
  name = theName;
}

void Company::_printInfo()
{
  cout << "the company name is " << name << endl;
}

TechCompany::TechCompany(string theName, string theProduct) : Company(theName)
{
  this->product = theProduct;
}

void TechCompany::_printInfo()
{
  cout << "this techcompany's product is " << product << endl;
}


// main
int main()
{
  Company *com = new Company("apple");
  com->_printInfo();

  delete com;
  com = NULL;

  com = new TechCompany("apple", "iphone");
  com->_printInfo();

  delete com;
  com = NULL;

  return 0;
}
