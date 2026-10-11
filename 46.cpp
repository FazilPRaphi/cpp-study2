#include<iostream>
#include<vector>
using namespace std;
void hello(vector<int> &nums,int n,int targetsum){
   for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
        if(nums[i]>nums[j]){
            swap(nums[j],nums[i]);
        }
    }
   }
   vector<int> ans;
   for(int i=0;i<n;i++){
    
    if(nums[i]<=targetsum){
        ans.push_back(nums[i]);
        targetsum-nums[i];
 
    }
    
}



} 
 int main(){

    vector<int> nums ={4,2,7,1,3};
    int targetsum=7;
    int n=nums.size();
    hello(nums,n,targetsum);
 }