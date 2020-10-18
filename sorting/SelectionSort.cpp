//selection sort 7//5//2020
#include<iostream>
using namespace std;
int min(int arr[],int n,int k)
{
   int MIN=arr[k];
    int loc=k;
    for(int j=k+1;j<=n-1;j++)
    {
        if(MIN>arr[j])
        {
            MIN=arr[j];
            loc=j;
        }
    }
    return loc;
}

int main()
{
    int arr[]={50,12,34,5,2,30,12,22,10,33};
int k;
int n=10,temp;
for(k=0;k<=n-2;k++)
{
    int p=min(arr,n,k);
    temp=arr[k];
    arr[k]=arr[p];
    arr[p]=temp;
}
for(k=0;k<n;k++)
{
    cout<<arr[k]<<" ";
}
}
