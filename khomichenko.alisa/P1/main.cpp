#include <iostream>
#include <stdexcept>

struct FindingSubMax
{
public:
  FindingSubMax():
    subMax_(0),
    max_(0),
    seqCount_(0)
  {}

  void finding (int num)
  {
  ++seqCount_;
  if (num > max_)
  {
    subMax_ = max_;
    max_ = num;
  }
  else if (num > subMax_ and num != max_)
  {
    subMax_ = num;
  }
  }
  int getResult () const
  {
    if (seqCount_ <2)
    {
      throw std::logic_error("too short sequence");
    }
    else
    {
    return subMax_;
    }
  }
private:
  int subMax_=0;
  int max_=0;
  int seqCount_=0;
};

int main()
{
  FindingSubMax FindingSubMax;
  int num = 0;
  std::cin>>num;
  while ((std::cin) and (num !=0))
  {
    FindingSubMax.finding(num);
    std::cin >> num;
  };
  if (!std::cin) {
    std::cerr<< "not a sequence\n";
    return 1;
  }
  else
  {
    try
    {
      std::cout<< FindingSubMax.getResult() << "\n";
      return 0;
    }
    catch (const std:: exception&e)
    {
      std::cerr<<e.what() << "\n";
      return 2;
    }
   }
};

