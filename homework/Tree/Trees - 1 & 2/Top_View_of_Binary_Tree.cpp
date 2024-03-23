#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left,*right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> topView(TreeNode *root)
{
    map<int,int> mp;
    queue<pair<TreeNode*,int>> q;
    q.push({root,0});
    while(q.empty()==false){
        auto p=q.front();
        TreeNode *curr=p.first;
        int hd=p.second;
        if(mp.find(hd)==mp.end())
            mp[hd]=(curr->val);
        q.pop();
        if(curr->left!=NULL)
            q.push({curr->left,hd-1});
        if(curr->right!=NULL)
            q.push({curr->right,hd+1});
    }
    vector<int> ans;
    for(auto it:mp)
    {
        ans.push_back(it.second);
    }
    return ans;
}

int main() {
	
	TreeNode *root = new TreeNode(10);  
    root->left = new TreeNode(20);  
    root->right = new TreeNode(30);  
    root->left->left = new TreeNode(40);
    root->left->right = new TreeNode(60);
    root->right->left = new TreeNode(90);
    root->right->right = new TreeNode(100);
    
    vector<int> ans=topView(root);
    for(auto it:ans)
    {
        cout<<it<<" ";
    }
          
    return 0;  
	
}