#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MIN = -2000000000;

int a[101],dp[110][110];
int N,M;

int rec(int cur, int m){
	if(m == 0) return 0;
	if(cur>N || m<0) return MIN;

	int & ret = dp[cur][m];
	if(ret != MIN) return ret;

	ret = -1000000007;
	ret = max(rec(cur+1,m),ret);

	for(int i=0 ; i+cur<=N ; i++)
		ret = max(ret, rec(cur+i+2, m-1) + a[cur+i] - a[cur-1]);

	return ret;
}

int main(){

	scanf("%d %d",&N,&M);

	for(int i=1 ;i<=N ; i++) scanf("%d",a+i),a[i] += a[i-1];

	for(int i=0 ; i<=109 ; i++)
		for(int j=0 ; j<=109 ; j++)
			dp[i][j] = MIN;

	printf("%d\n",rec(1,M));

	return 0;
}