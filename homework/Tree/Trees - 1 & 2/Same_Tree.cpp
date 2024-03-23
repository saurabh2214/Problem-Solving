#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left,*right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isSameTree(TreeNode* p, TreeNode* q) {
    if(p!=NULL && q==NULL)  
        return false;
    if(p==NULL && q!=NULL)  
        return false;
    if(p==NULL && q==NULL) 
        return true;
    return (p->val==q->val && isSameTree(p->left,q->left) && isSameTree(p->right,q->right));
}

int main()
{
    TreeNode* p = new TreeNode(1);
    p -> left = new TreeNode(2);
    p -> right = new TreeNode(3);

    TreeNode* q = new TreeNode(1);
    q -> left = new TreeNode(2);
    q -> right = new TreeNode(3);

    if(isSameTree(p,q)) 
        cout << "Both trees are same";
    else 
        cout << "Trees are not the same";

    return 0;
}