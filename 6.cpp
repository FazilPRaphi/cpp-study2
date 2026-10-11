#include<unordered_set>
#include<iostream>
using namespace std;
 int main(){
    unordered_set<int> l;
    l.insert(1);
    l.insert(1);
    l.insert(3);
    l.insert(6);
    l.insert(2);
    l.insert(7);

    for(int x:l){
        cout<<x<<" ";
    }


    return 0;
 }