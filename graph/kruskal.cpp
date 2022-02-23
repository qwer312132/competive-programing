struct Edge{
    int u,v,w;
    friend bool operator<(const Edge& lhs,const Edge& rhs){
        return lhs.w<rhs.w;
    }
};
vector<Edge> graph;
void kruskal(){
    int sum=0;
    sort(graph.begin(),graph.end());
    for(auto i:graph){
        if(Find(i.u)!=Find(i.v)){
            Union(find(i.u),find(i.v));
            sum+=i.w;
        }
    }
    cout<<sum<<endl;
}