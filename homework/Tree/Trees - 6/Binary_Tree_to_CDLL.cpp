#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left,*right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* prev=NULL;
TreeNode * bToDLL(TreeNode *root)
{
    if(root==NULL) return root;
    TreeNode *head=bToDLL(root->left);
    if(::prev==NULL)
    head=root;
    else{
        root->left=::prev;
        ::prev->right=root;
    }
    ::prev=root;
    bToDLL(root->right);
    return head;
    
}
TreeNode *bTreeToCList(TreeNode *root)
{
  root=bToDLL(root);
  TreeNode *curr=root;
  while(curr->right!=NULL){
      curr=curr->right;
  }
  curr->right=root;
  root->left=curr;
  return root;
}

int main()
{
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(3);
    root->right=new TreeNode(2);

    TreeNode* ans=bTreeToCList(root);
    cout<<ans->left->val;

    return 0;
}