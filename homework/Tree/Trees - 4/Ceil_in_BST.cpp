#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left,*right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int findCeil(TreeNode* root, int input) {
    TreeNode* res=NULL;
    while(root!=NULL)
    {
        if(root->val==input)
            return root->val;
        else if(root->val<input)
            root=root->right;
        else{    
            res=root;
            root=root->left;
        }
    }
    if(res==NULL)
        return -1;
    return res->val;
}

int main()
{
    TreeNode* root=new TreeNode(5);
    root->left=new TreeNode(1);
    root->right=new TreeNode(7);
    root->left->right=new TreeNode(2);
    root->left->right->right=new TreeNode(3);

    cout<<findCeil(root,3)<<endl;
    return 0;
}