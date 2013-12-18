// constructing priority queues
#include <iostream>       // std::cout
#include <queue>          // std::priority_queue
#include <vector>         // std::vector
#include <functional>     // std::greater
using namespace std;
class mycomparison
{
  bool reverse;
public:
  mycomparison(const bool& revparam=false)
    {reverse=revparam;}
  bool operator() (const int& lhs, const int&rhs) const
  {
    if (reverse) return (lhs>rhs);
    else return (lhs<rhs);
  }
};

int main ()
{
  int myints[]= {40,60,50,20};

  std::priority_queue<int> first;
  std::priority_queue<int> second (myints,myints+4);
  std::priority_queue<int, std::vector<int>, std::greater<int> > third (myints,myints+4);
  cout<<third.top()<<endl;
  
  // using mycomparison:
  typedef std::priority_queue<int,std::vector<int>,mycomparison> mypq_type;

  mypq_type fourth; 
  fourth.push(20);
  fourth.push(40);
  fourth.push(5);
  fourth.push(30);                      // less-than comparison
  cout<<fourth.top()<<endl;
  mypq_type fifth (mycomparison(true));   // greater-than comparison
  fifth.push(20);
  fifth.push(10);
  fifth.push(5);
  fifth.push(30);
  cout<<fifth.top()<<endl;
  return 0;
}
