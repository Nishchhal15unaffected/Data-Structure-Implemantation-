#include<iostream>
using namespace std;
// if array is not sorted than search a use
int searchA(int *arr,int n,int item)
{
    int i;
    for( i=0;i<n&& arr[i]!=item;i++);
    if(i<n)
        return i;
    else
        return -1;
}
// if array is sorted search b use
int searchB(int *arr,int n,int item )
{
    int i;
    for(i=0;arr[i]<item;i++);
    if(arr[i]==item)
    {
        return i;
    }
    else{
        return -1;
    }
}
int main()
{   int n;
    cout<<"enter the element of array";
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"enter the element to be search";
    int k;
    cin>>k;
    int index=searchB(arr,n,k);
    if(index==-1)
    {
        cout<<"element not found";
    }
    else{
        cout<<"element found at index : "<<index;
    }
}

