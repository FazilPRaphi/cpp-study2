#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Disjointset{
    public:
    int n;
    vector<int> par;
    vector<int> rank;

    Disjointset(int n){
        this->n =n;
        par.resize(n);
        rank.resize(n, 0);
        for(int i=0;i<n;i++){
            par[i]=i;
            rank[i]=0;
        }
    }
    int find(int x){
        if(par[x]==x){
            return x;

        }
        else{
            return par[x]= find(par[x]);
        }
    }
    int unionbyrank(int a,int b){
        int parA=find(a);
        int parB =find(b);

        if(rank[parA]==rank[parB]){
            par[parB]=parA;
            rank[parA]++;

        }else if
            (rank[parA]>rank[par[b]]){
                 par[parB]=parA;
            }
            else{
               par[parA]=parB; 
            }
        

    }
    void getInfo(){
        for(int i=0;i<n;i++){
            cout<<i<<" "<<"rank:-->"<<rank[i]<<"  "<<"parent-->"<<par[i]<<"\n";
        }
    }
};
class Edge{
    public:

    int u;
    int v;
    int wt;

    Edge(int u,int v,int wt){
        this->u=u;
        this->v=v;
        this->wt=wt;
    }
    

};
class Graph{
    public:
    vector<Edge> edges;
    int V;
    vector<int> par;
    vector<int> rank;

    Graph(int V){
        this->V=V;
        for(int i=0;i<V;i++){
            par.push_back(i);
            rank.push_back(0);
        }
    }
    int find(int x){
        if(par[x]==x){
            return x;
        }
        else{
            return par[x]= find(par[x]);
        }
    }
    void unionbyrank(int a,int b){
        int parA= find(a);
        int parB= find(b);
        if(rank[parA]==rank[parB]){
            par[parB]=parA;
            rank[parA]++;
        }
        else if
            (rank[parA]>rank[par[b]]){
                 par[parB]=parA;
            }
            else{
               par[parA]=parB; 
            }


    }
    void addedge(int u,int v,int wt){
        edges.push_back(Edge(u,v,wt));

    }

    void kruskals(){
        sort(edges.begin(),edges.end(),[](Edge &a,Edge &b){return a.wt<b.wt;});
        int minCost=0;
        for(int i=0;i<edges.size();i++){
            Edge e = edges[i];
            int parA=find(e.u);
            int parB=find(e.v);
            if(parA!=parB){
                unionbyrank(parA,parB);
                minCost+=e.wt;

            }
        }
        cout<<"minCost : "<<minCost;
    }

};
int main(){
    Graph graph(4);
    graph.addedge(0,1,10);
    graph.addedge(0,2,15);
    graph.addedge(0,3,30);
    graph.addedge(1,3,40);
    graph.addedge(2,3,50);
    graph.kruskals();

}
