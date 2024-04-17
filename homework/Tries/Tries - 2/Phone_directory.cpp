#include<bits/stdc++.h>
using namespace std;

struct TrieNode{
    struct TrieNode *children[26];
    bool isEnd;
    set<string> contacts;
};

void insert(TrieNode* root,string contact)
{
    TrieNode* curr=root;
    for (int i=0;i<contact.length();i++) {
        int ind=contact[i]-'a';
        if (!curr->children[ind]) {
            curr->children[ind] = new TrieNode();
        }
        curr = curr->children[ind];
        curr->contacts.insert(contact);
        // sort(curr->contacts.begin(), curr->contacts.end());
    }
    curr->isEnd=true;
    // sort(curr->contacts.begin(), curr->contacts.end());
}
vector<vector<string>> displayContacts(int n, string contact[], string s)
{
    TrieNode* root=new TrieNode();
    for(int i=0;i<n;i++)
    {
        insert(root,contact[i]);
    }
    TrieNode* curr=root;
    vector<vector<string>> res;
    string prefix="";
    for(int i=0;i<s.length();i++)
    {
        int ind=s[i]-'a';
        if(!curr->children[ind])
        {
            for(int j = i; j < s.length(); j++)
            {
                res.push_back({"0"});
            }
            return res;
        }
        curr=curr->children[ind];
        vector<string> v(curr->contacts.begin(), curr->contacts.end());
        res.push_back(v);
    }
    return res;
}