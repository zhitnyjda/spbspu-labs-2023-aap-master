#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include "functions.hpp"

int khoroshkin::inputLine(char * line)
{
  char c = 0;
  size_t read = 0;
  std::cin >> std::noskipws;
  while (std::cin >> c)
  {
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

char khoroshkin::findOtherMax(std::map<char, int> dict, int previousMaxChar, std::string alreadyTaken)
{
  std::pair<char, int> otherMaxPair;
  int maxValue = std::numeric_limits< int >::min();
  for (const auto & pair : dict)
  {
    if (maxValue < pair.second && pair.second <= previousMaxChar && alreadyTaken.find(pair.first)==std::string::npos)
    {
      maxValue = pair.second;
      otherMaxPair = pair;
    }
  }
  return otherMaxPair.first;
}

std::string khoroshkin::generateNewString(std::map<char, int> dict)
{
  char firstMaxChar = findFirstMax(dict);
  std::string newString (1, firstMaxChar);
  char secondMaxChar = findOtherMax(dict, dict[firstMaxChar], newString);
  newString.push_back(secondMaxChar);
  char thirdMaxChar = findOtherMax(dict, dict[secondMaxChar], newString);
  newString.push_back(thirdMaxChar);
  std::sort(newString.begin(), newString.end());
  return newString;
}

std::string khoroshkin::getFrequency(char * line, int length)
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
