#include<iostream>
#include<vector>
using namespace std;
int rodcutting(vector<int> price,int rodlength,vector<int> length ){
    int n=length.size();
    vector<vector<int>> dp(n+1,vector<int> (rodlength+1,0));
    for(int i=1;i<n+1;i++){
        for(int j=1;j<rodlength+1;j++){
            int x=price[i-1];
            int y=length[i-1];
            if(y<=j){
                dp[i][j]=max(dp[i][j-length[i-1]]+price[i-1],dp[i-1][j]);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][rodlength];

}
int main(){

    vector<int> price={1,5,8,9,10,17,17,20};
    int rodlength=8;
    vector<int>length={1,2,3,4,5,6,7,8};
    cout<<rodcutting(price,rodlength,length);
    return 0;
}

