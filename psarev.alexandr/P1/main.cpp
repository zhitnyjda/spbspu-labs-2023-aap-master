#include <iostream>
int main()
{
	int value;
	if (!(std::cin >> value)) {
		std::cout << "Incorrect input!";
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
		if (!(std::cin >> value)) {
			std::cout << "Incorrect input!";
			return 1;
		}
	}
	std::cout << max_len << std::endl;
	return 0;
}