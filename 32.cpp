#include<iostream>
#include<list>
#include<queue>
#include<vector>
using namespace std;
class Graph{
    int val;
    list<int> * l;
public:
    Graph(int val){
        this->val=val;
        l= new list<int> [val];


    }
    void addelement(int a,int b){
        l[a].push_back(b);
    }
    void printgraph(){
        for(int i=0;i<val;i++){
            cout<<i<<" -> ";
            for(int el : l[i]){
                cout<<el<<" ";
            }
            cout<<"\n";
        }
    }
    void pathhelper(int src,int end,vector<bool> &vis,string &path){
        if(src==end){
            cout<<path<<end<<endl;
            return;
        }
        vis[src]=true;
        path+= to_string(src);
        for(int el: l[src]){
            if(!vis[el]){
                pathhelper(el,end,vis,path);
            }
        }
        path= path.substr(0,path.size()-1);
        vis[src]=false;


    }
    void printallpath(int src,int end){
        string path="";
        vector<bool> vis(val,false); 
        pathhelper(src,end,vis,path);
    }
};
int  main(){
    Graph graph(6);
    graph.addelement(5,2);
    graph.addelement(5,0);
    graph.addelement(2,3);
    graph.addelement(3,1);
    graph.addelement(0,3);
    graph.addelement(4,0);
    graph.addelement(4,1);
    graph.printgraph();
    graph.printallpath(5,1);
}