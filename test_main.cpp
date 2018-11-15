#include "print_ip.h"

#include <iostream>
#include <sstream>
#include <list>
#include <vector>
#include <tuple>

using namespace std::string_literals;

#define BOOST_TEST_MODULE test_main

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(test_suite_main)

  BOOST_AUTO_TEST_CASE(test_pod)
  {
    std::ostringstream ip;

    ip::printer<char> ()(ip, -1);
    BOOST_CHECK(ip.str() == "255"s);
    ip.clear(); ip.str("");

    ip::printer<short>()(ip, 0);
    BOOST_CHECK(ip.str() == "0.0"s);
    ip.clear(); ip.str("");

    ip::printer<int>  ()(ip, 2130706433);
    BOOST_CHECK(ip.str() == "127.0.0.1"s);
    ip.clear(); ip.str("");

    ip::printer<long> ()(ip, 8875824491850138409);
    BOOST_CHECK(ip.str() == "123.45.67.89.101.112.131.41"s);
    ip.clear(); ip.str("");
  }


  BOOST_AUTO_TEST_CASE(test_std_string)
  {
    std::ostringstream ip;

    ip::printer<std::string>()(ip, "192.168.101.102"s);
    BOOST_CHECK(ip.str() == "192.168.101.102"s);
    ip.clear(); ip.str("");
  }

  BOOST_AUTO_TEST_CASE(test_std_list)
  {
    std::ostringstream ip;

    ip::printer<std::list<char>>()(ip, std::list<char>({54,53,52,51}));
    BOOST_CHECK(ip.str() == "54.53.52.51"s);
    ip.clear(); ip.str("");

    ip::printer<std::list<short>>()(ip, std::list<short>({244,243,242,241}));
    BOOST_CHECK(ip.str() == "244.243.242.241"s);
    ip.clear(); ip.str("");

    ip::printer<std::list<int>>()(ip, std::list<int>({32768,32769,32770,32771}));
    BOOST_CHECK(ip.str() == "32768.32769.32770.32771"s);
    ip.clear(); ip.str("");

    ip::printer<std::list<long>>()(ip, std::list<long>({2147483646l,2147483645l,2147483644l,2147483643l}));
    BOOST_CHECK(ip.str() == "2147483646.2147483645.2147483644.2147483643"s);
    ip.clear(); ip.str("");

  }

  BOOST_AUTO_TEST_CASE(test_std_vector)
  {
    std::ostringstream ip;

    ip::printer<std::vector<unsigned char>>()(ip, std::vector<unsigned char>({254,253,252,251}));
    BOOST_CHECK(ip.str() == "254.253.252.251"s);
    ip.clear(); ip.str("");

    ip::printer<std::vector<short>>()(ip, std::vector<short>({244,243,242,241}));
    BOOST_CHECK(ip.str() == "244.243.242.241"s);
    ip.clear(); ip.str("");

    ip::printer<std::vector<int>>()(ip, std::vector<int>({32768,32769,32770,32771}));
    BOOST_CHECK(ip.str() == "32768.32769.32770.32771"s);
    ip.clear(); ip.str("");

    ip::printer<std::vector<long>>()(ip, std::vector<long>({2147483646l,2147483645l,2147483644l,2147483643l}));
    BOOST_CHECK(ip.str() == "2147483646.2147483645.2147483644.2147483643"s);
    ip.clear(); ip.str("");
  }

  BOOST_AUTO_TEST_CASE(test_std_tuple)
  {
    std::ostringstream ip;

    ip::printer<std::tuple<char,char>>()(ip, std::tuple<char,char>(54,53));
    BOOST_CHECK(ip.str() == "54.53"s);
    ip.clear(); ip.str("");

    ip::printer<std::tuple<short,short,short>>()(
	ip
	, std::make_tuple(
	     static_cast<short>(144)
	    ,static_cast<short>(143)
	    ,static_cast<short>(142)
	    )
	);
    BOOST_CHECK(ip.str() == "144.143.142"s);
    ip.clear(); ip.str("");

    ip::printer<std::tuple<int,int,int,int>>()(
	ip
	, std::tuple<int,int,int,int>(32768,32769,32770,32771)
	);
    BOOST_CHECK(ip.str() == "32768.32769.32770.32771"s);
    ip.clear(); ip.str("");

    ip::printer<std::tuple<long,long,long,long>>()(
	ip
	, std::tuple<long,long,long,long>(2147483646l,2147483645l,2147483644l,2147483643l)
	);
    BOOST_CHECK(ip.str() == "2147483646.2147483645.2147483644.2147483643"s);
    ip.clear(); ip.str("");
  }

BOOST_AUTO_TEST_SUITE_END()
