#include "createLine.hpp"

size_t psarev::createTaskLine(char* userLine, const char* presetLine, size_t userLen, size_t presetLen, char*& resLine)
{
  size_t elemNum = 0;
  for (size_t i = 0; i < presetLen; i++) {
    if ((std::strchr(userLine, presetLine[i]) == NULL) && (std::strchr(resLine, presetLine[i]) == NULL)) {
      resLine[elemNum++] = presetLine[i];
    }
  }

  for (size_t j = 0; j < userLen; j++) {
    if ((std::strchr(presetLine, userLine[j]) == NULL) && (std::strchr(resLine, userLine[j]) == NULL)) {
      resLine[elemNum++] = userLine[j];
      if (elemNum % 10 == 0) {
        char* extLineRes = new char[elemNum + 10] {};
        for (size_t k = 0; k < elemNum; k++) {
          extLineRes[k] = resLine[k];
        }
        delete[] resLine;
        resLine = extLineRes;
      }
    }
  }
  return elemNum;
}
