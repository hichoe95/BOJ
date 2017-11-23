#include <cstdio>
#define ll long long
int a[500000],b[500000];

ll solve(int st, int e){
	if(st == e) return 0;

	int mid = (st+e)/2;
	ll ans = solve(st,mid) + solve(mid+1, e);
	int i = st,j=mid+1,k=0;

	while(i<=mid || j<=e){
		if(i<=mid && (j>e || a[i] <= a[j])) b[k++] = a[i++];
		else{
			ans+=(ll)(mid-i+1);
			b[k++] = a[j++];
		}
	}

	for(int i=st ; i<=e ; i++) a[i] = b[i-st];

	return ans;
}

int main(){
	int n;
	scanf("%d",&n);
	for(int i=0 ;i<n ; i++) scanf("%d",&a[i]);

	ll ans = solve(0,n-1);
	printf("%lld",ans);
	return 0;
}
