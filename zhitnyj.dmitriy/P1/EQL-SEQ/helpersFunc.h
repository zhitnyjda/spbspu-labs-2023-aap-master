#ifndef SOURCES_1_HELPERSFUNC_H
#define SOURCES_1_HELPERSFUNC_H
#include <iostream>

struct helperFunc
{
	public:
	helperFunc(std::istream *elm, long long count = 0, long long maxCount = 0) { helperFunc::elm = elm; helperFunc::count = count; helperFunc::maxCount = maxCount; }
	int findCount();

	private:
	std::istream *elm;
	long long count;
	long long maxCount;
};

#endif
