void tarjans_b(int node, vvi &adj, vi &disc, vi &low, int p, DSU &dsu){
    static int timer = 1;
    if(disc[node]) return;
    low[node] = disc[node] = timer++;

    for(auto &x:adj[node]){
        if(x==p) continue;
        tarjans_b(x, adj, disc, low, node, dsu);
        low[node] = min(low[node], low[x]);
        if(low[x] <= disc[node])
            dsu.unify(node, x);
    }
}

void bridgeCutTree(vvi &adj, vvi &tree, DSU &dsu){
    int n = (int) adj.size();
    vi disc(n);
    vi low(n);
    dsu.make(n);
    tree.resize(n);
    
    tarjans_b(0, adj, disc, low, -1, dsu);
    for(int i=0; i<n; i++){
        for(auto j:adj[i]){
            int ip = dsu[i];
            int jp = dsu[j];
            if(ip==jp) continue;
            tree[ip].pb(jp);
        }
    }
}
