//DIF-LAT
#include <iostream>
#include "buffer.hpp"
#include "str.hpp"
#include "transformations.hpp"


int main()
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
  std::cout << countDiffLat(str.getString()) << '\n';
  return 0;
}
