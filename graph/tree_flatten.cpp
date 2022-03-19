int ti=0;
vector<pair<int,int> > dfsTime(n);
int dfs(int x,int f){
    dfsTime[x].first=dfsTime[x].second=ti++;
    for(auto i:edge[x]){
        if(i==f) continue;
        dfsTime[x].second=max(dfsTime[x].second,
                              dfs(i,x));//紀錄最右界
    }
    return dfsTime[x].second;
}