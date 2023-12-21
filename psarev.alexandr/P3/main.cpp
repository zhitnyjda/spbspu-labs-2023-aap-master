#include "readLine.hpp"
#include "createLine.hpp"
#include "expandLine.hpp"

int main()
{
  size_t maxElemNum = 10;
  size_t extSize = 10;
  char* userLine = psarev::readLine(std::cin, extSize, maxElemNum);
  if (userLine == nullptr) {
    std::cerr << "Error: Not enough values or memory to allocate!\n";
    return 1;
  }
  size_t userLen = strlen(userLine);

  const char* presetLine = "abc ef";
  const size_t presetLen = strlen(presetLine);

  char* resLine = psarev::createTaskLine(userLine, presetLine, userLen, presetLen);
  size_t resLen = strlen(resLine);

  delete[] userLine;

  for (size_t i = 0; i < resLen; i++) {
    std::cout << resLine[i];
  }
  std::cout << '\n';
  delete[] resLine;
  return 0;
}
