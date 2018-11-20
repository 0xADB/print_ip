#include "print_ip.h"

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <tuple>

int main (int, char **)
{
  ip::printer<char> ()(std::cout, -1); std::cout << '\n';
  ip::printer<short>()(std::cout, 0); std::cout << '\n';
  ip::printer<int>  ()(std::cout, 2130706433); std::cout << '\n';
  ip::printer<long> ()(std::cout, 8875824491850138409); std::cout << '\n';

  ip::printer<std::string>()(std::cout, std::string("192.168.101.102")); std::cout << '\n';
  ip::printer<std::list<int>>()(std::cout, std::list<int>({192,168,101,103})); std::cout << '\n';
  ip::printer<std::vector<short>>()(std::cout, std::vector<short>({192,168,101,104})); std::cout << '\n';
  ip::printer<std::tuple<long, long, long>>()(std::cout, std::make_tuple(192l,168l,101l)); std::cout << '\n';

  return 0;
}
