#ifndef SCREEN_H_
#define SCEEN_H_

#include <iostream>
#include <string>

class Screen
{
 public:
  using pos = std::string::size_type;

 public:
  // 构造函数
  Screen() = default; // 1
  Screen(pos p2, pos p3) :
  height(p2), width(p3), contents(p2 * p3, ' ')  { } // 2
  Screen(pos p2, pos p3, const char ch) :
  height(p2), width(p3), contents(p2 * p3, ch)  { } // 3

  Screen& Move(pos p1, pos p2);
  char GetContent() const;
  char GetContent(pos p1, pos p2) const;
  Screen &SetContent(char ch) {
    contents[cursor] = ch;
    return *this;
  }
  
  Screen &SetContent(pos p1, pos p2, char ch) {
    contents[p1 * width + p2] = ch;
    return *this;
  }

  Screen &display(std::ostream &os) {
    do_display(os);
    return *this;
  }

  const Screen &display(std::ostream &os) const {
    do_display(os);
    return *this;
  }
  
 private:
  pos cursor = 0;
  pos height;
  pos width;
  std::string contents;

  void do_display(std::ostream & os) const {
    os << contents;
  }
  
};


// 成员函数
Screen& Screen::Move(pos p1, pos p2)  // p1表示光标移动的行数，p2表示光标移动的位数
{
  cursor = p1 * width + p2;
  return *this;
}

char Screen::GetContent() const
{
  return contents[cursor];
}

char Screen::GetContent(pos p1, pos p2) const
{
  return contents[p1 * width + p2];
}

#endif
