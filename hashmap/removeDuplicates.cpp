#include<iostream>
#include<map>
#include<vector>
using namespace std;
vector<int> removeDuplicates(int a[], int size)
{
    vector<int> output;
    map<int,bool> check;
    for(int i=0;i<size;i++)
    {
        if(check.count(a[i])>0)
        {
            continue;
        }
        check[a[i]]=true;
        output.push_back(a[i]);
    }
    return output;
}


int main()
{
    int a[]={1,2,2,3,4,4,3,5};
    vector<int> output= removeDuplicates(a,8);
    cout<<"your remove duplicate ans is:"<<endl;
    for(int i=0;i<output.size();i++)
    {
        cout<<output[i];
    }
}
