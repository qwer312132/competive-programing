struct Example{
  int x;
  friend bool operator>(const Example &a, const Example &b){
    return a.x > b.x;
} }; set<Example> s;// map<Example, int> mp;
struct cmp{
    bool operator()(const int &a,const int &b){return a>b;}
}; set<int, cmp> s;//map<int, int, cmp> mp;