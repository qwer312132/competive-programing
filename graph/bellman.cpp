void bellman(int startPoint){
    dis.clear();dis.resize(n,INF);
    dis[startPoint]=0;
    for(int i=1;i<n;i++){    //iteration n-1 times
        for(auto x:edge){    //relaxation edge
            int a=x.u,b=u.v,c=u.w; //from a to b weight c
            if(dis[a]+c<dis[b]){
                dis[b]=dis[a]+c;
            }
        }
    }
}