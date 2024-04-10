#include<bits/stdc++.h>
using namespace std;
struct TriesNode
{
    bool isEnd;
    TriesNode* children[26];
    // vector<string> commonPrefix;
    TriesNode()
    {
        for(int i=0;i<26;i++)
        {
            children[i]=NULL;
        }
        isEnd=false;
    }
};

class Trie {
public:
    TriesNode *root;
    Trie() {
        root=new TriesNode();
    }
    
    void insert(string word) {
        TriesNode *node=root;
        for(int i=0;i<word.size();i++)
        {
            int ind=word[i]-'a';
            if(node->children[ind]==NULL)
            {
                node->children[ind]=new TriesNode();
            }
            node=node->children[ind];
            // node->commonPrefix.push_back(word);
        }
        node->isEnd=true;
    }
    
    bool search(string word) {
        TriesNode* node=root;
        for(int i=0;i<word.size();i++)
        {
            int ind=word[i]-'a';
            if(node->children[ind]==NULL)
                return false;
            node=node->children[ind];
        }
        return node->isEnd;
    }
    
    bool startsWith(string prefix) {
        TriesNode* node = root;
        for (char c : prefix) {
            int ind = c - 'a';
            if (node->children[ind] == NULL)
                return false;
            node = node->children[ind];
        }
        return true;
    }
};
