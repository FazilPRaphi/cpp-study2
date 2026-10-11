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
void bfs(int src){
    queue<int> Q;
    vector<bool> visited (V,false);
    Q.push(src);
    visited[src]=true;
    while(!Q.empty()){
        int u=Q.front();
        cout<<u<<" ";
        Q.pop();
        
        for(int el : l[u]){
            if(!visited[el]){
                visited[el]=true;
                Q.push(el);
            }
        }

        cout<<endl;
    }
}
};
int main(){
    Graph graph(6);
    graph.addElement(0,1);
    graph.addElement(1,2);
    graph.addElement(2,3);
    graph.addElement(3,4);
    graph.addElement(4,5);
    graph.printGraph();
    graph.bfs(0);
    return 0;
}