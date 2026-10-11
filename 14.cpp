#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<string>
using namespace std;

void printIterinary(unordered_map<string,string> m){
    unordered_set<string> to;
    for(pair<string,string> ticket: m){
        to.insert(ticket.second);

    }
    string start="";
    for(pair<string,string> ticket: m){
        if(to.find(ticket.first)== to.end()){
            start=ticket.first;
        }
    }
    cout<<start<<"->";
    while(m.count(start)){
        cout<<m[start]<<"->";

        start= m[start];
    }
    cout<<"destinartion";
}
 int main(){
    unordered_map<string,string> m;
    m["Chennai"]="Bengaluru";
    m["Mumbai"]="Delhi";
    m["Goa"]="Chennai";
    m["Delhi"]="Goa";
    printIterinary(m);

    return 0;
 }