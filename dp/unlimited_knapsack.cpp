int cost[N], weight[N];
int c[W + 1];
void knapsack(int n, int w){
    for (int i=0; i<n; ++i)
        for (int j = weight[i]; j <= w; ++j)
            c[j] = max(c[j], c[j - weight[i]] + cost[i]);
}