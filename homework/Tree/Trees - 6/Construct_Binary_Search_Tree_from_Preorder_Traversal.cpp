#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left,*right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* bstFromPreorder(vector<int>& preorder) {
    if(preorder.size()==0)
        return NULL;
    if(preorder.size()==1)
        return new TreeNode(preorder[0]);
    int i=0;
    vector<int> left,right;
    TreeNode* root=new TreeNode(preorder[0]);
    for(int i=1;i<preorder.size();i++)
    {
        if(preorder[i]>root->val)
            right.push_back(preorder[i]);
        else if(preorder[i]<root->val)
            left.push_back(preorder[i]);
    }
    root->left=bstFromPreorder(left);
    root->right=bstFromPreorder(right);
    return root;
}

int main()
{
    vector<int> preorder={8,5,1,7,10,12};
    TreeNode* root=bstFromPreorder(preorder);
    cout<<"Root Value: "<<root->val<<endl;
    return 0;
}