#include<iostream>
using namespace std;
 
void quick_sort(int arr[20],int,int);
 
int main()
{
 int n,i;
 int arr[10] = {10,5,7,2,9,3,1,6,8,4};
 n=10;
 
 for(i=0 ; i<n ; i++)
 {
  	cout<<arr[i]<<"\t";
 } 
 
 quick_sort(arr,0,n-1);
 
 cout<<"\nThe Sorted Array is:\n\n";
 
 for(i=0 ; i<n ; i++)
 {
  	cout<<arr[i]<<"\t";
 } 
 return 0;
}
 
void quick_sort(int arr[20],int low,int high)
{
 int pivot,j,temp,i;
 if(low<high)
 {
  pivot = (low+high)/2;
  i = low;
  j = high;
 
  while(i<j)
  {
  	cout<<"while i and j are "<<i<<","<<j<<endl;
   while((arr[i]<=arr[pivot])&&(i<high))
   {
    i++;
   }
 
   while(arr[j]>arr[pivot])
   {
    j--;
   }
 
   if(i<j)
   { 
    temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
   }
  }
 
  temp=arr[pivot];
  arr[pivot]=arr[j];
  arr[j]=temp;
  quick_sort(arr,low,j-1);
  quick_sort(arr,j+1,high);
 }
}
