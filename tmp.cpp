#include <iostream>
#include <vector>
#include <set>

using std::cin; using std::cout; using std::endl;
using std::vector; using std::set; using std::multiset;

int main()
{
  int n = 0;
  cin >> n;
  // int *a = new int[n];
  int a[n];
  for(int i = 0; i < n; i++){
    a[i] = i;
  }

  // 测试
  for(int i = 0; i < n; i++){
    cout << a[i] << " ";
  }
  cout << endl;

  // delete [] a;
  return 0;
}

