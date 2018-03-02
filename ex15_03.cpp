#include "ex15_03.h"

int main()
{
  Quote x("hxc", 19.99);
  Bulk_quote y("hxc", 19.99, 10, 0.8);

  Quote *z = &y;

  x.debug();
  y.debug();

  z->debug();
  
  return 0;
}
