struct trie{
    trie *nxt[26];
    int cnt,sz;
    trie():cnt(0),sz(0){
        memset(nxt,0,sizeof(nxt));
    }
};
trie *root = new trie();
void insert(string& s){
    trie *now = root;  // 每次從根結點出發
    for(auto i:s){
        now->sz++;
        if(now->nxt[i-'a'] == NULL){
            now->nxt[i-'a'] = new trie();
        }
        now = now->nxt[i-'a'];  //走到下一個字母
    }
    now->cnt++;
    now->sz++;
}
int query_prefix(string& s){  //查詢有多少前綴為 s
    trie *now = root;    // 每次從根結點出發
    for(auto i:s){
        if(now->nxt[i-'a'] == NULL)return 0;
        now = now->nxt[i-'a']; 
    }
    return now->sz;
}
int query_count(string& s){  //查詢字串 s 出現次數
    trie *now = root;    // 每次從根結點出發
    for(auto i:s){
        if(now->nxt[i-'a'] == NULL)return 0;
        now = now->nxt[i-'a'];
    }
    return now->cnt;
}