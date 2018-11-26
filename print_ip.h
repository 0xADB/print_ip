#pragma once

#include <ostream>
#include <type_traits>
#include <stdint.h>
#include <tuple>

namespace ip
{

  template <typename T, typename Enable = void>
    struct printer
    {};

  template<typename T>
    struct printer<
      T
      , typename std::enable_if_t<std::is_integral_v<T>>
      >
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

  template<typename ContainerT>
    struct printer<
      ContainerT
      , typename std::enable_if_t<std::is_integral_v<typename ContainerT::value_type>>
      >
    {
      void operator()(std::ostream& stream, const ContainerT& addr)
      {
	for (auto it = std::begin(addr)
	    , end = std::end(addr)
	    ; it != end
	    ; ++it
	    )
	{
	  if (it != std::begin(addr)) stream << '.';
	  stream << static_cast<int>(*it);
	}
      }
    };

  template<>
    struct printer<std::string>
    {
      void operator()(std::ostream& stream, const std::string& addr)
      {
	stream << addr.c_str();
      }
    };

  template<typename T, typename... Args>
    struct printer<std::tuple<T, Args...>>
    {
      using TupleT = std::tuple<T,Args...>;

      // to localize static_cast
      void print(std::ostream& stream, const T& byte)
      {
	stream << static_cast<int>(byte);
      }

      void print(std::ostream& stream, char delimiter, const T& byte)
      {
	stream << delimiter;
	print(stream, byte);
      }

      template<typename U, size_t I = 0>
	typename std::enable_if_t<std::is_same_v<U,T>>
	  operator()(std::ostream& stream, const TupleT& addr)
      {
	print(stream, std::get<I>(addr));
      }

      template<typename U, typename... Brgs, size_t I = sizeof...(Brgs)>
	typename std::enable_if_t<std::is_same_v<U,T> && sizeof...(Brgs)>
	  operator()(std::ostream& stream, const TupleT& addr)
      {
	operator()<Brgs...>(stream, addr);
	print(stream, '.', std::get<I>(addr));
      }

      void operator()(std::ostream& stream, const TupleT& addr)
      {
	this->operator()<Args...>(stream, addr);
	print(stream, '.', std::get<sizeof...(Args)>(addr));
      }
    };

}
