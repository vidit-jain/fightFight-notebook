class Trie{

private:
    struct Node{
        int val;
        Node *arr[26];
    } *root;

public:
    Trie(){
        root = new Node();
    }

    void insert(const string &x){
        Node *curptr = root;
        for(auto ch:x){
            if(curptr->arr[ch-'a']==NULL)
                curptr->arr[ch-'a'] = new Node();
            curptr = curptr->arr[ch-'a'];
        }
    }

    int search(const string &x){
        Node *curptr = root;
        for(auto ch:x){
            if(curptr->arr[ch-'a']==NULL)
                return 0;
            else
                curptr = curptr->arr[ch-'a'];
        }
        return 1;
    }
};

