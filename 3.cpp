#include<iostream>
#include<vector>
using namespace std;

class Node {
    public:
    string key;
    int val;
    Node* next;
    Node(string key,int val){
        this->key=key;
        this->val=val;
        next=NULL;

    }
    ~Node(){
        if(next!=NULL){
            delete next;
        }
    }

};
class Hashtable{
    public:
    int totsize;
    int currsize;

    Node** table;

    int hashfunction(string key){
        int idx=0;
        for(int i=0;i<key.size();i++){
            idx= (idx+ key[i]*key[i])%totsize;
        }
        return idx;
    }
    void rehash(){
        Node** oldtable=table;
        int oldsize=totsize;
        totsize=2*totsize;
        currsize=0;
         table= new Node*[totsize];
        for(int i=0;i<totsize;i++){
            table[i]=NULL;  
        }
            for(int i=0;i<oldsize;i++){
                Node * temp =oldtable[i];
                while(temp!=NULL){
                    insert(temp->key,temp->val);
                    temp=temp->next;
                }
                if(oldtable[i]!=NULL){
                    delete oldtable[i];
                }
            }
        delete[] oldtable;
    }
    
    Hashtable(int totsize=5){
        this->totsize=totsize;
        currsize=0;
        table= new Node*[totsize];

        for(int i=0;i<totsize;i++){
            table[i]=NULL;  

        }
    }
    void insert(string key,int val){
        int idx= hashfunction(key);

        Node* newNode = new Node(key,val);
        Node* head =table[idx];
        newNode->next=head;
        table[idx]=newNode;
        currsize++;



        double lambda= currsize/(double)totsize;
        if(lambda>1){
            rehash();
        }
    }
    bool exists(string key){
            int idx= hashfunction(key);
                Node* temp =table[idx];
                    while(temp!=NULL){
                    if(temp->key==key){
                     return true;
                    }
                temp=temp->next;
        }
        return false;
    }
    int search(string key){
        
       int idx= hashfunction(key);
                Node* temp =table[idx];
                    while(temp!=NULL){
                    if(temp->key==key){
                     return temp->val;
                    }
                temp=temp->next;
        }
        return -1;
    }
    void print(){
        for(int i=0;i<totsize;i++){
            cout<<i<<endl;
            Node * temp = table[i];
            while(temp!=NULL){
                cout<<temp->key<<" , "<<temp->val<<" ";
                temp=temp->next;
            }
            cout<<endl;
        }
        
    }

    void remove( string key){
        int idx =hashfunction(key);
        Node*temp =table[idx];
        Node* prev=temp;
        while(temp!=NULL){
            if(temp->key==key){
                if(prev==temp){
                    table[idx]=temp->next;
                    delete temp;
                }
                    prev->next=temp->next;
                    delete temp;
                    break;
            }
            prev=temp;
            temp=temp->next;
        }

    }
};
int main(){
    Hashtable ht(5);
    
    ht.insert("India",150);
    ht.insert("China",150);
    ht.insert("US",50);
    ht.insert("Nepal",10);
    ht.insert("UK",20);
  //  if(ht.exists("India")){
    //    cout<<ht.search("India")<<endl;
    //}
 //   if(ht.exists("Nepal")){
      //  cout<<ht.search("Nepal")<<endl;
    //}
    ht.remove("China");
    ht.print();
    return 0;

}