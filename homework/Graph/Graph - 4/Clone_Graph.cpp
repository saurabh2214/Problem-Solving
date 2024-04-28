#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
};

void dfs(Node* node,unordered_map<Node*,Node*>& mp)
{
    Node* copy=new Node(node->val);
    mp[node]=copy;
    for(auto it:node->neighbors)
    {
        if(mp.find(it)==mp.end())
            dfs(it,mp);
        copy->neighbors.push_back(mp[it]);
    }
}
Node* cloneGraph(Node* node) {
    unordered_map<Node*,Node*> mp;
    if(node==NULL)
        return NULL;
    dfs(node,mp);
    return mp[node];
}