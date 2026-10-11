#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
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
    bool prefixsearch(string key){
        Node *temp =root;
        for(int i=0;i<key.size();i++){
            if(!temp->m.count(key[i])){
                return false;
            }
            temp=temp->m[key[i]];
        }
        return true;

    }

};

int main(){
   vector<string> words = {"apple","app","woman","mango","man"};
   Trie trie;
   for(int i=0;i<words.size();i++){

       trie.insert(words[i]);
   }
   cout<<trie.prefixsearch("wom");
    return 0;
}