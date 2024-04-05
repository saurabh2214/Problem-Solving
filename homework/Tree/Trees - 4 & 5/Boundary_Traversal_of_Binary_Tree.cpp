#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left,*right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isleaf(TreeNode *root) {
     return !root->left && !root->right;
}

void addleftboundary(TreeNode *root,vector<int>&result){
    TreeNode *curr=root->left;
    while(curr){
      if (!isleaf(curr)) {
        result.push_back(curr->val);
      }
      if(curr->left) 
        curr=curr->left;
      else 
        curr=curr->right;
    }
}

void addrightboundary(TreeNode *root,vector<int>&result){
    TreeNode *curr=root->right;
    vector<int>temp;
    while(curr){
        if(!isleaf(curr)){
            temp.push_back(curr->val);
        }
        if(curr->right) 
            curr=curr->right;
        else curr=curr->left;
    }
    for(int i=temp.size()-1;i>=0;--i){
        result.push_back(temp[i]);
    }
}

void addleafnodes(TreeNode *root,vector<int>&result){
    if(isleaf(root)){
        result.push_back(root->val);
        return;
    }
    if(root->left) addleafnodes(root->left, result);
    if(root->right) addleafnodes(root->right, result);
}

vector<int> traverseBoundary(TreeNode *root)
{  
    vector<int>result;
    if(root==NULL){
        return result;
    }
    if(!isleaf(root)){
        result.push_back(root->val);
    }
    addleftboundary(root,result);
    addleafnodes(root,result);
    addrightboundary(root,result);
    return result;
}

int main()
{
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(20);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(8);
    root->right->left = new TreeNode(18);
    root->right->right = new TreeNode(25);
    root->left->right->left = new TreeNode(7);

    vector<int> arr = traverseBoundary(root);
    for(int i=0;i<arr.size();++i){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}