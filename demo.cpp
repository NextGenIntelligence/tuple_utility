#include <iostream>
#include <vector>
#include <string>
#include <type_traits>
#include "tuple_utility.hpp"

int main()
{
  auto t = std::make_tuple(0, 1, 2, 3);

  // negate the elements of a tuple
  auto negative_t = tuple_map(std::negate<int>(), t);

  std::cout << "negative_t: ";
  tuple_print(negative_t);
  std::cout << std::endl;

  // add two tuples together
  auto zero_t = tuple_map(std::plus<int>(), t, negative_t);

  std::cout << "zero_t: ";
  tuple_print(zero_t);
  std::cout << std::endl;

  auto one_t = std::make_tuple(1,1,1);

  auto two_t = std::make_tuple(2,2,2);

  auto three_t = std::make_tuple(3,3,3);

  // add three tuples together
  auto six_t = tuple_map([](int x, int y, int z){return x + y + z;}, one_t, two_t, three_t);

  std::cout << "six_t: ";
  tuple_print(six_t);
  std::cout << std::endl;

  // take the first 2 elements of six_t:
  auto six_t_first_two = tuple_take<2>(six_t);

  std::cout << "six_t_first_two: ";
  tuple_print(six_t_first_two);
  std::cout << std::endl;

  // drop the first 2 elements of t:
  auto t_drop_2 = tuple_drop<2>(t);

  std::cout << "t_drop_2: ";
  tuple_print(t_drop_2);
  std::cout << std::endl;

  // make a std::vector from constructor arguments taken from a tuple
  auto vector_of_13s = make_from_tuple<std::vector<int>>(std::make_tuple(13,13));

  // append to a tuple
  auto empty = std::make_tuple();
  auto t10 = tuple_append(empty, 13);

  std::cout << "t10: ";
  tuple_print(t10);
  std::cout << std::endl;

  // reduce a tuple
  auto t11 = std::make_tuple(0, 1, 2, 3);
  auto reduce_t11 = tuple_reduce(t11, 0, [](int x, int y){return x + y;});
  std::cout << "reduce_t11: " << reduce_t11 << std::endl;
  
  // increment each element of a tuple
  auto t12 = std::make_tuple(0, 1, 2, 3);
  tuple_for_each([](int &x){ ++x; }, t12);
  std::cout << "t12: ";
  tuple_print(t12);
  std::cout << std::endl;

  auto t13 = std::make_tuple(0, 1);
  auto t14 = std::make_tuple(2, 3, 4);

  std::cout << "t13 less than t14: " << tuple_lexicographical_compare(t13, t14) << std::endl;
  std::cout << "empty less than t13: " << tuple_lexicographical_compare(empty, t13) << std::endl;
  std::cout << "empty less empty: " << tuple_lexicographical_compare(empty, empty) << std::endl;
  std::cout << "t14 less than t12: " << tuple_lexicographical_compare(t14, t12) << std::endl;

  // zip two tuples together
  auto t15 = std::make_tuple(0, 1);
  auto t16 = std::make_tuple(2, 3);
  auto t17 = tuple_zip(t15,t16);

  // filter elements of a tuple which are not arithmetic types
  auto t18 = std::make_tuple(13, 3.14159265359, std::string("not arithmetic"));
  auto t19 = tuple_filter<std::is_arithmetic>(t18);
  std::cout << "t19: ";
  tuple_print(t19);
  std::cout << std::endl;

  // prepend to a tuple
  auto t20 = tuple_prepend(empty, 7);

  std::cout << "t20: ";
  tuple_print(t20);
  std::cout << std::endl;

  // repeat a value a constant number of times
  auto t21 = tuple_repeat<3>(13.0);
  std::cout << "t21: ";
  tuple_print(t21);
  std::cout << std::endl;

  // gather elements from a tuple
  auto t22 = std::make_tuple('a', 'b', 'c', 'd', 'e');
  auto t23 = tuple_gather<0,2,4>(t22);

  std::cout << "t23: ";
  tuple_print(t23);
  std::cout << std::endl;

  return 0;
}

