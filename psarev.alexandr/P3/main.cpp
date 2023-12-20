#include "readLine.hpp"
#include "createLine.hpp"
#include "expandLine.hpp"

int main()
{
  try
  {
    char* userLine = psarev::readLine();
    const char* presetLine = "abc ef";

    size_t presetLen = strlen(presetLine);
    size_t userLen = strlen(userLine);
    if (userLen == 0) {
      std::cerr << "Error: At least ONE value need!\n";
      delete[] userLine;
      return 1;
    }

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
  catch (const std::logic_error& e)
  {
    std::cerr << e.what();
    return 1;
  }
}
