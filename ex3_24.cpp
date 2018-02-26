#include <iostream>
#include <string>
#include <vector>

using std::cin; using std::cout; using std::endl;
using std::string; using std::vector;

int main()
{
  vector<int> vi;
  int a = 0;
  while(cin >> a){
    vi.push_back(a);
  }

  // 使用迭代器
  cout << "输出相邻整数的和：" << endl;
  for(auto it = vi.cbegin(); (it+1) != vi.cend(); it++){
    cout << *it + *(it+1) << " ";
  }
  cout << endl;
  cout << endl;

  cout << "输出首尾整数的和：" << endl;
  for(auto lhs = vi.cbegin(), rhs = vi.cend() - 1; lhs <= rhs; lhs++, rhs--){
    cout << *lhs + *rhs << " ";
  }
  cout << endl;
  
  return 0;
}
