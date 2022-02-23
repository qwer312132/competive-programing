#define MXN 100005
#define LOG 20
vector<int> edge[MXN];
int anc[MXN][LOG];
int tin[MXN],tout[MXN],ti=0;
void build(int x,int f){
    for(int i=0;i<LOG;i++){
        anc[x][i] = f;
        f = anc[f][i];
    }
}
void dfs(int x,int f){
    tin[x] = ti++;
    build(x,f);
    for(auto i:edge[x]){
        if(i == f){
            continue;
        }
        dfs(i,x);
    }
    tout[x] = ti++;
}
bool isAnc(int x,int y){
    return tin[x] <= tin[y] && tout[x] >= tout[y];
}
int query(int x,int y){
    if(isAnc(x,y))  return x;
    if(isAnc(y,x))  return y;
    for(int i=LOG-1;i>=0;i--){
        if(! isAnc(anc[x][i],y)){
            x = anc[x][i];
        }
    }
    return anc[x][0];
}