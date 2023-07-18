vector<int> g[200200];
int up[200200][20];
int lvl[200200];
 
void binary_lift(int node, int par){
    up[node][0] = par;
    for(int i=1; i<20; i++){
        if(up[node][i-1]!=-1){
            up[node][i]=up[up[node][i-1]][i-1];
        }else{
            up[node][i]=-1;
        }
    }
    for(auto x: g[node]){
        if(x!=par){
            binary_lift(x,node);
        }
    }
}
 
void dfs(int node, int par, int dep){
    lvl[node]=dep;
    for(auto x: g[node]){
        if(x!=par){
            dfs(x,node,dep+1);
        }
    }
}
 
int jump_node(int node, int jump){
    for(int i=19; i>=0; i--){
        if(jump==0 || node==-1) break;
        if(jump>=(1LL<<i)){
            node = up[node][i];
            jump-=(1LL<<i);
        }
        // cout<<jump<<" "<<node<<endl;
    }
    return node;
}
 
int LCA(int nodeA, int nodeB){
    if(lvl[nodeB]>lvl[nodeA]) swap(nodeA,nodeB);
    // cout<<up[nodeA][2]<<endl;
    nodeA = jump_node(nodeA,lvl[nodeA]-lvl[nodeB]);
    // cout<<nodeA<<"*\n";
    if(nodeA==nodeB) return nodeA;
    for(int i=19; i>=0; i--){
        if(up[nodeA][i] != up[nodeB][i]){
            nodeA = up[nodeA][i];
            nodeB = up[nodeB][i];
        }
    }
    return jump_node(nodeA,1);
}

// 1-based nodes
//     dfs(1,-1,0);
//    binary_lift(1,-1);
