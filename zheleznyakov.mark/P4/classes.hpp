#ifndef CLASSES_HPP
#define CLASSES_HPP
#include <fstream>

namespace zheleznyakov
{
  class Matrix
  {
    public:
      int columns;
      int rows;
      int * values;
      void read(std::ifstream & input);
      int findMaxRow();
  };
};
#endif
