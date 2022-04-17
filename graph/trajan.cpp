struct Scc{
  int n, nScc, vst[MXN], bln[MXN], num;
  int dfn[MXN], low[MXN];
  vector<int> E[MXN];
  stack<int> stk;
  void init(int _n){
    n = _n;
    num = nScc = 0;
    for(int i = 0; i <= n; ++i) E[i].clear();
    FZ(vst); FZ(dfn); FZ(low);
    while(!stk.empty()) stk.pop();
  }
  void addEdge(int u, int v){E[u].pb(v);}
  void dfnlow(int u){
    int v;
    dfn[u] = low[u] = ++num;
    stk.push(u); vst[u] = 1;
    for(int i = 0; i < E[u].size(); ++i){
      v = E[u][i];
      if(!dfn[v]){dfnlow(v);low[u] = min(low[u], low[v]);}
      else if(vst[v]) low[u] = min(low[u], dfn[v]);
    }
    if(dfn[u] == low[u]){
      int t;
      ++nScc;
      do{
        t = stk.top(); stk.pop();
        vst[t] = 0; bln[t] = nScc;
      }while (t != u);
  } }
  void solve() {
    for(int i = 1; i <= n; ++i) if(!dfn[i]) dfnlow(i);
  } };