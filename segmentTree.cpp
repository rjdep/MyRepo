const int N = 100100;
int T[4*N];
int arr[N];
int merge(int a, int b){
    return a^b;
}
void build(int id, int l, int r){
    if(l==r){
        T[id]=(arr[l]);
        return;
    }
    int mid = (l+r)/2;
    build(id<<1,l,mid);
    build(id<<1|1,mid+1,r);
    T[id]=merge(T[id<<1],T[id<<1|1]);
}
int querry(int id, int l, int r, int lq, int rq){
    if(l>=lq && r<=rq) return T[id];
    if(lq>r || rq<l) return 0;
    int mid = (l+r)/2;
    return merge(querry(id<<1,l,mid,lq,rq),querry(id<<1|1,mid+1,r,lq,rq));
}

void update(int node, int l, int r, int idx, int val){
    if(l>idx || r<idx) return;
    if(l==r){
        T[node]=val;
        arr[idx]=val;
        return;
    }
    int mid = (l+r)/2;
    update(node<<1,l,mid,idx,val);
    update(node<<1|1,mid+1,r,idx,val);
    T[node]=merge(T[node<<1],T[node<<1|1]);
}
