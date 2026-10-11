#include<iostream>
#include<vector>
#include<list>
using namespace std;
class Graph{
    int V;
    list<int> * l;
public:

    Graph(int val){
        this->V=val;
        l= new list<int> [V];
    }

    void insert(int u,int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }
    void print(){
        for(int i=0;i<V;i++){
            cout<<i<<" --> ";
            for(int el : l[i]){
                cout<<el<<" ";
            }
            cout<<endl;
        }
    }
    bool haspath(int u,int des,vector<bool> &visited){
        
            if(u ==des){
                return true;
            }
        
        visited[u]=true;
        for(int el : l[u]){
        if(!visited[el]){
           return haspath(el,des,visited);
        }
    }
        return false;
    }
    bool has(int u,int des){
        vector<bool> visited (V,false);
        return haspath(u,des,visited);
    }
};

int main(){
    Graph graph(6);
    graph.insert(0,1);
    graph.insert(1,2);
    graph.insert(2,3);
    graph.insert(3,4);
    graph.insert(4,5);
    cout<<graph.has(4,1);
}