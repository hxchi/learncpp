#include <iostream>
#include <string>
#include <map>
#include <set>
#include <cctype>		// string字符串的方法
#include <algorithm>		// remove_if算法

using std::cin; using std::cout; using std::endl;
using std::string; using std::set; using std::remove_if;

using Map = std::map<std::string, std::size_t>;

// 函数
auto strip(string & str) -> string const &
{
  for(auto &ch : str){
    ch = tolower(ch);
  }

  str.erase(remove_if(str.begin(), str.end(), ispunct), str.end());
  return str;
}


// 主函数
int main()
{
  set<string> exclude = {"the", "but", "is", "a", "an"};
  Map word_count;
  string word;
  while(cin >> word){
    word = strip(word);
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


