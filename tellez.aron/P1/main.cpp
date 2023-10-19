#include <iostream>
#include <stdexcept>

void processSequence()
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
    throw std::logic_error("Error: Invalid entry, last uncounted value.\n");
  }
  if (count < 0)
  {
    throw std::overflow_error("Error: Too short sequence.\n");
  }
  std::cout << "Count of elements entered: " << count << "\n";
  std::cout << "Longest decreasing length: " << max_seq_count << "\n";
}

int main()
{
  try
  {
    processSequence();
  }
  catch (const std::logic_error & e)
  {
    std::cerr << e.what();
    return 2;
  }
  catch (const std::istream::failure & e)
  {
    std::cerr << "Not a sequence";
    return 1;
  }
  catch (const std::overflow_error & e)
  {
    std::cerr << e.what();
    return 1;
  }
  return 0;
}
