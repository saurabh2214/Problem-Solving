#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left,*right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void findpairs(TreeNode* root,TreeNode* &prev,TreeNode* &node1,TreeNode* &node2,bool& pair)
{
    if(root==NULL)
        return;
    findpairs(root->left,prev,node1,node2,pair);
    if (prev != NULL && root->val < prev->val) {
        if (!pair) {
            node1 = prev;
            node2 = root;
            pair = true;
        } 
        else {
            node2 = root;
        }
    }
    prev=root;
    findpairs(root->right,prev,node1,node2,pair);
}

void recoverTree(TreeNode* root) {
    if(root==NULL)
        return;
    TreeNode* node1=NULL,*node2=NULL, *prev=NULL;
    bool pair1=false;
    findpairs(root,prev,node1,node2,pair1);
    if (node1 != NULL && node2 != NULL) {
    int temp = node1->val;
    node1->val = node2->val;
    node2->val = temp;
    }
}

int main()
{
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(3);
    root->left->right=new TreeNode(2);

    recoverTree(root);
    return 0;
}