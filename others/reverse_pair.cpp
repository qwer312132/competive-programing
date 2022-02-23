int ans;
vector<int>arr;
vector<int>temparr;
void msort(int s,int t) {
	if(s==t) return ;
	int mid=(s+t)>>1;
	msort(s,mid),msort(mid+1,t);	
	int i=s,j=mid+1,k=s;
	while(i<=mid && j<=t) {
		if(arr[i]<=arr[j]) temparr[k]=arr[i],k++,i++;
		else temparr[k]=arr[j],k++,j++,ans+=mid-i+1;
	}
	while(i<=mid) temparr[k]=arr[i],k++,i++;
	while(j<=t) temparr[k]=arr[j],k++,j++;
	for(int i=s;i<=t;i++) arr[i]=temparr[i];
	return ;
}