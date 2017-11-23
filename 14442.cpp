#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
#define INF 1e9
#define pii pair<int,int>

int g[1002][1002];
int dp[1002][1002][11];// dp[x][y][k] k개를 부수고 (x,y)에 왔을때 까지의 최단경로.


int main(){

	int n, m, k;
	scanf("%d %d %d",&n,&m,&k);

	pii dir[4] = {pii(1,0),pii(-1,0),pii(0,1),pii(0,-1)};

	queue<pii> q;

	memset(g,-1,sizeof(g));
	memset(dp,0x3f,sizeof(dp));

	dp[1][1][0] = 1;

	for(int i=1 ; i<=n ;i++)
		for(int j=1 ;j<=m ;j++)
			scanf("%1d",&g[i][j]);

	q.push(pii(1,0));// (현재 좌표, 지금까지 온 경로 길이)

	while(q.size()){
		pii cur = q.front();
		q.pop();
		int cur_x = (cur.first-1)/m+1,cur_y = (cur.first-1)%m+1;

		for(pii go : dir){
			int next_x = cur_x+go.first, next_y = cur_y + go.second;
			int next_k = cur.second + g[next_x][next_y];

			if(g[next_x][next_y]!=-1){
				if( dp[next_x][next_y][next_k] > dp[cur_x][cur_y][cur.second]+1 && next_k <= k){
					dp[next_x][next_y][next_k] = dp[cur_x][cur_y][cur.second]+1;
					q.push(pii((next_x-1)*m + next_y,next_k));
				}
			}
		}
	}

	int ans = INF;
	for(int i=0 ; i <= k ; i++) ans = min(ans,dp[n][m][i]);
	if(ans == INF) printf("-1\n");
	else printf("%d\n",ans);


	return 0;
}