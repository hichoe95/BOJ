#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 987654321

int dp[101][101];
int n,m,k,x,y;


int main(){
	cin >> n >> m >> k;
	vector<pair<int,int>> skill(n+1);

	for(int i=1;i<=n;i++){
		cin >> x >> y;
		skill[i].first = x;
		skill[i].second = y;
	}

	for(int i=0 ;i<=100;i++)
		for(int j=1 ;j<=100;j++)
			dp[i][j] = INF;

	for(int i=1 ;i<=n;i++){
		for(int j=1 ; j<=m;j++){
			int a = j/skill[i].second;
			for(int l=0; l<=a ; l++){
				dp[i][j] = min(dp[i][j],dp[i-1][j-skill[i].second*l]+ skill[i].first*l + k*l*(l-1)/2);
			}
		}
	}

	cout << dp[n][m] << '\n';

}