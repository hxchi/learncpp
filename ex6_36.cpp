#include <iostream>

using std::cin; using std::cout; using std::endl;
using arrT = int[10];

arrT * func(int i);

int main()
{
  arrT a = func(10);

  // 测试返回数组指针
  for(int i = 0; i < 10; i++){
    cout << a[i] << " ";
  }
  cout << endl;

  return 0;
}

arrT * func(int i)
{
  int a[10];
  for(int cnt = 0; cnt < 10; cnt++){
    a[cnt] = i + cnt;
  }

  return &a;			// 这是错误的，因为不能返回局部变量的地址
}
