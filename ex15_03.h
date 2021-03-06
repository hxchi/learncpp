#ifndef EX15_03_H_
#define EX15_03_H_

#include <iostream>
#include <string>

using std::istream; using std::ostream;
using std::cin; using std::cout; using std::endl;
using std::string; using std::size_t;

class Quote;

// 非成员函数声明
double print_total(ostream & os, const Quote & q, size_t s);

class Quote{
  // 友元函数
  friend double print_total(ostream & os, const Quote & q, size_t s);
  
 public:
  Quote() = default;
  Quote(const string &s, double p) :
  bookNo(s), price(p) { }

  string isbn() const {
    return bookNo;
  }

  virtual double net_price(size_t x) const {
    return x*price;
  }

  virtual void debug() const {
    cout << "基类..." << endl;
    cout << "bookNo is " << isbn() << "  "
	 << "price is " << price << endl;
  }
  
  virtual ~Quote() = default;
  
 private:
  string bookNo;
 protected:			/* 派生类可以访问，但是其他代码不能访问。 */
  double price = 0.0;

};

// 派生类定义
class Disc_quote : public Quote{
 public:
  Disc_quote() = default;
  Disc_quote(const string & a, double b, size_t c, double d) :
  Quote(a, b), min_qty(c), discount(d) { }

  virtual double net_price(size_t a) const override = 0; /* virtual override */

 private:
  size_t min_qty = 0;
  double discount = 0.0;
  
};


class Bulk_quote : public Disc_quote{
 public:
  Bulk_quote() = default;
  Bulk_quote(const string &s, double p, size_t x, double y) :
  Disc_quote(s, x, y, z) { }

  double net_price(size_t x) const override;
  void debug() const override;
};

// 成员函数定义
double Bulk_quote::net_price(size_t x) const
{
  /* if(x >= min_qty)		/\* 要学会使用if...else的简化版 *\/ */
  /*   return x*price*discount; */
  /* else */
  /*   return x*price; */

  // 简化版
  return (x >= min_qty) ? x*price*discount : x*price;
}

void Bulk_quote::debug() const
{
  cout << "派生类..." << endl;
  /* cout << "bookNo is " << isbn() << "  " */
  /* 	 << "price is " << price << endl; */
  // 简化版
  Quote::debug();
  cout << "min_qty is " << min_qty << "  "
	 << "discount is " << discount << endl;
}
  
// 非成员函数定义
double print_total(ostream & os, const Quote & q, size_t s)
{
  double tmp = q.net_price(s);
  os << "bookno " << q.isbn() << ".     "
     << "sold: " << s << ".     "
     << "total money is " << tmp << endl;
  return tmp;
}

#endif
