#include <bits/stdc++.h> 
int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    // Write your code here.
    vector<int> dist(n+1,1000000000);
    dist[src]=0;
    for(int i=0; i<n-1; i++){
        for(int j=0; j<m; j++){
            int x = edges[j][0], y = edges[j][1], d = edges[j][2];
            if(dist[x] != 1e9 && dist[y]>dist[x]+d){
                dist[y]=dist[x]+d;
            }
        }
    }
    return dist[dest];
}
