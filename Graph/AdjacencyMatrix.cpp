#include<iostream>
using namespace std;
int main(){
int Matrix[100][100];
int n,max_edge;
int oragin,destiny,Graph_type;
cout<<"Enter the Number of vertices"<<endl;
cin>>n;
cout<<"Enter the type 1 if undirected graph and if directed graph type 0"<<endl;
cin>>Graph_type;
if(Graph_type){
max_edge=n*(n-1)/2;
}else{
max_edge=n*(n-1);
}
for(int i=0;i<max_edge;i++){
    cout<<"Enter the oragin and destiny if you want to end than enter -1 -1"<<endl;
    cin>>oragin>>destiny;
    if(oragin==-1&&destiny==-1){
        break;
    }
    if(oragin>=n || destiny>=n || oragin<0 || destiny<0){
        cout<<"please type currect vertices";
    }else{
        if(Graph_type){
         Matrix[oragin][destiny];
          Matrix[destiny][oragin];
        }else{
             Matrix[oragin][destiny];
        }
    }
}
for(int i=0;i<max_edge;i++){
    for(int j=0;j<max_edge;j++){
        cout<< Matrix[oragin][destiny];
    }
}
}

