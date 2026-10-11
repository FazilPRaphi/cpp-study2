#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
using namespace std;
class Node{
    public:
    
    unordered_map<char,Node*> m;
    bool end;

    Node(){
        end=false;
    }
};

class Trie{
    Node* root;
    public:
    Trie(){
        root=new Node();
    }
    void insert(string key){
        Node* temp =root;
        for(int i=0;i<key.size();i++){
           if( temp->m.count(key[i])==0){
            temp->m[key[i]]=new Node();//insert

           }
           temp=temp->m[key[i]];
        }
        temp->end= true;
    }
    int search(string key){
        Node *temp =root;
        for(int i=0;i<key.size();i++){
            if(!temp->m.count(key[i])){
                return -1;
            }
            temp=temp->m[key[i]];
        }
        if(temp->end==true){
        return 1;
        }   
        else{
            return false;
        }
    }
    int counthelper(Node * root){
        int ans=0;
        for(pair<char,Node*> j :root->m){
            ans+=counthelper(j.second);
        }

        return ans+1;

    }
        int  countNodes(){
          return   counthelper(root);
    }
};
int countSub(string key){
    Trie trie;
    for(int i=0;i<key.size();i++){
        string suffix= key.substr(i);
        trie.insert(suffix);

    }
    return trie.countNodes();
}
int main(){
    string str="ababa";
    cout<<countSub(str);


}