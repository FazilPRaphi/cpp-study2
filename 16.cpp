#include<iostream>
#include<vector>
using namespace std;
int ksum(vector<int> nums,int k){
    int x=0;
    for(int i=0;i<nums.size();i++){
    for(int j=i+1;j<nums.size();j++){
        if(k== nums[i]+nums[j] ){
            x++;

        }


    }

    }
for(int j=0;j<nums.size();j++){
    if(k==nums[j]){
        x++;
    }
}
return x;
}
int main(){
vector<int> nums={ 10,-2,2,-20,10};
int k=-10;
ksum(nums,k);

    return 0;
}