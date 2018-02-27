#include <iostream>
#include <string>
#include <vector>
#include <utility>

using std::cin; using std::cout; using std::endl;
using std::string; using std:: vector; using std::pair;

int main()
{
  vector<pair<string, int>> vp;
  string str;
  int a;
  while(cin >> str >> a){
    pair<string, int> p = {str, a};
    vp.push_back(p);
  }

  // 输出测试
  for(auto tmp : vp){
    cout << tmp.first << " "
	 << tmp.second << endl;
  }
  
  return 0;
}
