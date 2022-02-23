int dp[MXN];
bool v[MXN];

void dfs(int x){
    if(v[x])    return dp[x];
    v[x] = 1;
    dp[x] = 0;
    for(auto i:edge[x]){
        dp[x] = max(dp[x],dfs(i) + 1);
    }
    return dp[x];
}

int main(){

    for(int i=1;i<=n;i++){
        if(!v[i])   dfs(i);
    }
}