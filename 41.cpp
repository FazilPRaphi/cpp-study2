#include<iostream>
#include<vector>
using namespace std;
int climbstair(int n,vector<int> &f){
    if(n==0 || n==1){
        return f[n]=1;
    }
    return f[n]=climbstair(n-1,f)+climbstair(n-2,f);
}
int main(){
    int n=4;
    vector<int> f(n+1,-1);
    cout<<climbstair(n,f);
}