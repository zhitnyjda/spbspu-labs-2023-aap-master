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
  else if (num > subMax_)
  {
    subMax_ = num;
  }
  }
  size_t getResult () const
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
  size_t subMax_;
  size_t max_;
  size_t seqCount_;
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
      return 2;
    }
    catch (const std:: exception&e)
    {
      std::cerr<<e.what() << "\n";
    }
   }
};

