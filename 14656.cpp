#include <cstdio>

int main(){
	int n,cnt=0;
	scanf("%d",&n);
	for(int i=1,x ;i<=n;i++){
		scanf("%d ",&x);
		if(x!=i) cnt++;
	}
	printf("%d\n",cnt);
	return 0;
}