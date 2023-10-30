#include "bool_foo.hpp"
bool bool_foo(int prev, int current, int next)
{
  return current < prev && current > next;
}
