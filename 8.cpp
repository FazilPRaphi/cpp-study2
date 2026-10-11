#include<iostream>
#include<unordered_map>
using namespace std;
int main(){
int arr[]= {2,1,5,7,11,15};
int target=9;
int n=sizeof(arr)/sizeof(int);
unordered_map<int,int> m;
for(int i=0;i<n;i++){
    int comp =target-arr[i];
    if(m.count(comp)){
        cout<<m[comp]<<","<<i;
        break;

    }
    m[arr[i]]=i;
}
return 0;
}
