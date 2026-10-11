#include<iostream>
#include<string>
#include<vector>
using namespace std;
int longestsubstring(string s1,string s2){
    int n=s1.length();
    int m=s2.length();
    int ans=0;
    vector<vector<int>> dp(n+1,vector<int> (m+1,0));

    if(s1.length()==0 || s2.length()==0 ){
        return 0;
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else{
                dp[i][j]=0;
            }
            ans=max(ans,dp[i][j]);
        }
    }
    return ans;

}
int main(){
    string s1="abcdge";
    string s2="abedg";
    cout<<longestsubstring(s1,s2);
}