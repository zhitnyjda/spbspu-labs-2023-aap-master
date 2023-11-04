#include <iostream>

struct Counter {
  public: 
    void operator()(const int num)
    {
      num % 2 == 0 ? currentSequence++ : currentSequence = 0;
      maxSequence = std::max(maxSequence, currentSequence);
    }
    int getMaxSequence()
    {
      return maxSequence;
    }
  private:
    int maxSequence = 0;
    int currentSequence = 0;
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
      counter(num);
    }
  } while (num != 0);
  std::cout << counter.getMaxSequence() << "\n";
  return 0;
}
