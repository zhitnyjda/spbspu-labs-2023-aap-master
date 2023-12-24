#include "readLine.hpp"

int main()
{
  char * line = ponomarev::readLine(std::cin);
  std::cout << line << "\n";
  delete[] line;
  return 0;
}
