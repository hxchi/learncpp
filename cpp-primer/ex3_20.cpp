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

  cout << "输出相邻整数的和：" << endl;
  for(int i = 0; i < (vi.size() - 1); i++){
    cout << vi[i] + vi[i+1] << " ";
  }
  cout << endl;
  cout << endl;
  
  cout << "输出首尾整数的和：" << endl;
  for(int i = 0; i < (vi.size()/2); i++){
    cout << vi[i] + vi[vi.size()-i-1] << " ";
  }
  cout << endl;
  
  return 0;
}
