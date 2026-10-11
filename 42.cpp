#include<iostream>
#include<vector>
using namespace std;
int stair(int n,vector<int> &f){
    f[0]=f[1]=1;
    for(int i=2;i<=n;i++){
        f[i]=f[i-1]+f[i-2];
    }
    return f[n];
}
int main(){
    int n=5;
    vector<int> f(n+1,0);
    cout<<stair(n,f);
}
