#include<iostream>
using namespace std;
void insertionSort(int a[],int n)
{
    int temp,j;
    int i;
    for( i=1;i<n;i++)
    {
        temp=a[i];
        for( j=i-1;j>=0&&temp<a[j];j--)
        {
            a[j+1]=a[j];
        }
        a[j+1]=temp;
    }
}
int main()
{
    int a[]={12,32,11,23,44,1,3,22};
    insertionSort(a,8);
    for(int i=0;i<8;i++)
    {
        cout<<a[i]<<" ";
    }
}
