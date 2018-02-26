#include "Screen.h"
#include <iostream>
#include <string>

using std::cin; using std::cout; using std::endl;
using std::string;

int main()
{
  Screen s1(5, 5, 'X');
  cout << "test here..." << endl;
  s1.Move(4,0).SetContent('#').display(cout);
  cout << endl;
  
  s1.display(cout);
  cout << endl;

  return 0;
}
