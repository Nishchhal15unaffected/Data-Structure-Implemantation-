#include <iostream>
using namespace std;
void ar(int *arr,int d,int n);
void ar(int *arr,int d,int n){
    int temp[d];
    for(int i=0;i<d;i++){
        temp[i]=arr[i];
    }
    for(int i=0;i<n;i++){
        arr[i]=arr[i+1];
        arr[n-1]=temp[i];
    }
    for(int i=0;i<n;i++){
        cout<<arr[i];
    }
}
int main() {
	//code
		int t;
	int n;
	int d;
	cin>>t;
	while(--t){
	    cin>>n;
	    int arr[n];
	    cin>>d;
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    ar(arr,d,n);
	    }
	return 0;
}
