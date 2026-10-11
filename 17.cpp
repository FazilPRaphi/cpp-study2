#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int ksum(vector<int> nums,int k){
    unordered_map<int,int> m;
    m[0]=1;
    int ans=0;
    int sum=0;
    for(int j=0;j<nums.size();j++){
        sum+=nums[j];
        if(m.count(sum-k)){
            ans+=m[sum-k];
        }
        if(m.count(sum)){
            m[sum]++;
        }else{
            m[sum]=1;
        }
    }

    return ans;
   
    
}
int main(){
vector<int> nums={ 10,-2,2,-20,10};
int k=-10;
cout<<ksum(nums,k);

    return 0;
}