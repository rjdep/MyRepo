#include<bits/stdc++.h>

void dfs(int node, int par, vector<vector<int>> &g, vector<int> &temp, vector<int> &vis){
    temp.push_back(node);
    vis[node]=1;
    for(auto x: g[node]){
        if(x!=par && !vis[x]){
            dfs(x,node,g,temp,vis);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Write your code here
    vector<vector<int>> g(V);
    for(auto x: edges){
        g[x[0]].push_back(x[1]);
        g[x[1]].push_back(x[0]);
    }
    vector<vector<int>> ans;
    vector<int> vis(V,0);
    for(int i=0; i<V; i++){
        vector<int> temp;
        if(!vis[i]){
            dfs(i,-1,g,temp,vis);
            ans.push_back(temp);
        }
    }
    return ans;
    
}
