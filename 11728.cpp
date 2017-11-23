#include <cstdio>

int a[1000001],b[1000001],c[2000001];


int main(){

	int n,m;
	scanf("%d %d",&n,&m);

	for(int i=0 ;i<n;i++) scanf("%d",&a[i]);
	for(int i=0 ;i<m;i++) scanf("%d",&b[i]);

	int p=0,q=0,r=0;
	
	while(p<n && q<m)
		if(a[p] < b[q]) c[r++] = a[p++];
		else c[r++] = b[q++];

	while(p<n) c[r++] = a[p++];
	while(q<m) c[r++] = b[q++];

	for(int i=0 ;i<n+m ; i++) printf("%d ",c[i]);

	return 0;
}