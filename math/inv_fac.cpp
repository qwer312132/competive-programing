vector<int> inv(int n, int p){
    vector<int> fac(n + 1), inv_fac(n + 1);
    fac[0] = 1;
    for(int i = 1; i <= n; ++i) fac[i] = fac[i - 1] * i % p;
    inv_fac[n] = power(fac[n], p - 2);
    for(int i = n - 1; i >= 0; --i) 
        inv_fac[i] = inv_fac[i + 1] * (i + 1) % p;
    vector<int> inv(n + 1); inv[0] = 1;
    for(int i = 1; i <= n ; ++i)
        inv[i] = 1LL * fac[i - 1] * inv_fac[i] % p;
    return inv;
}