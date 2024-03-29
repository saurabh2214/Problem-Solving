#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left,*right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void traversal(TreeNode* root,int xlevel,int ylevel,map<int,map<int,vector<int>>>& mp)
{
    if(root==NULL)
        return;
    mp[xlevel][ylevel].push_back(root->val);
    traversal(root->left,xlevel-1,ylevel+1,mp);
    traversal(root->right,xlevel+1,ylevel+1,mp);
}
vector<vector<int>> verticalTraversal(TreeNode* root) {
    vector<vector<int>> ans;
    map<int,map<int,vector<int>>> mp;
    traversal(root,0,0,mp);
    for(auto it:mp)
    {
        vector<int> temp;
        for(auto its:it.second)
        {
            sort(its.second.begin(),its.second.end());
            for(auto i:its.second)
            {
                temp.push_back(i);
            }
        }
        ans.push_back(temp);
    }
    return ans;
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