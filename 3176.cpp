#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

#define abs(a) a<0 ? -a : a;

vector<pair<int,int>> graph[100001];
int parent[100001][20],mm[100001][20],MM[100001][20];
int depth[100001];

void dfs(int i,int dep){
	depth[i] = dep;
	for(pair<int,int> a : graph[i]){
		if(depth[a.first]==-1){
			parent[a.first][0] = i;
			mm[a.first][0] = a.second;
			MM[a.first][0] = a.second;
			dfs(a.first,dep+1);
		}
	}
}


int main(){

	int n;
	scanf("%d",&n);

	for(int i=0,x,y,w;i<n-1 ; i++){
		scanf("%d %d %d",&x,&y,&w);
		graph[x].push_back(pair<int,int>(y,w));
		graph[y].push_back(pair<int,int>(x,w));
	}
	memset(depth,-1,sizeof(depth));
	dfs(1,0);//depth[] 작성, Tree만들기

	for(int j=1 ; j<20 ; j++)
		for(int i = 1 ; i<=n; i++){
			parent[i][j] = parent[parent[i][j-1]][j-1];
			mm[i][j] = min(mm[i][j-1], mm[parent[i][j-1]][j-1]);
			MM[i][j] = max(MM[i][j-1], MM[parent[i][j-1]][j-1]);
		}

	int k;
	scanf("%d",&k);

	for(int i=0 ,x,y;i<k ;i++){
		scanf("%d %d",&x,&y);
		int M = -1, m = 987654321;
		int sub = abs((depth[x] - depth[y]));

		if(depth[x] < depth[y]){// x가 뎁스 깊음 
			int temp = x;
			x = y;
			y = temp;
		}

		for(int j=0 ; sub ; sub>>=1,j++)
			if(sub&1){
				m = min(m,mm[x][j]);
				M = max(M,MM[x][j]);
				x = parent[x][j];
			}

		if(x!=y){
			for(int i=19 ; i>=0 ; i--){
				if(parent[x][i] != parent[y][i]){
					m = min(m,min(mm[x][i],mm[y][i]));
					M = max(M,max(MM[x][i],MM[y][i]));
					x = parent[x][i];
					y = parent[y][i];
				}

			}
				m = min(m,min(mm[x][0],mm[y][0]));
				M = max(M,max(MM[x][0],MM[y][0]));

		}

		printf("%d %d\n",m,M);

	}


	return 0;
}