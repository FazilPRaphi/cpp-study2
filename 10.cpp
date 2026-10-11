#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;
bool validanagram(string s1,string s2){
    unordered_map<char,int> m;
    if(s1.length()!=s2.length()){
        return false;
    }
    for(int e : s1){
        if(m.count(e)){
            m[e]++;

        }
        else{
            m[e]=1;
        }

    }
    for(int e : s2){
        if(m.count(e)){
            m[e]--;

        }
        else{
            return false;
        }
        if(m[e]==0){
            m.erase(e);
        }


    }
    if(m.size()==0){

        return true;
    }
    else{
        return false;
    }
}
int main(){
    string s1="race";
    string s2="race";
    return 0;
}