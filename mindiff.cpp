#include<iostream>
using namespace std;

struct result{
	int min,max;
};

result *check(result *r1, result *r2){
	result *fin = new result;
	if(r1->max > r2->max)fin->max = r1->max;
	else fin->max = r2->max;
	if(r1->min < r2->min)fin->min = r1->min;
	else fin->min = r2->min;
	return fin;
}

result* maxdiff(int *arr, int low, int high){
	if(high > low+1){
		int mid = (low+high)/2;
		result* res1 = maxdiff(arr, low, mid);
		result* res2 = maxdiff(arr, mid+1, high);	
		return check(res1, res2);	
	}else{
		result *r = new result;
		if(arr[low] > arr[high]){
			r->min = arr[high];
			r->max = arr[low];
		}else{
			r->min = arr[low];
			r->max = arr[high];
		}		
		return r;
	}
}

int main(){
	int arr[] = {20,30,90,40,10,60,100,80};
	result* rs = maxdiff(arr, 0, 7);
	cout<<rs->max<<","<<rs->min<<endl;
	return 0;
}
