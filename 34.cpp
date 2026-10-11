#include<iostream>
#include<vector>
#include<list>
#include<stack>
#include<queue>
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
    void indegree(vector<int> &indegree){
        for(int i=0;i<V;i++){
            for(int v : l[i]){
                indegree[v]++;
            }
        }

    }
   void topsort(){
    vector<int> indegre (V,0);
    queue<int> q;
    indegree(indegre);
    for(int i=0;i<V;i++){
        if(indegre[i]==0){
            q.push(i);

        }
    }
    while(!q.empty()){
        int u=q.front();
        q.pop();

        cout<<u<<" ";
        for(int el : l[u]){
            indegre[el]--;
            if(indegre[el]==0){
                q.push(el);
            }
        }
        
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
