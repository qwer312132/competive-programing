struct Node{
    Node *l, *r;
    int val;
    Node(int _val):val(_val){l = r = nullptr;}
};
void pull(Node *x){x->val = x->r->val + x->l->val;}
void build(Node *&x, int l, int r){
    x = new Node(0);
    if(l == r){
        x->val = arr[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(x->l, l, mid);
    build(x->r, mid + 1, r);
    pull(x);
}
Node *update(Node *&pre, int l, int r, char &c, int &p, int &v){
    Node *x = new Node(0);
    if(l == r){
        if(c == '+') x->val = pre->val + v;
        else x->val = pre->val - v;
        return x;
    }
    int mid = (l + r) >> 1;
    if(p <= mid){
        x->l = update(pre->l, l, mid, c, p, v);
        x->r = pre->r;
    }
    else{
        x->l = pre->l;
        x->r = update(pre->r, mid + 1, r, c, p, v);
    }
    pull(x);
    return x;
}
ll query(Node *x, int l, int r, int ql, int qr){
    if(ql <= l && r <= qr){
        return x->val;
    }
    int mid = (l + r) >> 1, ret = 0;
    if(ql <= mid) ret += query(x->l, l, mid, ql, qr);
    if(mid < qr) ret += query(x->r, mid + 1, r, ql, qr);
    return ret;
}
vector<Node *> vsn;