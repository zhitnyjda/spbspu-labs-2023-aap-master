#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
  int value;
  if (!(cin >> value)) {
    cout << "Incorrect input!\n";
    return 1;
  }

  int prev_value = value;
  int seq_len = 0;
  int max_len = 0;

  while (value != 0) {
    if (value >= prev_value) {
      seq_len++;
      if (seq_len > max_len) {
        max_len = seq_len;
      }
    } else {
      seq_len = 1;
    }
    prev_value = value;
    if (!(cin >> value)) {
      cout << "Incorrect input!\n";
      return 1;
    }
  }
  cout << max_len << endl;
  return 0;
}
