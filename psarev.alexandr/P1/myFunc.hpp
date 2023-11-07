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

  private:
    int prev_value;
    int seq_len;
    int max_len;
  };
}
#endif
