#ifndef SOURCES_1_HELPERSFUNC_H
#define SOURCES_1_HELPERSFUNC_H
#include <iostream>

struct helperFunc
{
	public:
		helperFunc(int count = 0,int mCount = 0,int n = 0)
		{
			helperFunc::count = count;

			helperFunc::mCount = mCount;

			helperFunc::n = n;
		}
		int operator()(std::istream* str);
		int operator()(int n);

	private:
		int count, mCount, n;
};

#endif
