#ifndef MYFUNC_H
#define MYFUNC_H
namespace psarev
{
  class maxLen
  {
  public:
    maxLen();
    void operator()(int value);
    int operator()();

    int seq_len;

  private:
    int max_len;
    int prev_value;
  };
}
#endif
