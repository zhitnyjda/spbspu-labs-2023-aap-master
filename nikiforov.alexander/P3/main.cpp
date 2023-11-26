#include <iostream>
#include <cstring>
#include <iomanip>
#include "Func.hpp"

using namespace nikiforov;
int main()
{
	char c = 0;
	size_t size = 0;
	size_t count = 0;
	size_t read = 0;
	Str string;
	char* str1 = new char[size] {};
	char* str2 = new char[size] {};
	std::cin >> std::noskipws;

	while ((std::cin >> c) && (c != '\n'))
	{
		if (c != '\n') {
			string.AddElem(str1, size, read);
			str1[read++] = c;
		}
	}

	size_t len1 = read;
	size = 0;
	read = 0;

	while ((std::cin >> c) && (c != '\n')) {
		string.AddElem(str2, size, read);
		str2[read++] = c;
	}

	size_t len2 = read;
	std::cin >> std::skipws;
	int res = string.result(str1, str2, len1, len2);
	delete[] str1;
	delete[] str2;
	return res;
}
