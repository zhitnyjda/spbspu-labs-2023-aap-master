#include "readLine.hpp"
#include "createLine.hpp"

int main()
{
  try
  {
    char* userLine = new char[10] {};
    const char* presetLine = "abc ef";

    psarev::readLine(userLine);
    size_t presetLen = strlen(presetLine);
    size_t userLen = strlen(userLine);
    if (userLen == 0) {
      std::cerr << "Error: At least ONE value need!\n";
      delete[] userLine;
      return 1;
    }

    char* resLine = new char[10] {};
    size_t resMarker = psarev::createTaskLine(userLine, presetLine, userLen, presetLen, resLine);

    delete[] userLine;

    for (size_t i = 0; i < resMarker; i++) {
      std::cout << resLine[i];
    }
    std::cout << '\n';
    delete[] resLine;
    return 0;
  }
  catch (const std::bad_alloc& e)
  {
    std::cerr << "Error: Can't allocate memory!\n";
    return 1;
  }
}
