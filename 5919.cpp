#include <cstdio>

int main(){
	int n,a[10000],s=0,ans=0;
	scanf("%d",&n);
	for(int i=0 ;i<n ; i++) scanf("%d",&a[i]),s+=a[i];
	s/=n;
	for(int i=0 ;i<n ; i++)
		if(a[i]-s>0) ans+= a[i]-s;

	printf("%d",ans);
	return 0;
}