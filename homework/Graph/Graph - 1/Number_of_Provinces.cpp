#include<bits/stdc++.h>
using namespace std;

void BFS(vector<vector<int>>& isConnected,int i,vector<bool>& visited)
{
    queue<int> q;
    visited[i]=true;
    q.push(i);
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        for (int j = 0; j < isConnected.size(); j++) {
            if (isConnected[node][j] == 1 && !visited[j]) {
                visited[j] = true;
                q.push(j);
            }
        }
    }
}

int findCircleNum(vector<vector<int>>& isConnected) {
   int count=0;
   vector<bool> visited(isConnected.size(),false);
   for(int i=0;i<isConnected.size();i++)
   {
        if(visited[i]==false)
        {
            BFS(isConnected,i,visited);
            count++;
        }
   }
   return count;
}