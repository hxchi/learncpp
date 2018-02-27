#include <iostream>
#include <vector>
#include <set>

using std::cin; using std::cout; using std::endl;
using std::vector; using std::set; using std::multiset;

int main()
{
  vector<int> vi;
  for(int i = 0; i < 10; i++){
    vi.push_back(i);
    vi.push_back(i);
  }

  // 初始化set，multiset
  set<int> si(vi.cbegin(), vi.cend());
  multiset<int> msi(vi.cbegin(), vi.cend());

  // 输出set，multiset
  for(auto tmp : si){
    cout << tmp << " ";
  }
  cout << endl;

  for(auto tmp : msi){
    cout << tmp << " ";
  }
  cout << endl;

  return 0;
}

