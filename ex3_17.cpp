#include <iostream>
#include <string>
#include <vector>

using std::cin; using std::cout; using std::endl;
using std::string; using std::vector;

int main()
{
  vector<string> vs;
  string str;
  while(cin >> str){
    vs.push_back(str);
  }

  for(auto &i : vs){
    for(auto &c : i){
      c = toupper(c);
    }
    cout << i << endl;
  }

  return 0;
  
}
