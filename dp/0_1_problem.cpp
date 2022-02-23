struct Data{
  int cost, w;
};
int dp[MXN] = {};
Data arr[MXN] = {};
int n, c, w, sum = 0;
cin >> n;
for(int i = 0; i < n; ++i){
  cin >> arr[i].cost >> arr[i].w;
  sum += arr[i].w;
}
dp[0] = 0;
for(int i = 0; i < n; ++i){
  for(int j = sum; j >= arr[i].w; --j){
    dp[j] = max(dp[j], dp[j - arr[i].w])
  }
}