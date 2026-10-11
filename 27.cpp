#include<iostream>
#include<vector>
#include<list>
#include<queue>

using namespace std;
class Graph{
    public:
    int V;
    list<int>* l;

 
Graph(int V){
    this->V=V;
    l=new list<int> [V];

}
void addElement(int u,int v){
    l[u].push_back(v);
    l[v].push_back(u);
}
void printGraph(){
    for(int i=0;i<V;i++){
        cout<<i<<"->";
        for(int x : l[i]){
            cout<<x<< " ";
        }
        cout<<"\n";
    }
}
void dfshelper(int u,vector<bool> &visited){
    visited[u]=true;
    cout<<u<<" ";
    for(int el : l[u]){
        if(!visited[el]){
            dfshelper(el,visited);
        }
    }

}
void dfs()

{ 
    vector<bool> visited(10,false);
    for(int i=0;i<V;i++){
        if(!visited[i]){

           dfshelper(i,visited);
           cout<<endl;
        }
       
        
    }
}
};
int main(){
    Graph graph(10);
    graph.addElement(1,6);
    graph.addElement(6,4);
    graph.addElement(4,9);
    graph.addElement(4,3);
    graph.addElement(3,8);
    graph.addElement(3,7);
    graph.addElement(2,5);
    graph.addElement(0,2);
    //graph.printGraph();
    graph.dfs();
    
    return 0;
}