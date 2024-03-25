#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left,*right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* decode(string data, int& i){
    if(i>=data.length()) 
        return NULL;
    string temp = "";
    while(i<data.size() && data[i]!=','){
        temp+=data[i];
        i++;
    }
    i++;
    if(temp=="NULL") 
        return NULL;
    int val = stoi(temp);
    TreeNode* root = new TreeNode(val);
    root->left = decode(data,i);
    root->right = decode(data,i);
    return root;
}

string serialize(TreeNode* root) {
    if(root==NULL)
        return "NULL,";
    return to_string(root->val)+","+serialize(root->left)+serialize(root->right);
}
TreeNode* deserialize(string data) {
    int l=0;
    return decode(data,l);
}

int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    cout<<serialize(root)<<endl;
    cout<<deserialize(serialize(root))<<endl;
    return 0;
}