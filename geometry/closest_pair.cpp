#define x first
#define y second
vector<pair<int, int> > p;
set<pair<int, int> > s;
ld dis(pair<int, int> &a, pair<int, int> &b){
    ld x = a.x-b.x, y = a.y-b.y;
    return sqrt(x*x + y*y);
}
int main(){
    int n;
    while(cin>>n){
        p.assign(n,{0,0});
        for(int i = 0;i < n;i++)cin>>p[i].x>>p[i].y;
        sort(p.begin(),p.end());
        s.clear();
        s.insert({p[0].y,p[0].x});
        int l = 0;ld ans = 5e18;
        for(int i = 1;i < n;i++){
            int d = ceil(ans);
            while(l < i && p[l].x < p[i].x - d){
                s.erase({p[l].y,p[l].x});
                l++;
            }
            auto it_l = s.lower_bound({p[i].y - d,0});
            auto it_r = s.upper_bound({p[i].y + d,0});
            for(auto it = it_l;it != it_r;it++){
                ans = min(ans,dis({it->y,it->x},p[i]));
            }
            s.insert({p[i].y,p[i].x});
        }
        cout<<ans<<endl;
    }
    return 0;
}