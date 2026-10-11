#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
void inter(vector<int> &nums1,vector<int> &nums2){
    unordered_set<int> m;
    for(int i=0;i<nums1.size();i++){
        m.insert(nums1[i]);
    }
   for(int el: nums2){
    if(m.find(el)!= m.end()){
        cout<<el<<" ";
        m.erase(el);
    }

   }
}
int main(){
    vector<int> nums1= {7,3,9};
    vector<int> nums2= {6,3,9,2,9,4};
    inter(nums1,nums2);

    
    return 0;
}