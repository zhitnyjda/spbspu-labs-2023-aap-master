#ifndef MYSTRUCT_HPP
#define MYSTRUCT_HPP
#include <iostream>

namespace mihalchenko
{
  struct DinString
  {
  public:
    DinString(size_t n);
    ~DinString();
    void dinResize();
    void dinAppend(char elem);
    void dinOutput();

    size_t getSize();
    size_t getCounterCurrent();
    char *getDinstr();

  private:
    size_t size = 0;
    char *dinstr = nullptr;
    size_t counterCurrent = 0;
    size_t addArr = 0;
  };

  char *findIdenticalChars(char *str1, char *str2, size_t size1, size_t size2);

  size_t arrUniq(char *mas, size_t size);
}
#endif
