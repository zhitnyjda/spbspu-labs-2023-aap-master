#include <iostream>
#include "helpersFunc.h"

int main()
{
	if(!std::cin)
	{
		std::cerr << "Can't identify given data as sequence!" << std::endl;

		return 1;
	}
	
	helperFunc * helperFunc_ = new helperFunc(&std::cin);

	helperFunc_->findCount();

	return 0;
}
