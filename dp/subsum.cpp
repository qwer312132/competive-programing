bitset<MXN> dp;
int n, x;
for(int i = 0; i < MXN; ++i){
  cin >> x;
  dp <<= dp | x;
}