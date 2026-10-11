#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
void unione(vector<int> &nums1,vector<int> &nums2){
    unordered_set<int> m;
    for(int i=0;i<nums1.size();i++){
        m.insert(nums1[i]);
    }
    for(int i=0;i<nums2.size();i++){
        m.insert(nums2[i]);
    }
    for(int  e : m){
        cout<< e<<" ";
    }
}
int main(){
    vector<int> nums1= {7,3,9};
    vector<int> nums2= {6,3,9,2,9,4};
    unione(nums1,nums2);

}