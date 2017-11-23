#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define R 0
#define G 1
#define B 2
int card[1001],n,m,k,map[501][501],dp[1001][501],M=0;
vector<int> g[501];

int main(){
	ios_base::sync_with_stdio(false);

	cin >> n;
	for(int i=1 ;i<=n;i++){
		char a;cin >> a;
		if(a == 'R') card[i] = R;
		else if(a == 'G') card[i] = G;
		else card[i] = B;
	}
	cin >> m >> k;
	for(int i=0 ;i<k ;i++){
		int a,b;char c;
		cin >> a >> b >> c;
		g[a].push_back(b);
		g[b].push_back(a);
		if(c == 'R') map[a][b] = R,map[b][a] = R;
		else if(c == 'G') map[a][b] = G,map[b][a] = G;
		else map[a][b] = B,map[b][a] = B;
	}
	memset(dp,-1,sizeof(dp));

	for(int i : g[1])
		if(card[1] == map[1][i]) dp[1][i] = 10;
		else dp[1][i] = 0;

	for(int i=2 ; i<=n;i++){
		for(int j=1 ; j<=m ; j++){
			for(int l : g[j]){
				if(dp[i-1][l] != -1){
					if(card[i] == map[j][l]) dp[i][j] = max(dp[i][j],dp[i-1][l] + 10);
					else dp[i][j] = max(dp[i][j],dp[i-1][l]);
				}
				M = max(M,dp[i][j]);
			}
		}
	}

	cout << M << '\n';

	return 0;
}