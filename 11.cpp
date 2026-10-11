#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int distinct(vector<int> nums){
    unordered_map<int,int> m;
    for(int e : nums){
        if(m.count(e)){
            m[e]++;
        }
        else{
            m[e]=1;
        }
    }
    int count=0;
    for(auto p : m){
    if(p.second==1){
        count++;
    }

}
    return count;
}
int main(){
    vector<int> nums={4,3,2,5,6,7,4,2,1};
    cout<<distinct(nums);
    return 0;
}