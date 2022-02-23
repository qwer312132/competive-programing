void dijkstra(int startPoint,int endPoint){
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq;
    v.clear();v.resize(n);
    dis.clear();dis.resize(n,INF);
    dis[startPoint]=0;
    pq.push({dis[startPoint],startPoint});    
    //將起點加進去pq裡面
    while(!pq.empty()){                       
        //當pq還有東西時繼續做
        auto u=pq.top();pq.pop();             
        //每次取出離起點最近的點
        if(v[u.second]) continue;             
        //如果之前走過代表已經有更短的路經過不用在重新走
        v[u.second]=1;                        
        //設成走過
        for(auto i:edge[u.second]){
            if(dis[i.first]>u.first+i.second){    
                //判斷是否可以鬆弛
                dis[i.first]=u.first+i.second;    
                pq.push({dis[i.first],i.first});  
                //將可鬆弛的路連出去
            }
        }
    }
    cout<<dis[endPoint]<<endl;
}