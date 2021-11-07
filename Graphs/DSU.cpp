class DSU{
private:
    vector<int> dsu;
    vector<int> rank;

    void __makedsu(int n){
        dsu.resize(n);
        rank.resize(n);
        for(int i=0; i<n; i++) dsu[i] = i;
    }

public:
    DSU(){}
    DSU(int n){ __makedsu(n); }
    void make(int n){ __makedsu(n); }
    
    int parent(int i){
        if(dsu[i]==i) return i;
        else return dsu[i] = parent(dsu[i]);
    }

    int operator[](int i){
        return parent(i);
    }

    void unify(int a, int b){
        a = parent(a);
        b = parent(b);
        if(rank[a] < rank[b])
            swap(a, b);
        dsu[b] = a;
        if(a!=b && rank[a] == rank[b])
            rank[a]++;
    }
};
