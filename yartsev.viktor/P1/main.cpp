#include <iostream>

struct Counter {
  int amount = 0; 
  void addNumber(const int num)
  {
    amount += (num % 2 == 0);
  }
  int getAmount()
  {
    return amount;
  }
};

int main ()
{
  int num;
  Counter counter; 
  do {
    std::cin >> num;
    if (!std::cin) {
      std::cerr << "Not a sequence\n";
      return 1;
    } else if (num != 0) {
      counter.addNumber(num);
    }
  } while (num != 0);
  std::cout << counter.getAmount() << "\n";
  return 0;
}
