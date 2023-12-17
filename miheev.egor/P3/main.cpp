//DIF-LAT
#include "str.hpp"
#include "buffer.hpp"
#include <cctype>
#include <iostream>
#include <iomanip>

int main(int argc, char* argv[])
{
  using namespace miheev;
  const size_t BUFF_SIZE = 5;
  Buffer buffer(BUFF_SIZE);
  String str;

  bool isEnd = false;
  while(!isEnd)
  {
    buffer.clean();
    isEnd = buffer.fillFromCin();
    str.fillFromBuff(buffer);
  }
  str.print();

  return 0;
}

