#include<bits/stdc++.h>
using namespace std;

struct TriesNode
{
    TriesNode* children[2];
    int count=0;
};

void insert(TriesNode *root, int N) 
{ 
    for (int i = 31; i >= 0; i--) 
    { 
        bool x = (N) & (1 << i);    
        if(!root->children[x]) 
        { 
            root->children[x] = new TriesNode(); 
        } 
        root->children[x]->count+= 1; 
        root= root->children[x]; 
    } 
} 


int cntSmaller(TriesNode * root, int N, int K) 
{ 
    int cntPairs = 0; 
    for (int i = 31; i >= 0 && root; i--) 
    {                                      
        bool x = N & (1 << i); 
        bool y = K & (1 << i); 
        if(y==true) 
        { 
            if(root->children[x])
            {
                cntPairs  += root->children[x]->count; 
            }
            root = root->children[1 - x]; 
        }  
        else
        {  
            root = root->children[x]; 
        } 
    } 
    return cntPairs; 
} 

int pairs(vector<int>arr, int n, int k)
{
    TriesNode *root = new TriesNode(); 
    int cntPairs = 0; 
    for(int i = 0;i < n; i++)
    { 
        cntPairs += cntSmaller(root, arr[i], k); 
        insert(root, arr[i]); 
    } 
    return cntPairs; 
}

int countPairs(vector<int>& nums, int low, int high) {
    int n = nums.size(); 
    return pairs(nums, n, high + 1) - pairs(nums, n, low);
}