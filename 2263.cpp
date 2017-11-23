#include <cstdio>

int pos[100001];
int n;
int post[100001];
int in[100001];

void prt(int is,int ie,int ps, int pe){
	if(is>ie || ps>pe) return;
	int root = post[pe];
	printf("%d ",root);

	int p = pos[root];
	int left = p - is;
	prt(is,p-1,ps,ps+left - 1);
	prt(p+1,ie,ps+left,pe-1);
}

int main(){

	scanf("%d",&n);
	for(int i=0 ; i<n ; i++) scanf("%d",&in[i]);
	for(int i=0 ; i<n ; i++) scanf("%d",&post[i]);
	for(int i=0 ; i<n ; i++) pos[in[i]] = i;
	prt(0,n-1,0,n-1);

	return 0;
}