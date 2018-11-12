#pragma once

#include <ostream>
#include <type_traits>
#include <stdint.h>

namespace ip
{

  template <typename T, typename Enable = void>
    struct printer
    {};

  template<typename T>
    struct printer<T, typename std::enable_if<std::is_integral<T>::value>::type>
    {
      void operator()(std::ostream& stream, const T& addr)
      {
	auto first = reinterpret_cast<const uint8_t *>(&addr);
	auto last = reinterpret_cast<const uint8_t *>(&addr) + sizeof(T);
	while (first <= --last)
	{
	  stream << static_cast<int>(*(last));
	  if (first != last) stream << '.';
	}
      }
    };

}
