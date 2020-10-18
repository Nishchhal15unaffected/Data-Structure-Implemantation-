#include<iostream>
#include<map>
using namespace std;
int main()
{
    map<string,int> ourmap;
    pair<string,int> p("abc",1);
    ourmap.insert(p);
    //one more way to insert elements
    ourmap["def"]=2;
    //size
    cout<<"size:"<<ourmap.size()<<endl;
    // find and access the key
    cout<<ourmap["abc"]<<endl;
    //find and access the key one more way
    cout<<ourmap.at("def")<<endl;
    ourmap["gfg"]=22;
    // check
    if(ourmap.count("gfg")>0)
    {
        cout<<"present"<<endl;
    }
       cout<<"size:"<<ourmap.size()<<endl;
       ourmap.erase("gfg");
          cout<<"size:"<<ourmap.size()<<endl;
}
