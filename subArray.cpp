#include<iostream>
#include<vector>
using namespace std;

int subArray_sum(int *arr, int sz){
	int sofar = arr[0];
	int ending_here = arr[0];
	for(int i=1; i<sz;i++){
		ending_here = max(arr[i], ending_here + arr[i]);
		sofar = max(sofar, ending_here);
	}
	return sofar;	
}

int sequence(std::vector<int> const & numbers)
{
        // Initialize variables here
        int max_so_far  = numbers[0], max_ending_here = numbers[0];
 
        // OPTIONAL: These variables can be added in to track the position of the subarray
        // size_t begin = 0;
        // size_t begin_temp = 0;
        // size_t end = 0;
 
        // Find sequence by looping through
        for(size_t i = 1; i < numbers.size(); i++)
        {
                if(max_ending_here < 0)
                {
                        max_ending_here = numbers[i];
                }
                else
                {
                        max_ending_here += numbers[i];
                }
 
                // calculate max_so_far
                if(max_ending_here >= max_so_far )
                {
                        max_so_far  = max_ending_here;
 
                }
        }
        return max_so_far ;
}

int main(){
	int arr[] = {1, 4, -5, 6, -4, 10, -8};	
	vector<int> vec(arr, arr+5);
	cout<<sequence(vec);
	return 0;
}
