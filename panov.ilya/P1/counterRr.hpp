#ifndef counterRr_HPP
#define counterRr_HPP
namespace Panov
{
  struct CounterRr
  {
    public:
      CounterRr();
      void operator()(int number);
      int operator()() const;
    private:
      int count;
      int first;
  };
}
#endif