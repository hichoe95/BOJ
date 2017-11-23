#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;
#define pb push_back

int g[201][201],c[201];
int n;
long long cnt,m;

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	vector<pair<int,int> > t[201];

	for(int i=0 ; i<m ;i++){
		int u,v;
		cin >> u >> v;
		g[u][v] = 1;
		g[v][u] = 1;
	}

	for(int i=1 ;i<=n; i++)
		for(int j=i+1;j<=n;j++)
			if(g[i][j]){
				for(int k = j+1 ; k<=n;k++){
					if(g[i][k] && g[j][k]){
						t[i].pb(pair<int,int>(j,k));
						t[j].pb(pair<int,int>(i,k));
						t[k].pb(pair<int,int>(i,j));
					}
				}
			}

	for(int i=1 ; i<=n ; i++){
		int sz = t[i].size();
		cnt += (sz*(sz-1))/2;
		for(int j = 0 ; j<sz ; j++){
			c[t[i][j].first]++;
			c[t[i][j].second]++;
		}
		for(int j=1 ; j<=n ; j++) 
			cnt -= (c[j]*(c[j]-1))/2;
		memset(c,0,sizeof(c));
	}

	cout << cnt << endl;
	return 0;
}