#include "createLine.hpp"
#include "expandLine.hpp"

char* psarev::createTaskLine(char* userLine, const char* presetLine, size_t userLen, size_t presetLen)
{
  size_t elemNum = 0;
  size_t expAm = 10;
  size_t maxElemNum = expAm;
  char* resLine = new char[maxElemNum] {};
  for (size_t i = 0; i < presetLen; i++) {
    if ((std::strchr(userLine, presetLine[i]) == NULL) && (std::strchr(resLine, presetLine[i]) == NULL)) {
      resLine[elemNum++] = presetLine[i];
    }
  }

  for (size_t j = 0; j < userLen; j++) {
    if ((std::strchr(presetLine, userLine[j]) == NULL) && (std::strchr(resLine, userLine[j]) == NULL)) {
      resLine[elemNum++] = userLine[j];
      if (elemNum == maxElemNum) {
        resLine = expandLine(resLine, elemNum, expAm);
        maxElemNum += expAm;
      }
    }
  }
  return resLine;
}
