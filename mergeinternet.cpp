#include <iostream>
using namespace std;

void merge(int*,int*,int,int,int);
void mergesort(int *a, int*b, int low, int high)
{
    int pivot;
    if(low<high)
    {
        pivot=(low+high)/2;
        mergesort(a,b,low,pivot);
        mergesort(a,b,pivot+1,high);
        merge(a,b,low,pivot,high);
    }
}
void merge(int *a, int *b, int low, int mid, int high)
{
    int fir,j,sec,k;
    fir=low;
    j=low;
    sec=mid+1;

    while((fir<=mid)&&(sec<=high))
    {
        if(a[fir]<=a[sec])
        {
            b[j]=a[fir];
            fir++;
        }
        else
        {
            b[j]=a[sec];
            sec++;
        }
        j++;
    }
    if(fir>mid)
    {
        for(k=sec; k<=high; k++)
        {
            b[j]=a[k];
            j++;
        }
    }
    else
    {
        for(k=fir; k<=mid; k++)
        {
            b[j]=a[k];
            j++;
        }
    }
    for(k=low; k<=high; k++) a[k]=b[k];
}

int main()
{
    int a[] = {12,10,43,23,100,45,123,56,98,41,90,24};
    int num;

    num = sizeof(a)/sizeof(int);

    int b[num];

    mergesort(a,b,0,num-1);

    for(int i=0; i<num; i++)
        cout<<a[i]<<" ";
    cout<<endl;
}
