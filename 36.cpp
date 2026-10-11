#include<iostream>
#include<vector>
using namespace std;
class Edge{
    public:
    int val;
    int wt;
    Edge(int val,int wt){
        this->val=val;
        this->wt=wt;


    }


};
void bellmanford(int src,vector<vector<Edge>> graph,int v){
    vector<int> dis(v,INT32_MAX);
    dis[src]=0;
    for(int i=0;i<v-1;i++){
        for(int u=0;u<v;u++){
            for(Edge e: graph[u]){
                if(dis[u] != INT32_MAX && dis[e.val]> dis[u]+e.wt){
                    dis[e.val]=dis[u]+e.wt;
                }
            }
        }
    }
    for(int el : dis){
        cout<<el<<" ";
    }

}
int main(){
    int v=6;
    vector<vector<Edge>> graph(v);
  graph[0].push_back(Edge(2,4));

    graph[1].push_back(Edge(2,1));
    graph[1].push_back(Edge(3,7));

    graph[2].push_back(Edge(4,3));
    graph[3].push_back(Edge(5,1));

    graph[4].push_back(Edge(3,2));
    graph[4].push_back(Edge(5,5));
    bellmanford(0,graph,v);
}