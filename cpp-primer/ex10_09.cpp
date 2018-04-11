#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::cin; using std::cout; using std::endl;
using std::string; using std::vector; 

bool isShorter(const string &s1, const string &s2);

int main()
{
  vector<string> vs{"the", "quick", "red", "fox", "jumps", "over", "the", "red", "turtle"};

  sort(vs.begin(), vs.end());
  auto end_unique = unique(vs.begin(), vs.end());
  vs.erase(end_unique, vs.end());

  stable_sort(vs.begin(), vs.end(), isShorter);
  // 测试
  for(auto i : vs){
    cout << i << " ";
  }
  cout << endl;
  
  return 0;
}

bool isShorter(const string &s1, const string &s2)
{
  return s1.size() < s2.size();
}
