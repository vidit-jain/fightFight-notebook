vector<vector<int>> g, gt;
vector<bool> used;
vector<int> order, comp;
vector<bool> assignment;

void dfs1(int v) {
    used[v] = true;
    for (int u : g[v]) {
        if (!used[u])
            dfs1(u);
    }
    order.push_back(v);
}

void dfs2(int v, int cl) {
    comp[v] = cl;
    for (int u : gt[v]) {
        if (comp[u] == -1)
            dfs2(u, cl);
    }
}

bool solve_2SAT(int n) {
    n <<= 1;
    order.clear();
    used.assign(n, false);
    for (int i = 0; i < n; ++i) {
        if (!used[i])
            dfs1(i);
    }

    comp.assign(n, -1);
    for (int i = 0, j = 0; i < n; ++i) {
        int v = order[n - i - 1];
        if (comp[v] == -1)
            dfs2(v, j++);
    }

    assignment.assign(n / 2, false);
    for (int i = 0; i < n; i += 2) {
        if (comp[i] == comp[i + 1])
            return false;
        assignment[i / 2] = comp[i] > comp[i + 1];
    }
    return true;
}
void add_edge(int p, int q) { g[p].pb(q); gt[q].pb(p); }

void add_imp(int p, int q) { add_edge(p, q); add_edge(q ^ 1, p ^ 1);}
void add_equiv(int p, int q) { add_imp(p, q); add_imp(q, p); }

void add_true(int p) { add_edge(p ^ 1, p); }
void add_and(int p, int q) { add_true(p); add_true(q); }

void add_or(int p, int q) { add_edge(p ^ 1, q); add_edge(q ^ 1, p); }
void add_xor(int p, int q) { add_or(p, q); add_or(p ^ 1, q ^ 1); }
