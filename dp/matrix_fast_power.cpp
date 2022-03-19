#define MOD 1'000'000'007
#define ll long long
vector<vector<ll>> operator*(const vector<vector<ll>>& lhs,const vector<vector<ll>>& rhs){
    vector<vector<ll>> ret(lhs.size(),vector<ll>(rhs[0].size(),0));
    for(int i=0;i<lhs.size();i++){
        for(int j=0;j<rhs[0].size();j++){
            for(int k=0;k<rhs.size();k++){
                ret[i][j] += lhs[i][k] * rhs[k][j] % MOD;
                ret[i][j] %= MOD;
    }   }   }
    return ret;
}
vector<vector<ll>> init_value={{1},{0}};//第0,1項
vector<vector<ll>> base={{1,1},{1,0}};//費式數列轉移式
vector<vector<ll>> matrix={{1,0},{0,1}};//單位矩陣
while(y){// x^y
    if(y&1) matrix = matrix * base;
    base = base * base;
    y >>= 1;
}
matrix = matrix * init_value;
cout<< matrix[0][0] << endl;