#include<iostream>
#include<vector>
#include<list>
#include<stack>
using namespace std;
class Graph{
    int V;
    list<int> * l;
    public:

    Graph(int val){
        this->V=val;
        l= new list<int> [V];


    }
    void addelement(int a,int b){
        l[a].push_back(b);
    }
    void printgraph(){
        for(int i=0;i<V;i++){
            cout<<i<<"->";
            for(int el: l[i]){
                cout<<el<<" ";
            }
        }
    }
    void helper(int src,vector<bool> &vis,stack<int> &s){
        vis[src]=true;
        for(int el : l[src]){
            if(!vis[el]){
                helper(el,vis,s);
            }

        }
        s.push(src);
    }
    void topsort(){
        vector<bool> vis( V,false);
        stack<int> s;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                helper(i,vis,s);
            }
        }

        while(!s.empty()){
            cout<<s.top()<<" ";
            s.pop();
        }
    }


};
int main(){
    Graph graph(6);
    graph.addelement(5,2);
    graph.addelement(5,0);
    graph.addelement(2,3);
    graph.addelement(3,1);
    graph.addelement(4,1);
    graph.addelement(4,0);
    graph.topsort();
}
