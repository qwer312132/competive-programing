double f(double x) //f(x)為所求的U型函數
double triSearch(double lowest, double highest){
    double low = lowest, high = highest, l, r;
    while(high - low > 1e-6){
        l = low + (high - low) / 3, r = l + (high - low) / 3;
        double lv = f(l), rv = f(r);
        if(lv < rv) high = r;
        else low = l;
    }
    return f(low);
}
