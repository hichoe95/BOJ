#include <cstdio>

int main(){
	int n,cnt=0;
	scanf("%d",&n);
	for(int i=0 , x ;i<5;i++){
		scanf("%d",&x);
		if(x%10 == n) cnt++;
	}
	printf("%d\n",cnt);
}