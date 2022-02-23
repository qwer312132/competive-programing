int power(int a,int b){
    int ans=1,base=a;
    while(b!=0){
        if(b&1){//如果是奇数 
            ans*=base;//向结果赋值 
        }
        base*=base;//基础相乘
        b=b/2; 
    }
    return ans;
}