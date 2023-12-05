#ifndef MYSTRUCT_HPP
#define MYSTRUCT_HPP
#include <iostream>
 
struct DinString
{
public:
  DinString(size_t n, char c);
  ~DinString();
  void dinResize();
  void dinAppend(char elem);
  void dinOutput();
//private:
  size_t size;
  size_t size2;
  char *dinstr;
  size_t counterCurrent;
  size_t addArr;
 };
#endif
