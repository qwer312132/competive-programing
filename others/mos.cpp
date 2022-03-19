int len = sqrt(n);
struct query{
    int l,r,id;//詢問的左界右界 以及 第幾筆詢問
    friend bool operator<(const query& lhs,const query& rhs){
        return ((lhs.l / len) == (rhs.l / len)) ? lhs.r<rhs.r : lhs.l<rhs.l;
    }//先判斷是不是在同一塊 不同塊的話就比較塊的順序，否則比較右界r
};
int ans[200005] = {}, t = 0;
vector<query> q;
void add(int idx){...}
void sub(int idx){...}
void mos(){
    sort(all(q));
    for(int i = 0, l = -2, r = -1; i < q.size(); ++i){
        while(l > q[i].l) add(--l);
        while(r < q[i].r) add(++r);//先做新增元素的
        while(l < q[i].l) sub(l++);//再做移除元素的
        while(r > q[i].r) sub(r--);
        ans[q[i].id] = t//移到區間後儲存答案
    } 
}
