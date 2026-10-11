#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
void majorityElement(vector<int> nums){
    unordered_map<int,int> g;
    int n = nums.size();
    int l=n/3;
    for(int e : nums){
        if(g.count(e)){
            g[e]++;
        }
        else{
            g[e]=1;
        }
        if(g[e]>=l){
            cout<< e;
            break;
        }
            
    }
}

int main(){
    vector<int> nums= {1,3,2,5,1,2,5,3,1};
    majorityElement(nums);



    return 0;
}