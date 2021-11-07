class Trie{

private:
    int arr[int(1e6)][26];
    int root;
    int lastocc;
public:
    Trie(){
        root = 0;
        lastocc = 0;
        memset(arr, 0, sizeof(int)*1e6*26);
    }

    void insert(const string &x){
        int curptr = root;

        for(auto ch:x){
            if(arr[curptr][ch-'a']==0)
                arr[curptr][ch-'a'] = ++lastocc;
            curptr = arr[curptr][ch-'a'];
        }
    }

    int search(const string &x){
        int curptr = root;
        for(auto ch:x){
            if(arr[curptr][ch-'a']==0)
                return 0;
            else
                curptr = arr[curptr][ch-'a'];
        }
        return 1;
    }
};
