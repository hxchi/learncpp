// 测试返回数组

#include <iostream>
#include <stdio.h>

// 返回指针
int* _getArraya()
{
  int *a = new int[10];
  for(int i = 0; i < 10; i++){
    a[i] = i;
  }

  return a;
}

// 作为函数参数
void _getArrayb(int *a)
{
  for(int i = 0; i < 11; i++){
    *(a++) = i;
    // a[i] = i;
  }
}

// 主函数
int main()
{
  int *a = _getArraya();

  printf("第一种方法：\n");
  for(int i = 0; i < 10; i++){
    std::cout << a[i] << "\n";
  }

  // int b[10];			// 不能声明为int *b
  int *b = new int[10];
  _getArrayb(b);
  printf("第二种方法：\n");
  for(int i = 0; i < 10; i++){
    std::cout << b[i] << "\n";
  }

  return 0;
}
