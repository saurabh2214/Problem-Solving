#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left,*right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *lca(TreeNode* root,int a,int b)
    {
        if(root==NULL || root->val==a || root->val==b)
            return root;
        TreeNode* left=lca(root->left,a,b);
        TreeNode* right=lca(root->right,a,b);
        if(left!=NULL && right!=NULL)
            return root;
        if(left!=NULL)
            return left;
        else
            return right;
    }
    
    int distance(TreeNode* root,int val)
    {
        int temp=0,dis=0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                TreeNode* curr=q.front();
                q.pop();
                if(curr->val==val)
                {
                    dis=temp;
                    return dis;
                }
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
            temp++;
        }
    }
    
    int findDist(TreeNode* root, int a, int b) {
        
        TreeNode* meet=lca(root,a,b);
        int disa=distance(meet,a);
        int disb=distance(meet,b);
        return disa+disb;
    }

int main()
{
    TreeNode* root=new TreeNode(11);
    root->left=new TreeNode(22);
    root->right=new TreeNode(33);
    root->left->left=new TreeNode(44);
    root->left->right=new TreeNode(55);
    root->right->left=new TreeNode(66);
    root->right->right=new TreeNode(77);

    int a=77,b=22;
    cout<<findDist(root,a,b)<<endl;
    return 0;
}