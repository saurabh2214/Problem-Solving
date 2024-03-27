#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left,*right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> verticalTraversal(TreeNode* root) {
        
}

int main()
{
    TreeNode* root = new TreeNode(3);
    root->left =new TreeNode(9);
    root->right =new TreeNode(20);
    root->right->left =new TreeNode(15);
    root->right->right =new TreeNode(7);

    vector<vector<int>> ans = verticalTraversal(root);
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