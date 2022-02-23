dp[0] = 1;
for(int i = 1; i <= MXN; ++i){
  int tmp = i * w[i], now = i;
  while(tmp){
    tmp -= now;
    for(int j = now j <= sum; ++j){
      dp[j] |= dp[j - now];
    }
    now <<= 1;
    if(now > tmp) now = tmp;
  }
}