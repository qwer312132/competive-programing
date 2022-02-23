// 最近點對
#include<bits/stdc++.h>
#define double long double
#define INF 1'000'000'000
#define MXN 3'000'005
using namespace std;
struct pt{
    double x,y;
}arr[MXN],sorted_y[MXN];
struct cmp_x{
    bool operator ()(const pt& lhs,const pt& rhs){
        if(lhs.x != rhs.x)  return lhs.x < rhs.x;
        return lhs.y < rhs.y;
    }
};
struct cmp_y{
    bool operator ()(const pt& lhs,const pt& rhs){
        if(lhs.y != rhs.y)  return lhs.y < rhs.y;
        return lhs.x < rhs.x;
    }
};
int n;
double ans=INF;
pt Left[MXN],Right[MXN],tmp[MXN];
inline double dist(int i,int j){
    return sqrt((arr[i].x-arr[j].x)*(arr[i].x-arr[j].x)+(arr[i].y-arr[j].y)*(arr[i].y-arr[j].y));
}
inline double dist(const pt& lhs,const pt& rhs){
    return sqrt((lhs.x-rhs.x)*(lhs.x-rhs.x)+(lhs.y-rhs.y)*(lhs.y-rhs.y));
}
void merge(int l,int r){
    int mid = (l+r)/2;
    int l_num=0,r_num=0;
    for(int i=l;i<=mid;i++){
        if(abs(sorted_y[i].x-arr[mid].x)<ans){
            Left[l_num] = sorted_y[i];
            l_num++;
        }
    }
    for(int i=mid+1;i<=r;i++){
        if(abs(sorted_y[i].x-arr[mid].x)<ans){
            Right[r_num] = sorted_y[i];
            r_num++;
        }
    }
    for(int i=0,j=0;i<l_num;i++){
        while(j+1 < r_num && Left[i].y > Right[j].y){
            j++;
        }
        for(int k=j;k<r_num && abs(Left[i].y-Right[k].y)<ans;k++){
            ans = min(ans, dist(Left[i],Right[k]));
        }
    }
    for(int i=0,j=0;i<r_num;i++){
        while(j+1 < l_num && Right[i].y > Left[j].y){
            j++;
        }
        for(int k=j;k<l_num && abs(Right[i].y-Left[k].y)<ans;k++){
            ans = min(ans, dist(Right[i],Left[k]));
        }
    }
    int l_id=l,r_id=mid+1,id=0; //merge sort
    while(l_id<=mid && r_id<=r){
        if(sorted_y[l_id].y < sorted_y[r_id].y){
            tmp[id++] = sorted_y[l_id++];
        }
        else{
            tmp[id++] = sorted_y[r_id++];
        }
    }
    while(l_id<=mid)    tmp[id++]=sorted_y[l_id++];
    while(r_id<=r)      tmp[id++]=sorted_y[r_id++];
    for(int i=l;i<=r;i++)   sorted_y[i] = tmp[i-l];
}
void closest_pair(int l,int r){
    if(r-l<=3){
        for(int i=l;i<=r;i++){
            for(int j=i+1;j<=r;j++){
                ans=min(ans,dist(i,j));
                sort(sorted_y+l,sorted_y+r+1,cmp_y());
            }
        }
        return;
    }
    int mid = (l+r)/2;
    closest_pair(l,mid);
    closest_pair(mid+1,r);
    merge(l,r);
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i].x>>arr[i].y;
        sorted_y[i] = arr[i];
    }
    sort(arr,arr+n,cmp_x());
    closest_pair(0,n-1);
    cout<<fixed<<setprecision(4)<<ans<<endl;
    return 0;
}