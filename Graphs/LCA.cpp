class LCA{
private:
    int n;
    vvi lift;
    vi dep;

    void mark_parents(int node, vvi &adj, int p){
        for(auto x:adj[node]){
            if(x==p) continue;
            dep[x] = dep[node]+1;
            mark_parents(x, adj, node);
            lift[x][0] = node;
        }
    }

    void precomp_LCA(vvi &tree, int root){
        int n = (int) tree.size();
        lift.assign(n, vi(32, root));
        dep.assign(n, 0);
        dep[root] = 0;
        mark_parents(root, tree, -1);
        for(int i=1; i<32; i++)
            for(int j=0; j<n; j++)
                lift[j][i] = lift[lift[j][i-1]][i-1];
    }

public:
    
    LCA() = default;
    
    LCA(vvi &tree, int root){
        precomp_LCA(tree, root);
    }

    void make(vvi &tree, int root) {
        precomp_LCA(tree, root);
    }

    int getLCA(int a, int b){        
        if(dep[a]<dep[b]) swap(a, b);
        int diff = dep[a] - dep[b];

        for(int i=31; i>=0; i--)
            if(diff & (1<<i))
                a = lift[a][i];

        if(a==b) return a;

        for(int i=31; i>=0; i--)
            if(lift[a][i] != lift[b][i])
                a = lift[a][i], b = lift[b][i];

        return lift[a][0];
    }

    int getAncestor(int a, int k){
        for(int i=0; i<32; i++)
            if(k & (1<<i))
                a = lift[a][i];
        return a;
    }

    int depth(int a) { return dep[a]; }

};
