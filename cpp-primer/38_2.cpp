// 测试死循环

#include <stdio.h>

int main()
{
  unsigned int a = 2013;	
  int b = -2;
  short c = 0;
  
  while((b+a) >= 0){
    a = a + b;
    c++;
    printf("%d\n", c);
  }

  return 0;
}

// unsigned的数无法与零比较大小
