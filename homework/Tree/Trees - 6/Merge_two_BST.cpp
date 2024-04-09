#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left,*right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void inOrder(TreeNode *root,vector<int> &ans)
{
    if(root == NULL)
    {
        return;
    }
    inOrder(root->left,ans);
    ans.push_back(root->val);
    inOrder(root->right,ans);
}

void mergeLL(vector<int> &ans1,vector<int> &ans2,vector<int> &ans)
{
    
    int i=0;
    int j=0;
    
    while(i<ans1.size() && j<ans2.size())
    {
        if(ans1[i]<ans2[j])
        {
            ans.push_back(ans1[i]);
            i++;
        }
        else{
            ans.push_back(ans2[j]);
            j++;
        }
    }
    
    while(i<ans1.size())
    {
        ans.push_back(ans1[i]);
        i++;
    }
    
    while(j<ans2.size())
    {
        ans.push_back(ans2[j]);
        j++;
    }
}

vector<int> merge(TreeNode *root1, TreeNode *root2)
{
    vector<int> ans;    
    vector<int> ans1;
    vector<int> ans2;
   
    inOrder(root1,ans1);
    inOrder(root2,ans2);
    mergeLL(ans1,ans2,ans);
   
    return ans;
}

int main()
{
    TreeNode* root1 = new TreeNode(5);
    root1->left = new TreeNode(3);
    root1->right = new TreeNode(6);
    root1->left->left = new TreeNode(2);
    root1->left->right = new TreeNode(4);

    TreeNode* root2 = new TreeNode(2);
    root2->left = new TreeNode(1);
    root2->right = new TreeNode(3);
    root2->right->right = new TreeNode(7);
    root2->right->right->left = new TreeNode(6);

    vector<int> ans = merge(root1,root2);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}