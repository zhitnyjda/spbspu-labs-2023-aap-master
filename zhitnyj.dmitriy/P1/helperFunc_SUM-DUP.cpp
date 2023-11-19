#include <iostream>
#include <stdexcept>
#include "helpersFunc_SUM-DUP.h"

int helperFunc::operator()(std::istream* str)
{
   int n_ = 0;

   do
   {
      try
      {
         if (str->peek() == 10 && helperFunc::n == n_)
         {
            std::cout << "Sequence should end with 0!" << std::endl;

            return 1;
         }
         *str >> n_;

         if (str->fail())
         {
            std::cout << "Not a sequence!" << std::endl;

            return 2;
         }

         helperFunc::operator()(n_);
      }
      catch (std::exception& err)
      {
         err.what();
      }
      l_++;
   } while (n_);

   if (l_ < 4)
   {
      std::cout << "Too short sequence!" << std::endl;

      return 1;
   }

   std::cout << "Count: " << helperFunc::count << std::endl;

   return 0;
}

int helperFunc::operator()(int n_)
{
   if (!(( l_ + 1 ) % 3 ) && ( l_ != 0 ))
   {
      if (( s == n_ ))
         helperFunc::count++;

      helperFunc::s = 0;
   }
   else
   {
      helperFunc::s += n_;
      helperFunc::n = n_;
   }

   return 0;
}
