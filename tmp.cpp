#include <iostream>
#include <vector>
#include <set>

using std::cin; using std::cout; using std::endl;
using std::vector; using std::set; using std::multiset;

int main()
{
  int a[6] = {0, 1, 2, 3, 4, 5};
  int (&p)[6] = a;

  // 测试
  for(int i = 0; i < 6; i++){
    cout << p[i] << " ";
  }
  cout << endl;

  return 0;
}

