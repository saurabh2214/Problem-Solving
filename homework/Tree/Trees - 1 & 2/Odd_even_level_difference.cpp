#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left,*right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int getLevelDiff(TreeNode *root)
{
    if(root==NULL)
        return 0;
    int oddsum=0,evensum=0;
    int a=1;
    queue<TreeNode* > q;
    q.push(root);
    while(!q.empty())
    {
        int count=q.size();
        for(int i=0;i<count;i++)
        {
            TreeNode* curr=q.front();
            q.pop();
            if(a%2==0)
            {
                evensum+=curr->val;
            }
            else
            {
                oddsum+=curr->val;
            }
            if(curr->left!=NULL)
            {
                q.push(curr->left);
            }
            if(curr->right!=NULL)
            {
                q.push(curr->right);
            }
            
        }
        a++;
    }
    return oddsum-evensum;  
}

int main()
{
    TreeNode  * root = new TreeNode(10);
    root->left=new  TreeNode(20);
    root->right=new TreeNode(30);
    root->left->left=new TreeNode(40);
    root->left->right=new TreeNode(60);

    cout<<getLevelDiff(root);
    return 0;

}
