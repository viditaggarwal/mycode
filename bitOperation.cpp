#include <iostream>
using namespace std; 

int main(){
    int n = 511;
    int n1 = n>>6;
    cout<<n1<<endl;
	int n2 = (n1+1)<<6;
    cout<<n2;
    return 0;
}

