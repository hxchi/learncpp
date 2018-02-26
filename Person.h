#ifndef PERSON_H_
#define PERSON_H_

#include <iostream>
#include <string>

class Person;

std::istream &read(Person &tmp, std::istream &is);
std::ostream &print(const Person &tmp, std::ostream &os);

class Person
{
  // 友元函数
  friend std::istream &read(Person &tmp, std::istream &is);
  friend std::ostream &print(const Person &tmp, std::ostream &os);
  
 public:
  // 构造函数
  Person() = default;
  Person(std::istream &is);
  Person(const std::string s1, const std::string s2) :
  name(s1), address(s2) { }
  
  std::string GetName() const;
  std::string GetAdd() const;

 private:
  std::string name;
  std::string address;
};

// 成员函数
Person::Person(std::istream &is)
{
  read(*this, is);
}
std::string Person::GetName() const
{
  return name;
}

std::string Person::GetAdd() const
{
  return address;
}

// 非成员函数
std::istream &read(Person &tmp, std::istream &is)
{
  is >> tmp.name >> tmp.address;
  return is;
}

std::ostream &print(const Person &tmp, std::ostream &os)
{
  os << tmp.GetName() << " ";
  os << tmp.GetAdd();
  return os;
}


















#endif
