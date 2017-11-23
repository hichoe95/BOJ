#include <cstdio>
#include <cstring>
#define ll long long
#define INF 1e9

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int M[501][501];
ll dp[501][501];// (x,y)에서 n,m으로 가는 내리막길의 수
bool visited[501][501];
int n,m;


ll go(int x, int y){

	if(x == n && y == m) return 1;
	if(dp[x][y]!=-1) return dp[x][y];

	ll sum = 0;
	int cur = M[x][y];

	for(int i=0 ; i <4 ; i++){
		int nx = x+dx[i],ny = y+dy[i];
		if(!visited[nx][ny] && cur > M[nx][ny]){
			visited[nx][ny] = true;
			sum+=go(nx,ny);
			visited[nx][ny] = false;
		}
	}
	dp[x][y] = sum;
	return sum;
}


int main(){
	scanf("%d %d",&n,&m);

	for(int i=0 ;i<=500 ; i++) M[i][0] = M[0][i] = INF;
	memset(dp,-1,sizeof(dp));
	for(int i=1 ;i <= n ; i++)
		for(int j=1 ; j<=m ; j++)
			scanf("%d",&M[i][j]);

	visited[1][1] = true;
	printf("%lld",go(1,1));

	return 0;
}