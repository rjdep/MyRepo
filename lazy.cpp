// Q
// 1 L R val -> Make all values from L to R equal to val
// 2 L R -> Sum of values from L to R

const int N = 200100;
int arr[N], T[4*N], lazy[4*N];

int merge(int a, int b){
    return a+b;
}

void update(int id, int l, int r, int lq, int rq, int val){
    if(lazy[id]){
        T[id]=(r - l + 1)*lazy[id];
        if(l!=r){
            lazy[id<<1]=lazy[id];
            lazy[id<<1|1]=lazy[id];
        }
        lazy[id]=0;
    }
    if(l>=lq && r<=rq){
        T[id]=(r-l+1)*val;
        if(l != r){
            lazy[id<<1] = val;
            lazy[id<<1|1] = val;
        }
        return;
    }
    if(lq>r || rq<l) return;
    int mid = (l+r)/2;
    update(id<<1,l,mid,lq,rq,val);
    update(id<<1|1,mid+1,r,lq,rq,val);
    T[id]=merge(T[id<<1],T[id<<1|1]);

}

int query(int id, int l, int r, int lq, int rq){
    if(lq>r || rq<l) return 0;
    if(lazy[id]){
        T[id]=(r-l+1)*lazy[id];
        if(l != r){
            lazy[id<<1] = lazy[id];
            lazy[id<<1|1] = lazy[id];
        }
        lazy[id]=0;
    }
    if(l>=lq && r<=rq){
        return T[id];
    }
    int mid = (l+r)/2;
    return merge(query(id<<1,l,mid,lq,rq),query(id<<1|1,mid+1,r,lq,rq));
}

void build(int id, int l, int r){
    if(l==r){
        T[id]=arr[l];
        lazy[id]=0;
        return;
    }
    int mid = (l+r)/2;
    build(id<<1,l,mid);
    build(id<<1|1,mid+1,r);
    T[id]=merge(T[id<<1],T[id<<1|1]);
}
