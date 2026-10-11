#include<iostream>
#include<vector>
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
int main(){
    Disjointset dj(6);
    dj.unionbyrank(0,2);
  //  cout<<dj.find(2)<<" ";
    dj.unionbyrank(1,3);
    dj.unionbyrank(2,5);
    dj.unionbyrank(0,3);
   // cout<<dj.find(2)<<" ";
    dj.unionbyrank(0,4);
    
    dj.getInfo();
}
