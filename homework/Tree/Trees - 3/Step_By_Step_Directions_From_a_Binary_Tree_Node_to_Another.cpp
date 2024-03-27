#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left,*right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* LCA(TreeNode* root,int p,int q)
{
    if(root==NULL || root->val==p || root->val==q)
    {
        return root;
    }
    TreeNode* left=LCA(root->left,p,q);
    TreeNode* right=LCA(root->right,p,q);
    if(left!=NULL && right!=NULL)
        return root;
    if(left!=NULL)
        return left;
    else
        return right;
}
bool path(TreeNode* root,int val,string &s)
{
    if(!root)
        return false;
    if(root->val==val)
        return true;
    s.push_back('L');
    if(path(root->left,val,s))  
        return true;
    s.pop_back();
    s.push_back('R');
    if(path(root->right,val,s))
    {
        return true;
    }
    s.pop_back();
    return false;
}
string getDirections(TreeNode* root, int startValue, int destValue) {
    if(root==NULL)
        return "";
    string s;
    TreeNode* meet=LCA(root,startValue,destValue);
    string s1,s2;
    path(meet,startValue,s1);
    path(meet,destValue,s2);
    for(auto &it:s1)
    {
        s+="U";
    }
    return s+s2;
}


int main()
{
    TreeNode *root=new TreeNode(5);
    root->left=new TreeNode(1);
    root->right=new TreeNode(2);
    root->left->left=new TreeNode(3);
    root->right->right=new TreeNode(4);
    root->right->left=new TreeNode(6);

    int p=3,q=6;
    string s=getDirections(root,p,q);
    cout<<s<<endl;
    return 0;
}
