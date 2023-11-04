#include <iostream>
#include <limits>
#include <stdexcept>

struct Counter {
  public: 
    void operator()(const int num)
    {
      const int maxSize = std::numeric_limits< int >::max();
      if (num % 2 == 0) {
        if (currentSequence == maxSize) {
          throw std::overflow_error("Sequence is too long");
        } else {
          currentSequence++;
        }
      } else {
        currentSequence = 0;
      }
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
      std::cerr << "Error: Not a sequence\n";
      return 1;
    } else if (num != 0) {
      try {
        counter(num);
      } catch (const std::exception & e) {
        std::cerr << "Error: " << e.what() << "\n";
        std::cout << counter.getMaxSequence() << "\n";
        return 2;
      }
    }
  } while (num != 0);
  std::cout << counter.getMaxSequence() << "\n";
  return 0;
}
