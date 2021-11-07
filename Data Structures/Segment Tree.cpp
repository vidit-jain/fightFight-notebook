template <typename T>
class Segtree{
private: 
    int n;
    vector<T> tree;
    T identity;

    T merge(T a, T b){
        return a + b;
    }

    T __query(int node, int seg_l, int seg_r, int q_l, int q_r){
        if(seg_l >= q_l && seg_r <= q_r) return tree[node];
        if(seg_l > q_r || seg_r < q_l) return identity;
        int mid = seg_l + (seg_r-seg_l)/2;
        return merge(__query(2*node, seg_l, mid, q_l, q_r), __query(2*node+1, mid+1, seg_r, q_l, q_r));
    }

    void build(vector<T> &arr){
        int sz = (int) arr.size();
        n = 1 << (32 - __builtin_clz (sz - 1));
        tree.resize(2*n);
        for(int i=0; i<sz; i++) tree[n+i] = arr[i];
        for(int i=sz; i<n; i++) tree[n+i] = identity;
        
        for(int i=n-1; i>=1; i--) 
            tree[i] = merge(tree[2*i], tree[2*i+1]);
    }

public:
    Segtree(vector<T> &arr, T id){
        identity = id;
        build(arr);
    }

    T query(int l, int r){
        return __query(1, 0, n-1, l, r);
    }

    void update(int node, T value){
        tree[n+node] = value;
        for(int i=(n+node)/2; i>=1; i/=2)
            tree[i] = merge(tree[2*i], tree[2*i+1]);
    }
};
