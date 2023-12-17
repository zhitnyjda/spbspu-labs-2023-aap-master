#ifndef LAVRAN_HPP
#define LAVRAN_HPP // Lavran [ToDo] : Придумать адекватное название
namespace likhachev
{
  int readSequence(char *array);
  int copyCharArray(char *copyFrom, char *copyTo, int size);

  int strDoesHasSame(char *array1, int size1, char *array2, int size2);
  int strRemoveDigits(char *array, int size);

  void outLine(char *array, int size);
};
#endif
