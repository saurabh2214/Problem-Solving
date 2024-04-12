#include<bits/stdc++.h>
using namespace std;

struct TrieNode{
    int count=0;
    TrieNode *children[26]={NULL}; 
};
void insert(TrieNode* root, string word)
{
    for(int i=0;i<word.length();i++)
    {
        int ind=word[i]-'a';
        if(root->children[ind]==NULL){
            root->children[ind]=new TrieNode();
        }
        root=root->children[ind];
        root->count=root->count+1;
    }
}
void countPrefixAtIndex(TrieNode* root,int& cnt,string s)
{
    TrieNode* curr=root;
    for(int i=0;i<s.length();i++)
    {
        int ind=s[i]-'a';
        curr=curr->children[ind];
        cnt+=curr->count;
    }
}
vector<int> sumPrefixScores(vector<string>& words) {
    TrieNode* root=new TrieNode();
    for(int i=0;i<words.size();i++)
    {
        insert(root,words[i]);
    }
    vector<int> ans;
    int cnt;
    for(int i=0;i<words.size();i++)
    {
        cnt=0;
        countPrefixAtIndex(root,cnt,words[i]);
        ans.push_back(cnt);
    }
    return ans;      
}