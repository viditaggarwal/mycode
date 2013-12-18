#include <iostream>
#include <ext/hash_map>
#define _DEFINE_DEPRECATED_HASH_CLASSES 0
//typedef pair <int, int> Int_Pair;
 
using namespace std;
using namespace __gnu_cxx;
 
int main()
{
  hash_map <int, int> hm1;
  hm1[1] = 100;
  cout<<hm1[1]<<endl;
  
  // The following 2 lines would err because the iterator is const
  // hm1_cIter = hm1.begin ( );
  // hm1.erase ( hm1_cIter );
 
  
  return 0;
}
