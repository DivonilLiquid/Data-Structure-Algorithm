#include <iostream>
using namespace std;
class trie{
    public:
    trie*next[26];
    bool ended;
    trie(){
        for(int i=0;i<=26;i++) next[i] = NULL;
        ended = false;
    }
};
void insert(string s,trie*root){
    trie*curr = root;
    for(int i=0;i<s.size();i++){
        if(curr->next[s[i]-'a']==NULL)curr->next[s[i]-'a']=new trie();
        curr=curr->next[s[i]-'a'];
    }
    curr->ended=true;
}
bool search(string s,trie*root){
    trie*curr=root;
    for(int i=0;i<s.size();i++){
        if(curr->next[s[i]-'a']!=NULL)
        curr=curr->next[s[i]-'a'];
        else
        return false;
    }
    return curr->ended;
}
int main() {
    trie*root = new trie();
    insert("madhur",root);
    insert("madhav",root);
    insert("manak",root);
    insert("mayank",root);
    insert("shivani",root);
    if(search("shivani",root)){
        cout<<"Yes in trie"<<endl;
    }
    else{
        cout<<"Not in trie"<<endl;
    }
}
