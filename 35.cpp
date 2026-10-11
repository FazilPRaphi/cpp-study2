#include<iostream>
#include<vector>
#include<utility>
#include<queue>
using namespace std;
class Edge{
    public:
    int val;
    int wt;
    Edge(int v,int w){
        this->val=v;
        this->wt=w;
    }
};

void dij(int src,vector<vector<Edge>> graph,int V){
    priority_queue<pair<int,int>,vector<pair<int,int>> ,greater<pair<int,int>>> pq;
    vector<int> dis(V,INT32_MAX);
    pq.push(make_pair(0,src));
    dis[src]=0;
    while(pq.size()>0){
        int u=pq.top().second;
        pq.pop();
       
            vector<Edge> edges=graph[u];
            for(Edge el: edges){
                if(dis[el.val]>dis[u]+ el.wt){
                    dis[el.val]=dis[u]+ el.wt;
                    pq.push(make_pair(dis[el.val],el.val));
                }

            }
        
    }
    for(int d: dis){
        cout<<d<<" ";

    }



}
int main(){
    int V=6;
    vector<vector<Edge>> graph(V);
    graph[0].push_back(Edge(1,2));
    graph[0].push_back(Edge(2,4));

    graph[1].push_back(Edge(2,1));
    graph[1].push_back(Edge(3,7));

    graph[2].push_back(Edge(4,3));
    graph[3].push_back(Edge(5,1));

    graph[4].push_back(Edge(3,2));
    graph[4].push_back(Edge(5,5));
    dij(1,graph,V);



    }
