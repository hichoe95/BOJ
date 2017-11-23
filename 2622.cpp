#include <cstdio>

int main(){

	int n,cnt=0;
	
	scanf("%d",&n);

	for(int i=1 ; i<(double)n/2 ; i++)
		if(!((n-i)%2)) cnt++;

	printf("%d",cnt);

	return 0;
}