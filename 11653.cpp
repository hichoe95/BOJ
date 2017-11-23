#include <cstdio>

void pf(int n,int i){

	if(n==1) return;

	for(; i<=n ;i++) if(!(n%i)) break;

	printf("%d\n",i);
	pf(n/i,i);
}

int main(){
	int n;
	scanf("%d",&n);
	pf(n,2);
	return 0;
}