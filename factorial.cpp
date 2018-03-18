// this code is used to calculate factorial

#include <iostream>
#include <climits>

class Factorial{
 public:
  Factorial(unsigned short n);
  unsigned long getFactorial();
  bool inRange();

 private:
  unsigned short num;
};

// member function
Factorial::Factorial(unsigned short n)
{
  this->num = n;
}

unsigned long Factorial::getFactorial()
{
  unsigned long sum = 1;

  for(int i = num; i >= 1; i--){
    sum *= i;
  }

  return sum;
}


bool Factorial::inRange()
{
  unsigned long max = ULONG_MAX;

  for(int i = num; i >= 1; i--){
    max /= i;
  }

  return (max > 1) ? true : false;
}

int main()
{
  unsigned short num = 0;

  std::cout << "enter a num" << std::endl;
  std::cin >> num;

  Factorial fac(num);

  if(fac.inRange()){
    std::cout << num << "'s factorial is " << fac.getFactorial() << std::endl;
  }
  else{
    std::cout << "the num " << num << " is too large for me to calculate." << std::endl;
  }

  return 0;
}
