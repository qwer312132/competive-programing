void bellman(int startPoint){
    dis.clear();dis.resize(n,INF);
    dis[startPoint]=0;
    for(int i=1;i<n;i++){
        for(auto x:edge){
            int a=x.u,b=x.v,c=x.w;
            if(dis[a]+c<dis[b]){
                dis[b]=dis[a]+c;
            }
        }
    }
}