#include <iostream>
#include <string>
#include <map>
#include <set>

using std::cin; using std::cout; using std::endl;
using std::string; using std::map; using std::set;

int main()
{
  set<string> exclude = {"the", "but", "is", "a", "an"};
  map<string, size_t> word_count;
  string word;
  while(cin >> word){
    if(exclude.find(word) == exclude.end()){
      word_count[word]++;
    }
  }

  // 打印测试结果
  for(const auto &w : word_count){
    cout << w.first << " occurs " << w.second
	 << ((w.second > 1) ? " times" : " time") << endl;
  }

  return 0;
}
