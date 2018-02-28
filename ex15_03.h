#ifndef EX15_03_H_
#define EX15_03_H_

#include <iostream>
#include <string>

using std::istream; using std::ostream;
using std::cin; using std::cout; using std::endl;
using std::string;

// 非成员函数声明
double print_total(ostream & os, const Quote & q, size_t s);

class Quote{
 public:
  Quote() = default;
  Quote(const string &s, double p) :
  bookNo(s), price(p) { }

  string isbn() const {
    return bookNo;
  }

  virtual double net_price(size_t s) const {
    return n*price;
  }

  virtual ~Quote() = default;
  
 private:
  string bookNo;
 protected:			/* 派生类可以访问，但是其他代码不能访问。 */
  double price = 0.0;

};


// 非成员函数定义
double print_total(ostream & os, const Quote & q, size_t s)
{
  double tmp = q.net_price();
  os << "bookno " << q.isbn() << " "
     << "total money is " << s * q.net_price(s) << endl;
  return tmp;
}

#endif
