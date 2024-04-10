#include<bits/stdc++.h>
using namespace std;

struct TrieNode{
    TrieNode* children[2];
    TrieNode() {
        children[0] = NULL;
        children[1] = NULL;
    }
};

class Solution {
public:
    void insertIntoTries(TrieNode* root,int num)
    {
        TrieNode* curr = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!curr->children[bit])
                curr->children[bit] = new TrieNode();
            curr = curr->children[bit];
        }
    }
    int findMaximumXOR(vector<int>& nums) {
        TrieNode* root=new TrieNode();
        int maxore=0;
        for(auto it:nums)
        {
            insertIntoTries(root,it);
        }
        for(int j=0;j<nums.size();j++)
        {
            int xore=0;
            TrieNode* node=root;
            for(int i=31;i>=0;i--)
            {
                int bit=(nums[j]>>i)&1;
                if(node->children[1-bit]!=NULL){
                   node = node->children[1-bit];
                   xore+=(1<<i);
                } 
                else
                {
                    node=node->children[bit];
                }
            }
            maxore=max(maxore,xore);
        }
        return maxore;
    }
};