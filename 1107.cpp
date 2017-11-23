#include <cstdio>
#include <algorithm>

bool bt[11];

int check(int n){
	if(!n)
		return bt[n] ? 0 : 1;
	int len = 0;
	while(n){
		if(bt[n%10]) return 0;
		len++;
		n/=10;
	}
	return len;
}

int main(){

	int N,M;
	scanf("%d%d",&N,&M);

	for(int i=0 , x ;i<M ;i++){
		scanf("%d",&x);
		bt[x] = true;
	}

	int ans = (N - 100);
	if(ans<0) ans = -ans;

	for(int i=0 ; i<=1000000 ; i++){
		int len = check(i);
		int a = i-N;
		if(a<0) a= -a;
		if(len>0) ans = std::min(ans,len + a);
	}

	printf("%d",ans);

	return 0;
}