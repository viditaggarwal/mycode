#include<iostream>
#include<vector>
#include<stdio.h>
#include<string.h>
using namespace std;

void printVec(vector<int> vec){
	for(int i=0;i<vec.size();i++){
		cout<<vec[i]<<",";
	}
	cout<<endl;	
}

int count( int S[], int m, int n )
{
    // If n is 0 then there is 1 solution (do not include any coin)
    if (n == 0)
        return 1;
     
    // If n is less than 0 then no solution exists
    if (n < 0)
        return 0;
 
    // If there are no coins and n is greater than 0, then no solution exist
    if (m <=0 && n >= 1)
        return 0;
 
    // count is sum of solutions (i) including S[m-1] (ii) excluding S[m-1]
    return count( S, m - 1, n ) + count( S, m, n-S[m-1] );
}

int countDP(int S[], int m, int n){
	
	int table[n+1][m],x,y;
    
    // Fill the enteries for 0 value case (n = 0)
    for (int i=0; i<m; i++)
        table[0][i] = 1;
        
    for(int i=1;i<n+1;i++){
    	for(int j=0;j<m;j++){
    		x = (i-S[j]>=0)?table[i-S[j]][j]:0;
    		
    		y = (j>=1)?table[i][j-1]:0;
    		
    		table[i][j] = x+y;
    	}
    }
    return table[n][m-1];
}

void findOpt(int *arr, int sum, vector<int> vec, int n){
	
	if(sum == 0){
		printVec(vec);
		return;	
	}else{
		for(int i=0;i<n;i++){
			if(sum - arr[i] >= 0){
				sum -= arr[i];
				vector<int> temp = vec;
				temp.push_back(arr[i]);
				findOpt(arr, sum, temp, n);	
			}			
			sum += arr[i];
		}
	}
}

int countNew( int S[], int m, int n )
{
    // table[i] will be storing the number of solutions for
    // value i. We need n+1 rows as the table is consturcted
    // in bottom up manner using the base case (n = 0)
    int table[n+1];
 
    // Initialize all table values as 0
    memset(table, 0, sizeof(table));
 
    // Base case (If given value is 0)
    table[0] = 1;
 
    // Pick all coins one by one and update the table[] values
    // after the index greater than or equal to the value of the
    // picked coin
    for(int i=0; i<m; i++)
        for(int j=S[i]; j<=n; j++)
            table[j] += table[j-S[i]];
 
    return table[n];
}

int main(){
	int arr[] = {1,2};
	int n = sizeof(arr)/sizeof(int);
	vector<int> vec;
	int sum = 3;
	//findOpt(arr, sum, vec, n);
	cout<<countNew(arr, n, sum);
	return 0;
}
