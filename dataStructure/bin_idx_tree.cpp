#define lowbit(x) (x & -x)
int bit[MXN + 1], n;
void update(int x,int v){
    while(x<=n){
        bit[x] += v;
        x += lowbit(x);
    }
}
int query(int x){
    int ret=0;
    while(x){// 當不為 0 時
        ret += bit[x];// 回傳值加上BIT[x]
        x -= lowbit(x);// 每次減掉自己的lowbit
    }
    return ret;
}