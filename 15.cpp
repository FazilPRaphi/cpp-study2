#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<string>
using namespace std;
int largestsum0(vector<int> &nums){
    unordered_map<int,int> m;//sum,index;
    m[0]=-1; 
    int sum=0;
    int ans=0;
    for(int j=0;j<nums.size();j++){
        sum+=nums[j];
        if(m.count(sum)){
            int curr =j-m[sum];
            ans= max(ans,curr);
        }else{
            m[sum]=j;
        }
    }
    return ans;
}
int main(){
    vector<int> nums ={15,-2,2,-8,1,7,10};
    cout<<largestsum0(nums);
    return 0;
}