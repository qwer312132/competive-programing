bitset<MXN> dp;
int n, x;
cin >> n;
for(int i = 0; i < n; ++i){
  cin >> x;
  dp <<= dp | x;
}