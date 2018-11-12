#include "print_ip.h"

#include <iostream>

int main (int, char **)
{
  ip::printer<char> ()(std::cout, -1); std::cout << '\n';
  ip::printer<short>()(std::cout, 0); std::cout << '\n';
  ip::printer<int>  ()(std::cout, 2130706433); std::cout << '\n';
  ip::printer<long> ()(std::cout, 8875824491850138409); std::cout << '\n';

  return 0;
}
