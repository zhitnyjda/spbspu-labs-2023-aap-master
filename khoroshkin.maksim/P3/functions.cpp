#include <iostream>
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
    if (c == '\n')
    {
      line[read - 1] = 0;
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

char khoroshkin::findOtherMax(std::map<char, int> dict, int previousMaxChar, char * alreadyTaken)
{
  std::pair<char, int> otherMaxPair;
  int maxValue = std::numeric_limits< int >::min();
  for (const auto & pair : dict)
  {
    if (maxValue < pair.second && pair.second <= previousMaxChar && std::find(alreadyTaken, alreadyTaken+3, pair.first) == alreadyTaken+3)
    {
      maxValue = pair.second;
      otherMaxPair = pair;
    }
  }
  return otherMaxPair.first;
}

char * khoroshkin::generateNewString(std::map<char, int> dict)
{
  char * newString = new char[3];
  char firstMaxChar = findFirstMax(dict);
  newString[0] = firstMaxChar;
  char secondMaxChar = findOtherMax(dict, dict[firstMaxChar], newString);
  newString[1] = secondMaxChar;
  char thirdMaxChar = findOtherMax(dict, dict[secondMaxChar], newString);
  newString[2] = thirdMaxChar;
  std::sort(newString, newString+3);
  return newString;
}

char * khoroshkin::getFrequency(char * line, int length)
{
  std::map<char, int> charFrequency;
  for (int i = 0; i < length; i++)
  {
    if (std::isalpha(line[i]) && line[i] != ' ')
    {
      charFrequency[std::tolower(line[i])]++;
    }
  }
  return generateNewString(charFrequency);
}
