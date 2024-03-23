#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left,*right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    if(root==NULL)
        return ans;
    queue<TreeNode* > q;
    q.push(root);
    while(q.empty()==false)
    {
        int count=q.size();
        vector<int> arr;
        for(int i=0;i<count;i++)
        {
            TreeNode *curr=q.front();
            q.pop();
            arr.push_back(curr->val);
            if(curr->left!=NULL)
                q.push(curr->left);
            if(curr->right!=NULL)
                q.push(curr->right);
        }
        ans.push_back(arr);
    }
    return ans;
}

int main()
{
    TreeNode *root=new TreeNode(3);
    root->left=new TreeNode(9);
    root->right=new TreeNode(20);
    root->right->left=new TreeNode(15);
    root->right->right=new TreeNode(7);

    vector<vector<int>> ans=levelOrder(root);
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[i].size();j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}