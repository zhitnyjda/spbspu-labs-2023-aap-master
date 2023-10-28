#ifndef main_HPP
#define main_HPP
#include <iostream>

struct SomeFunctor
{
public:
  SomeFunctor() : count(0), min_value(std::numeric_limits< long long > ::max()), max_count(std::numeric_limits< long long > ::max()) {}

  void operator()(long long value)
  {
    if (count <= max_count)
    {
      if ((value <= min_value) and (value != 0))
      {
        count = value == min_value ? count + 1 : 1;
        min_value = value;
      }
    }
    else
    {
      throw std::overflow_error("Too many elements\n");
    }
  }
  long long functor()
  {
    return count;
  }
private:
	long long count;
	long long min_value;
	long long max_count;
};

#endif
