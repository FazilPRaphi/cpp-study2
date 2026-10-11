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
    //l[v].push_back(u);
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
bool iscyclehelper(int src, vector<bool> &vis,vector<bool> &recpath){
    vis[src]=true;
    recpath[src]=true;
    for(int el : l[src]){
        if(!vis[el]){
            if(iscyclehelper(el,vis,recpath)){
                return true;
            }
        }
        else{
           if( recpath[el]){
            return true;
           }
        }

    }
    recpath[src]=false;
    return false;

}
bool iscycle(){
    vector<bool> vis( V,false);
    vector<bool> recpath( V,false);
   for(int i=0;i<V;i++){
       if(iscyclehelper(i,vis,recpath)){
        return true;
       }

   }
   return false;
}
};
int main(){
    Graph graph(5);
    graph.addElement(0,1);
    graph.addElement(1,2);
    graph.addElement(2,0);
    graph.addElement(0,3);
    graph.addElement(4,3);
  
    //graph.printGraph();
   // graph.dfs();
   if(graph.iscycle()){
    cout<<"cycle exist\n";
   }else{
    cout<<"Nope";
   }
    return 0;
};