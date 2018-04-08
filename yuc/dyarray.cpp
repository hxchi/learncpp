#include <iostream>
#include <string>

using std::cout; using std::endl; using std::cin;
using std::string;

int main()
{
  unsigned int cnt;
  cout << "enter a unsigned int number: ";
  cin >> cnt;

  int *x = new int[cnt];
  for(int i = 0; i < (int)cnt; i++){
    x[i] = i*i;
  }

  for(int i = 0; i < (int)cnt; i++){
    cout << x[i] << endl;
  }

  delete [] x;

  return 0;
}

// 長度可變的數組
