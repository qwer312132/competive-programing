struct blk{
    vector<int> local;
    int global, tag;
    blk(){
        local.clear();
        tag = global = 0;
    }
};
int len;
blk arr[MXN] = {};
void build(int &n){
    len = sqrt(n);
    int x;
    for(int i = 0 ; i < n; ++i){
        cin >> x;
        arr[i/len].local.pb(x);
        arr[i/len].global += x;
    }
}
void update(int ql, int qr, int v){
    int l = ql/len, r = qr/len;
    if(l == r){
        for(int i = ql; i <= qr; ++i){
            arr[l].local[i % len] += v;
            arr[l].global += v;
        }
        return;
    }
    for(int i = ql; i < (l + 1) * len; ++i){
        arr[l].local[i % len] += v;
        arr[l].global += v;
    }
    for(int i = l + 1; i < r; ++i){
        arr[i].global += (v * len);
        arr[i].tag += v;
    }
    for(int i = r * len; i <= qr; ++i){
        arr[r].local[i % len] += v;
        arr[r].global += v;
    }
}
int query(int ql, int qr){
    int l = ql/len, r = qr/len, ret = 0;
    if(l == r){
        for(int i = ql; i <= qr; ++i)
            ret += arr[l].local[i % len] + arr[l].tag;
        return ret;
    }
    for(int i = ql; i < (l + 1) * len; ++i)
        ret += arr[l].local[i % len] + arr[l].tag;
    for(int i = l + 1; i < r; ++i)
        ret += arr[i].global;
    for(int i = r * len; i <= qr; ++i)
        ret += arr[r].local[i % len] + arr[r].tag;
    return ret;
}