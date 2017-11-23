#include <cstdio>

int main(){
	int n;
	scanf("%d",&n);
	long long d[31]={0,},ans;
	d[1] = 1;
	d[2] = 3;

	for(int i=3 ; i<=n ; i++) d[i] = d[i-1] + d[i-2]*2;
	if(!(n%2)) ans = (d[n] + d[n/2+1])/2;
    else ans = (d[n] + d[(n-1)/2])/2;
    if(n==1) printf("1");
	else printf("%lld",ans);
	return 0;
}