#include<iostream>
#include<vector>

using namespace std;
int cat (int n,vector<int> &dp){
    if(n==0 ||n==1){
        return 1;
    }
    if(dp[n]!=-1){
        return dp[n];
    };
    int ans=0;
    for(int i=0;i<n;i++){
        ans+=cat(i,dp)*cat(n-i-1,dp);

    }
    return ans;
}
int main(){
    int n;
    cout<<"enter the no";
    cin>>n;
    vector<int> dp(n+1,-1);
    
    cout<<cat(n,dp)<<endl;
    return 0;
 }