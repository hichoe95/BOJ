#include <cstdio>
#include <cmath>

void rec(int x, int y, int n){
	if(!n) return;

	rec(x,6-x-y,n-1);
	printf("%d %d\n",x,y);
	rec(6-x-y,y,n-1);
}

int main(){
	int n;
	scanf("%d",&n);
	printf("%d\n",(int)pow(2,n)-1);
	rec(1,3,n);
	return 0;
}