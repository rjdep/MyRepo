struct Unionfind
{
    /*
        Unionfind uf(n);
        uf.reset();
        1-based indexing
    */
    int n, set_size, *parent, *rank;
    Unionfind() {}
    Unionfind(int a)
    {
        n = set_size = a;
        parent = new int[n + 1];
        rank = new int[n + 1];
    }

    int find(int x)
    {
        if (x != parent[x])
        {
            return parent[x] = find(parent[x]);
        }
        else
        {
            return x;
        }
    }

    bool check(int x, int y)
    {
        return (parent[x] == parent[y]);
    }
    void merge(int x, int y)
    {
        int xroot = find(x), yroot = find(y);
        if (xroot != yroot)
        {
            if (rank[xroot] >= rank[yroot])
            {
                rank[xroot] += rank[yroot];
                parent[yroot] = xroot;
            }
            else
            {
                rank[yroot] += rank[xroot];
                parent[xroot] = yroot;
            }
            set_size--;
        }
    }

    void reset()
    {
        set_size = n;
        for (int i = 1; i <= n; i++)
        {
            parent[i] = i;
            rank[i] = 1;
        }
    }

    int rnk(int a){
        return rank[a];
    }

    int size()
    {
        return set_size;
    }
};
