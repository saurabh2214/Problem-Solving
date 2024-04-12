#include<bits/stdc++.h>
using namespace std;

struct TrieNode{
    TrieNode* children[26]={NULL};
    bool isEnd=false;
};

void insert(TrieNode* root, string word)
{
    for(int i=0;i<word.length();i++)
    {
        int ind=word[i]-'a';
        if(root->children[ind]==NULL)
            root->children[ind]=new TrieNode();
        root=root->children[ind];
    }
    root->isEnd=true;
}
void search(TrieNode* root , string word,string& ans){
    int n=word.size();
    string t;
    for(int i=0;i<word.length();i++){
        int ind=word[i]-'a';
        if(root->children[ind]==NULL){
            ans+=word;
            return;
        }
        t+=word[i];
        root=root->children[ind];
        if(root->isEnd){
            ans+=t;
            return;
        }
    }
    ans+=word;
}
string replaceWords(vector<string>& dictionary, string sentence) {
    TrieNode* root=new TrieNode();
    for(int i=0;i<dictionary.size();i++)
    {
        insert(root,dictionary[i]);
    }
    string ans="";
    string t;
    for(int i=0;i<sentence.length();i++)
    {
        if(sentence[i]==' ')
        {
            search(root,t,ans);
            ans+=' ';
            t="";
        }
        else
        {
            t+=sentence[i];
        }
    }
    search(root,t,ans);
    return ans;
}