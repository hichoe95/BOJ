#include <iostream>
#include <algorithm>
#include <queue>
#include <functional>
#include <vector>
using namespace std;
#define pii pair<int,int>
#define INF 1e7

int cost[101][101] = {0,};
vector<pii> g[101];
bool dg[101][101][101] = {0,};

int main(){

	ios_base::sync_with_stdio(false);

	priority_queue<pair<pair<int,int>,int>,vector<pair<pair<int,int>,int> >, greater<pair<pair<int,int>,int> > > q;

	int n,l;
	cin >> n;

	for(int i=0 ;i<101 ; i++)
		for(int j=0 ; j<101 ; j++)
			cost[i][j] = INF;

	for(int i=0 ;i<n; i++){
		int m,t;
		cin >> m >> t;
		if(i==n-1) l =t;
		for(int j=0 ; j<m ; j++){
			int a,b;
			cin >> a >> b;
			g[i+1].push_back(pii(b,t));
			for(int k=0 ; k<a ; k++){
				int c;
				cin >> c;
				dg[i+1][b][c] = true;
			}
		}
	}

	cost[0][1] = 0;
	q.push(pair<pii,int>(pii(1,0),0));

	while(q.size()){
		pair<pii,int > cur = q.top();
		q.pop();
		for(pii nx : g[cur.first.first]){
			if(!dg[cur.first.first][nx.first][cur.first.second]){
				if(cost[cur.first.first][nx.first] > cost[cur.first.second][cur.first.first] + nx.second){
					cost[cur.first.first][nx.first] = cost[cur.first.second][cur.first.first] + nx.second;
					q.push(pair<pii,int>(pii(nx.first,cur.first.first), cost[cur.first.first][nx.first]));
				}
			}
		}
	}
	int ans=INF;

	for(int i=0 ;i<n;i++)
		 ans = min(ans,cost[i+1][n]);

	if(ans + l >= INF)
		cout << "impossible" << endl;
	else
		cout << ans + l << endl;


	return 0;


}
