#include <iostream>

int main()
{
  int value = 0;
  int count = 0;
  int max_seq_count = 0;
  int current_seq_count = 0;
  int actual = -1;
  do
  {
    std::cin >> value;
    count += std::cin ? (value ? 1 : 0) : 0;
    if (value <= actual)
    {
      current_seq_count++;
      if (current_seq_count > max_seq_count)
      {
        max_seq_count = current_seq_count;
      }
    }
    else
    {
      current_seq_count = 0;
    }
    actual = value;
  }
  while (value != 0);

  if (!std::cin)
  {
    std::cerr << "Error: Invalid entry, last uncounted value.\n";
    return 1;
  }
  if (count < 0)
  {
    std::cerr << "Error: Too short sequence.\n";
    return 2;
  }

  std::cout << "Count of elements entered: " << count << "\n";
  std::cout << "Longest decreasing length: " << max_seq_count << "\n";
  return 0;
}
