vector<int> linear_sieve(int m){
    vector<int> p, d(m, 0);
    for(int i = 2; i < m; ++i){
        if(d[i] == 0) p.emplace_back(i), d[i] = i;
        for(int j = 0; p[j] * i < m; ++j){
            d[p[j] * i] = p[j];
            if(i % p[j] == 0) break;
    } }
    return d;
}