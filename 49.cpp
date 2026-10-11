#include<iostream>
#include<string>
using namespace std;
int longestsubstring(string s1,string s2){
    int n=s1.length();
    int m=s2.length();
    if(s1.length()==0 || s2.length()==0 ){
        return 0;
    }
    if(s1[n-1]==s2[m-1]){
        return 1+ longestsubstring(s1.substr(0,n-1),s2.substr(0,m-1));
    }else{
        return max(longestsubstring(s1.substr(0,n-1),s2),
                   longestsubstring(s1,s2.substr(0,m-1)));
    }

}
int main(){
    string s1="abcdge";
    string s2="abedg";
    cout<<longestsubstring(s1,s2);
}