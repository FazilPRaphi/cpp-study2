#include<iostream>
#include<string>
#include<vector>
using namespace std;
int lcm(string s1,string s2,vector<vector<int>> &dp){
    int n=s1.length();
    int m=s2.length();
   
    if(s1.length()==0 || s2.length()==0 ){
        return 0;
    }
    if(dp[n][m]!=-1){
        return dp[n][m];
    }
        if(s1[n-1]==s2[m-1]){
            dp[n][m]= 1+ lcm(s1.substr(0,n-1),s2.substr(0,m-1),dp);
        }else{
           dp[n][m]= max(lcm(s1.substr(0,n-1),s2,dp),
            lcm(s1,s2.substr(0,m-1),dp));
        }
return dp[n][m];
    }

int main(){
    string s1="abcdge";
    string s2="abedg";
    vector<vector<int>> dp(s1.length()+1,vector<int> (s2.length()+1,-1));
    cout<<lcm(s1,s2,dp);
}