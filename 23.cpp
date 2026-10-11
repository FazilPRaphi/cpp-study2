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
    void longhelp(Node* root,string &ans,string temp){
        for(pair<char,Node * > l: root->m){
        if(l.second->end){
            temp+=l.first;
            if((temp.size()==ans.size() && (temp<ans)) || (temp.size()>ans.size())){
                ans=temp;
            }
            longhelp(l.second,ans,temp);
            temp=temp.substr(0,temp.size()-1);
        }

        }
    }
    string longeststring(){
        string ans="";
        
        longhelp(root,ans,"");
        return ans;
    }

};
string longest(vector<string> words){
    Trie trie;
    for(int i=0;i<words.size();i++){
        trie.insert(words[i]);
    }
    return trie.longeststring();
}
int main(){
    vector<string> dict ={"a","ap","app","appl","apple","apply"};
    cout<<longest(dict);
}