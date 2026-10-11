#include<iostream>
#include<vector>
#include<list>
#include<queue>

using namespace std;
class Graph{
    public:
    int V;
    list<pair<int,int>>* l;

 
Graph(int V){
    this->V=V;
    l=new list<pair<int,int>> [V];

}
void addElement(int u,int v,int wt){
    l[u].push_back(make_pair(v,wt));
    l[v].push_back(make_pair(u,wt));
}
void printGraph(){
    for(int i=0;i<V;i++){
        cout<<i<<"->";
        for(auto x : l[i]){
            cout<<x.first<<","<<x.second << " ";
        }
        cout<<"\n";
    }
}
void primsalgo(int src,int V){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<bool> mst (V,false);
    pq.push(make_pair(0,src));
    int ans=0;
    while(!pq.empty()){
        int u=pq.top().second;
        int cost =pq.top().first;
        pq.pop();
        if(!mst[u]){
            mst[u]=true;
            ans+=cost;
           
            list<pair<int,int>> neigh= l[u];
            for(pair<int,int> n :neigh){
                int v= n.first;
                int currwt= n.second;
                pq.push(make_pair(currwt,v));
            }

        }
    }
    cout<<"final cost of mst : "<<ans;
}
};

int main() {

    int V = 6;
    Graph g(V);

    g.addElement(0, 1, 4);
    g.addElement(0, 2, 3);
    g.addElement(1, 2, 1);
    g.addElement(1, 3, 2);
    g.addElement(2, 3, 4);
    g.addElement(2, 4, 5);
    g.addElement(3, 4, 2);
    g.addElement(3, 5, 3);
    g.addElement(4, 5, 6);

    g.printGraph();

    g.primsalgo(0, V);

    return 0;
}
/// https://chatgpt.com/share/6a8018a3-a734-83e8-bb82-9b382fae70fe