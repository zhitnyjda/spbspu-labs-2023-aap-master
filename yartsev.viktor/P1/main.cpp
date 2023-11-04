#include <iostream>

int main ()
{
  int num;
  int counter = 0;
  do {
    std::cin >> num;
    if (!std::cin) {
      std::cerr << "Not a sequence\n";
      return 1;
    } else if (num != 0) {
      counter++;
    }
  } while (num != 0);
  std::cout << counter << "\n";
  return 0;
}
