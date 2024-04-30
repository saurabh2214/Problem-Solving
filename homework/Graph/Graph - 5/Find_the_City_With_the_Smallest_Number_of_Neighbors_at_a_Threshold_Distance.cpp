#include<bits/stdc++.h>
using namespace std;

//using dijestra

// vector<int> dijestra(int n,vector<pair<int,int>> adj[],int src)
// {
//     vector<int> dis(n,1e9);
//     priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
//     dis[src]=0;
//     pq.push({0,src});
//     while(!pq.empty())
//     {
//         int node=pq.top().second;
//         int dist=pq.top().first;
//         pq.pop();
//         for(auto it:adj[node])
//         {
//             int adjNode=it.first;
//             int edgeWeight=it.second;
//             if(dist+edgeWeight<dis[adjNode])
//             {
//                 dis[adjNode]=dist+edgeWeight;
//                 pq.push({dis[adjNode],adjNode});
//             }
//         }
//     }
//     return dis;
// }
// int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
//     vector<vector<int>> ans;
//     vector<pair<int,int>> adj[n];
//     for(int i=0;i<edges.size();i++)
//     {
//         adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
//         adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
//     }
//     for(int i=0;i<n;i++)
//     {
//         ans.push_back(dijestra(n,adj,i));
//     }
//     vector<int> count;
//     for(int i=0;i<ans.size();i++)
//     {
//         int cnt=0;
//         for(int j=0;j<ans[i].size();j++)
//         {
//             if(ans[i][j]<=distanceThreshold)
//                 cnt++;
//         }
//         count.push_back(cnt);
//     }
//     int mini=INT_MAX,res;
//     for(int i=0;i<n;i++)
//     {
//         if(mini>=count[i]){
//             mini=count[i];
//             res=i;
//         }
//     }
//     return res;
// }

//Floyd Warshall

int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
    vector<vector<int>> mat(n,vector<int>(n,1e9));
    for(int i=0;i<n;i++)
    {
        mat[i][i]=0;
    }
    for(int i=0;i<edges.size();i++)
    {
        int src=edges[i][0];
        int dst=edges[i][1];
        int wt=edges[i][2];
        mat[src][dst]=wt;
        mat[dst][src]=wt;
    }
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                mat[i][j]=min(mat[i][j],mat[i][k]+mat[k][j]);
            }
        }
    }
    int city=0,max_City=n;
    for(int i=0;i<n;i++)
    {
        int count=0;
        for(int j=0;j<n;j++)
        {
            if(i!=j && mat[i][j]<=distanceThreshold)
                count++;
        }
        if(count<=max_City)
        {
            city=i;
            max_City=count;
        }
    }
    return city;
}