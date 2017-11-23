#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX=987654321;

int n,m[1001],d[1001];

int main(){
	scanf("%d",&n);
	for(int i=1 ;i<=n; i++)
		scanf("%d",&m[i]);
	for(int i=1 ; i<=n;i++) d[i] = MAX;
	d[1]=0;
	for(int i=1 ;i <= n ;i++)
		for(int j=1 ; j <= m[i] && i+j<=n ; j++)
			d[i+j] = min(d[i]+1, d[i+j]);

	if(d[n] == MAX) printf("%d\n",-1);
	else printf("%d\n",d[n]);
	return 0;
}
