#include <iostream>
#include <limits>
#include <algorithm>
#include "functions.hpp"

int khoroshkin::inputLine(char *& line, size_t capacity)
{
  char c = 0;
  size_t read = 0;
  std::cin >> std::noskipws;
  while (std::cin >> c)
  {
    if (read == capacity - 1)
    {
      capacity *= 2;
      char * newLine = new char[capacity];
      for (size_t i = 0; i < read; i++)
      {
        newLine[i] = line[i];
      }
      delete[] line;
      line = newLine;
    }
    line[read++] = c;
    if (read == capacity - 1 || c == '\n')
    {
      line[read] = '\0';
      break;
    }
  }
  return read;
}

char khoroshkin::findFirstMax(std::map<char, int> dict)
{
  std::pair<char, int> firstMaxPair;
  int maxValue = std::numeric_limits< int >::min();
  for (const auto & pair : dict)
  {
    if (maxValue < pair.second)
    {
      maxValue = pair.second;
      firstMaxPair = pair;
    }
  }
  return firstMaxPair.first;
}

char khoroshkin::findOtherMax(std::map<char, int> dict, int previousMaxChar, char first, char second)
{
  std::pair<char, int> otherMaxPair;
  int maxValue = std::numeric_limits< int >::min();
  for (const auto & pair : dict)
  {
    if (maxValue < pair.second && pair.second <= previousMaxChar && pair.first != first && pair.first != second)
    {
      maxValue = pair.second;
      otherMaxPair = pair;
    }
  }
  return otherMaxPair.first;
}

void khoroshkin::generateNewString(std::map<char, int> dict, char * newString)
{
  char firstMaxChar = findFirstMax(dict);
  newString[0] = firstMaxChar;
  char secondMaxChar = findOtherMax(dict, dict[firstMaxChar], newString[0]);
  newString[1] = secondMaxChar;
  char thirdMaxChar = findOtherMax(dict, dict[secondMaxChar], newString[0], newString[1]);
  newString[2] = thirdMaxChar;
  std::sort(newString, newString+3);
}

void khoroshkin::getFrequency(const char * line, int length, char * newString)
{
  std::map<char, int> charFrequency;
  for (int i = 0; i < length; i++)
  {
    if (std::isalpha(line[i]) && line[i] != ' ')
    {
      charFrequency[std::tolower(line[i])]++;
    }
  }
  generateNewString(charFrequency, newString);
}

void khoroshkin::clearString(char * string, size_t stringSize)
{
  for (size_t i = 0; i < stringSize; ++i)
  {
    string[i] = '\0';
  }
}

void khoroshkin::generateNewWithTwo(const char * firstLine, const char * secondLine, size_t size1, size_t size2, char * newString)
{
  for (size_t i = 0; i < size1; i++)
  {
    for (size_t j = 0; j < size2; j++)
    {
      if (firstLine[i] == secondLine[j])
      {
        break;
      }
      if (j == size2 - 1)
      {
        for (size_t k = 0; k < size1; k++)
        {
          if (!newString[k])
          {
            newString[k] = firstLine[i];
            newString[k + 1] = '\0';
            break;
          }
        }
      }
    }
  }
}
