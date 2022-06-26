//H[l, r] = H[r] - H[l-1] * p^(r - l + 1)
const ll P1 = 75577;
const ll P2 = 12721;    // 多一個質數 p2
const ll MOD = 998244353;
pair<ll,ll> h1[100005];
void build(const string& s){
    pair<ll,ll> val = make_pair(0,0);
    h1[0] = {0, 0};
    for(int i=0; i<s.size(); i++){
        val.first = (val.first * P1 + s[i]) % MOD;
        val.second = (val.second * P2 + s[i]) % MOD;
        h1[i + 1] = val;
    }
}