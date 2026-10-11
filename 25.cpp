#include<iostream>
#include<vector>
#include<utility>
#include<list>
using namespace std;
class Graph{
    int val;
    list<pair<int,int> >* l;

    public:

    Graph(int val){
        this->val=val;
        l = new list<pair<int,int>> [val];
    }

    void addelement(int u,int v,int m){
        l[u].push_back(make_pair(v,m));
        l[v].push_back(make_pair(u,m));
    }
    void printgraph(){
        for(int i=0;i<val;i++){
            cout<<i<<"->";
            for(auto el : l[i]){
                cout<<"("<<el.first<<","<<el.second<<")";

            }
            cout<<endl;
        }
    }
};
int main(){
    Graph graph(5);
    graph.addelement(0,1,5);
    graph.addelement(1,2,1);
    graph.addelement(1,3,3);
    graph.addelement(3,2,1);
    graph.addelement(2,4,2);
    graph.printgraph();
    return 0;
}