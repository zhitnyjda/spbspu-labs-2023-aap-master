#ifndef MYSTRUCT_HPP
#define MYSTRUCT_HPP
#include <iostream>

namespace mihalchenko
{
  struct DinString
  {
  public:
    DinString(size_t n, char c);
    ~DinString();
    void dinResize();
    void dinAppend(char elem);
    void dinOutput();

    size_t size;
    size_t size2;
    char *dinstr;
    size_t counterCurrent;
    size_t addArr;
  };

  char * findIdenticalChars(char * str1, char * str2, size_t size1, size_t size2);

  size_t arr_uniq(char * mas, size_t size);
}
#endif
