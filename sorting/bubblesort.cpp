#include<iostream>
using namespace std;
void bubblesort(int a[],int n)
{
    int paas,i,temp;
    for(paas=0;paas<n-1;paas++){
    for(i=0;i<n-1-paas;i++)
    {
        if(a[i]>a[i+1])
        {
            temp=a[i];
            a[i]=a[i+1];
            a[i+1]=temp;
        }
    }}
}

int main()
{
    int a[]={24,2,34,1,4};
    bubblesort(a,5);
    for(int i=0;i<5;i++)
    {
        cout<<a[i]<<endl;
    }
}
