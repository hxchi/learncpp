#include "ex15_03.h"

int main()
{
  Quote x("hxc", 19.99);
  Bulk_quote y("hxc", 19.99, 10, 0.8);

  print_total(cout, x, 10);
  // cout << "总价： " << z1 << endl;

  print_total(cout, y, 10);
  // cout << "总价： " << z2 << endl;

  return 0;
}
