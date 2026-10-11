#include<iostream>
#include<vector>
using namespace std;
int knap(vector<int> val,vector<int> wt,int w,int n){
    if(n==0 || w==0){
        return 0;
    }
    int itemwt =wt[n-1];
    int itemval=val[n-1];
    if(itemwt<=w){
        int ans1=knap(val,wt,w-wt[n-1],n-1) + itemval;

        int ans2=knap(val,wt,w,n-1);

        return max(ans1,ans2);

    }else{

      return   knap(val,wt,w,n-1);

    }
}
int main(){
    vector<int> val={15,14,10,45,30};
    vector<int> wt={2,5,1,3,4};
    int w=7;
    int n=5;
    cout<<knap(val,wt,w,n); 
}