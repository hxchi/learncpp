#ifndef SALES_DATA_H_
#define SALES_DATA_H_

#include <iostream>
#include <string>

struct Sales_data;

Sales_data add(const Sales_data s1, const Sales_data s2);
std::istream& read(std::istream &is, Sales_data &tmp);
std::ostream& print(std::ostream &os, Sales_data &tmp);
bool CompareIsbn(const Sales_data s1, const Sales_data s2);

struct Sales_data
{
  // 友元函数
  friend Sales_data add(const Sales_data s1, const Sales_data s2);
  friend std::istream& read(std::istream &is, Sales_data &tmp);
  friend std::ostream& print(std::ostream &os, Sales_data &tmp);
  /* friend bool CompareIsbn(const Sales_data s1, const Sales_data s2); */
  
  // 构造函数
  Sales_data() = default;
  Sales_data(std::istream &is);
  Sales_data(const std::string &str, unsigned int num, double price) :
  bookNo(str), units_sold(num), revenue(price * num) { };
  Sales_data(const Sales_data & orig); /* 拷贝初始化 */
  
  std::string isbn() const;
  Sales_data& combine(const Sales_data &data);

private:
  std::string bookNo;
  unsigned int units_sold;
  double revenue;
};

// 成员函数，函数定义
Sales_data::Sales_data(std::istream &is)
{
  read(is, *this);
}

Sales_data::Sales_data(const Sales_data & orig)
{
  bookNo = orig.bookNo;
  units_sold = orig.units_sold;
  revenue = orig.revenue;
}

std::string Sales_data::isbn() const
{
  return bookNo;
}

Sales_data &Sales_data::combine(const Sales_data &data)
{
  units_sold += data.units_sold;
  revenue += data.revenue;
  return *this;
}


// 非成员函数，函数定义
Sales_data add(const Sales_data s1, const Sales_data s2)
{
  Sales_data sum = s1;
  sum.combine(s2);
  return sum;
}


std::istream& read(std::istream &is, Sales_data &tmp)
{
  double price = 0.0;
  is >> tmp.bookNo >> tmp.units_sold >> price;
  tmp.revenue = price * tmp.units_sold;
  return is;
}


std::ostream& print(std::ostream &os, Sales_data &tmp)
{
  os << tmp.isbn() << " ";
  os << tmp.units_sold << " ";
  os << tmp.revenue;
  return os;
}

bool CompareIsbn(const Sales_data s1, const Sales_data s2)
{
  return s1.isbn().size() < s2.isbn().size();
}

#endif
