#include<bits/stdc++.h>

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.
    vector<vector<int>> g(n+1);
    vector<int> indeg(n+1,0),vis(n+1,0);
    for(auto x: edges){
        g[x.first].push_back(x.second);
        indeg[x.second]++;
    }
    queue<int> q;
    for(int i=1; i<=n; i++){
        if(indeg[i]==0){
            q.push(i);
        }
    }
    vector<int> topo;
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        if(vis[it]) continue;
        vis[it]=1;
        topo.push_back(it);
        for(auto x: g[it]){
            if(!vis[x]){
                indeg[x]--;
                if(indeg[x]==0){
                    q.push(x);
                }
            }
        }        
    }
    if(topo.size()==n){
        return 0;
    }
    return 1;
    
}
