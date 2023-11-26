#ifndef LAVRAN_HPP
#define LAVRAN_HPP
namespace likhachev
{
  struct CharSequence
  { // Lavran [ToDo] : Придумать адекватное название
  public:
    CharSequence();
    void read();
    void outValues();

  private:
    char *array1;
    char *array2;
    char *input;
    int size;
    void switchInput();
    void moveValues(int isStraight);
  };
};
#endif
