#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;
class Node{
    public:
    unordered_map<char,Node*> m;
    bool end;
    int freq;


    Node(){
        end=false;
        
    }
};
class Trie{
    Node* root;
    public:
    Trie(){
        root=new Node();
        root->freq=-1;
    }
    void insert(string key){
        Node* temp =root;
        for(int i=0;i<key.size();i++){
           if( temp->m.count(key[i])==0){
            temp->m[key[i]]=new Node();//insert
            temp->m[key[i]]->freq=1;
           }
           else{
            temp->m[key[i]]->freq++;
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

    string getPrefix(string key){
        Node* temp=root;
        string prefix="";
        for(int i=0;i<key.size();i++){
            prefix+=key[i];
            if(temp->m[key[i]]->freq==1)
            {
                return prefix;
            }
            temp=temp->m[key[i]];
        }
        return prefix;
    }

};


void prefixproblem(vector<string> words){
    Trie trie;
    for(int i=0;i<words.size();i++){
        trie.insert(words[i]);
    }
    for(int i=0;i<words.size();i++){
       cout<<trie.getPrefix(words[i])<<endl;
    }

}
int main(){
    vector<string> words={"zebra","dog","duck","dove"};
    prefixproblem(words);
}