#include <iostream>
using namespace std;

int main() 
{
	int value, prev_value, seq_len, max_len;
	
	if (!(cin >> value)) {
		cout << "Incorrect input!";
		return 1;
	}

	prev_value = value;
	seq_len = 0;
	max_len = 0;

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
			cout << "Incorrect input!";
			return 1;
		}
	}

	cout << max_len;
	return 0;
}