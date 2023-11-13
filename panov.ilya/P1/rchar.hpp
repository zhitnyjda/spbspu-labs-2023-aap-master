#ifndef RCHAR_HPP
#define RCHAR_HPP
namespace panov
{
  struct Rchar
  {
  public:
    Rchar();
    void operator()(int number);
    long long operator()() const;
  private:
    int count;
    int first;
    int max_number;
  };
}
#endif
