#include <cstdio>

int main(){
	int n;
	long long mul=1;
	scanf("%d",&n);
	for(int i=1 ;i<=n;i++) mul*=i;
	printf("%lld\n",mul);
	return 0;
}