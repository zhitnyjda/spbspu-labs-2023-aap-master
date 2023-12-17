#include "string.hpp"
#include "iostream"
#include <cstring>

char *kaseev::readLine()
{
  std::string inputStr;
  std::getline(std::cin, inputStr);
  char *charArray = new char[inputStr.length() + 1];
  strcpy(charArray, inputStr.c_str());

  return charArray;
}

char* kaseev::interleaveStrings(char* str1, char* str2)
{
  if (str1 == nullptr || str2 == nullptr)
  {
    return nullptr;
  }
  size_t len1 = strlen(str1);
  size_t len2 = strlen(str2);
  size_t newLen = len1 + len2 + 1;
  size_t t = 0;
  if (newLen <= 1)
  {
    return nullptr;
  }
  char *newStr = new(std::nothrow) char[newLen];
  if (newStr == nullptr)
  {
    return nullptr;
  }
  for (size_t i = 0; i < std::min(len1, len2); ++i)
  {
    newStr[t++] = str1[i];
    newStr[t++] = str2[i];
  }
  if (len1 < len2)
  {
    strcpy(newStr + t, str2 + len1);
  } else if (len1 > len2)
  {
    strcpy(newStr + t, str1 + len2);
  } else
  {
    newStr[t] = '\0';
  }
  return newStr;
}
