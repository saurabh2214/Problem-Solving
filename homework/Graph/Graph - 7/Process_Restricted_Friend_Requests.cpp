#include<bits/stdc++.h>
using namespace std;

class Disjoint{
    public:
        vector<int>parent,size,rank;
        Disjoint(int n){
            rank.resize(n + 1, 0);
            parent.resize(n+1);
            size.resize(n+1);
            for(int i=0;i<=n;i++){
                parent[i] = i;
                size[i] = 1;
            }
        }
        int findParent(int u){
            if(u==parent[u]){
                return u;
            }
            return parent[u] = findParent(parent[u]);
        }

        void UnionbyRank(int u, int v) {
            int pu = findParent(u);
            int pv = findParent(v);
            if (pu == pv) 
                return;
            if (rank[pu] < rank[pv]) {
                parent[pu] = pv;
            }
            else if (rank[pv] < rank[pu]) {
                parent[pv] = pu;
            }
            else {
                parent[pv] = pu;
                rank[pu]++;
            }
        }

        void UnionbySize(int u, int v){
            int pu = findParent(u);
            int pv = findParent(v);
            if(pu==pv){
                return;
            }
            if(size[pu]<size[pv]){
                size[pv] += size[pu];
                parent[pu] = pv;
            }
            else{
                size[pu] += size[pv];
                parent[pv] = pu;
            }
        }
};

vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
    int size=requests.size();
    Disjoint ds(n);
    vector<bool> ans(size,false);
    for(int i=0;i<size;i++){
        int u=ds.findParent(requests[i][0]);
        int v=ds.findParent(requests[i][1]);
        bool flag=true;
        for(int j=0;j<restrictions.size();j++){
            int new_u=ds.findParent(restrictions[j][0]);
            int new_v=ds.findParent(restrictions[j][1]);
            if((new_u==u && new_v==v) || (new_u==v && new_v==u)){
                flag=false;
                break;
            }
        }
        if(flag){
            ds.UnionbyRank(requests[i][0],requests[i][1]);
            ans[i]=true;
        }
    }
    return ans;
}