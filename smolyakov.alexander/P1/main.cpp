#include <iostream>

bool testSet(int values[]);
bool anyValue(bool values[]);
void clearArray(int values[]);

bool tryInputArrayElement(int values[])
{
  std::cin >> values[0];
  if (!std::cin)
  {
    std::cerr << "Wrong input format.\n";
    return false;
  }
  return true;
}

int main()
{
  int numbers[3];
  int combinations = 0;
  int elements = 1;

  if (!tryInputArrayElement(numbers))
  {
    return 1;
  }

  while (numbers[0] != 0)
  {
    if (testSet(numbers))
    {
      combinations++;
      clearArray(numbers);
    }

    numbers[2] = numbers[1];
    numbers[1] = numbers[0];

    if (!tryInputArrayElement(numbers))
    {
      return 1;
    }
    elements++;
  }

  if (elements < 3)
  {
    std::cerr << "The sequence is too short (has to be at least 3 numbers long).\n";
    return 2;
  }

  std::cout << combinations << '\n';
  return 0;
}

bool testSet(int values[])
{
  int squares[3];
  for (int i = 0; i < 3; i++)
  {
    squares[i] = values[i] * values[i];
  }

  bool conditions[3];
  conditions[0] = (squares[0] == squares[1] + squares[2]);
  conditions[1] = (squares[1] == squares[0] + squares[2]);
  conditions[2] = (squares[2] == squares[0] + squares[1]);
  return anyValue(conditions);
}

bool anyValue(bool values[])
{
  bool flag = false;
  const int arrayLength = 3;
  for (int i = 0; i < arrayLength; i++)
  {
    flag = (values[i] || flag);
  }
  return flag;
}

void clearArray(int values[])
{
  const int arrayLength = 3;
  for (int i = 0; i < arrayLength; i++)
  {
    values[i] = 0;
  }
  return;
}
