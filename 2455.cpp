#include <cstdio>
#define max(a,b) a>b?a:b
int main(){
	int sum = 0,cur=0;
	for(int i=0 , x,y ; i<4 ; i++){
		scanf("%d %d",&x,&y);
		cur = cur - x + y;
		sum = max(sum,cur);
	}
	printf("%d",sum);
	return 0;
}