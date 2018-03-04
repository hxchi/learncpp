// c
#include <string.h>

// c++
#include <iostream>

using std::cout; using std::endl;

class MyString{
 public:
  MyString() = default;
  MyString(char *pdata = NULL) : m_pData(pdata) { }
  MyString(const MyString &mstr) : m_pData(mstr.m_pData) { }
  ~MyString();

  // 赋值运算符函数
  MyString & operator = (const MyString &mstr);

 private:
  char * m_pData;
};

// 成员函数
MyString & MyString::operator = (const MyString &mstr)
{
  if(this == &mstr){		// 如果需要赋值的对象的值和即将赋入的值相等，那么就不执行任何操作。
    return *this;
  }

  delete [] m_pData;		// 考虑到连续赋值，需要删除new申请的动态内存
  m_pData = NULL;
  m_pData = new char[strlen(mstr.m_pData) + 1];
  strcpy(m_pData, mstr.m_pData);

  return *this;
}


// 测试函数
int main()
{
  MyString m1("hxc");
  cout << m1.m_pData << endl;

  
  return 0;
}
