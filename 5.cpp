#include<iostream>
#include<map>
#include<string>
using namespace std;
int main(){
map<string,int> ht;
ht["India"]=150;
ht["China"]=150;
ht["US"]=50;
ht["Nepal"]=10;




for(pair<string,int> m: ht){
    cout<<m.first<<","<<m.second<<endl;
}

if(ht.count("Nepal")){
    cout<<"Nepal exists";
}
return 0;
}