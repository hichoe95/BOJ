#include <cstdio>

int main(){
	int n,x;
	scanf("%d %d",&n,&x);

	for(int i=0,a;i<n;i++){
		scanf("%d",&a);
		if(a<x) printf("%d ",a);
	}
	return 0;
}