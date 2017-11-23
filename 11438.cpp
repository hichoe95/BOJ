#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

#define abs(a) a<0 ? -a : a;

vector<int> graph[100001];
int parent[100001][20];
int depth[100001];

void dfs(int i,int dep){
	depth[i] = dep;
	for(int a : graph[i]){
		if(depth[a]==-1){
			parent[a][0] = i;
			dfs(a,dep+1);
		}
	}
}


int main(){

	int n;
	scanf("%d",&n);

	for(int i=0,x,y;i<n-1 ; i++){
		scanf("%d %d",&x,&y);
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	memset(depth,-1,sizeof(depth));
	dfs(1,0);//depth[] 작성, Tree만들기

	for(int j=1 ; j<20 ; j++)
		for(int i = 1 ; i<=n; i++){
			parent[i][j] = parent[parent[i][j-1]][j-1];
		}

	int k;
	scanf("%d",&k);

	for(int i=0 ,x,y;i<k ;i++){
		scanf("%d %d",&x,&y);
		int sub = abs((depth[x] - depth[y]));

		if(depth[x] < depth[y]){// x가 뎁스 깊음 
			int temp = x;
			x = y;
			y = temp;
		}

		for(int j=0 ; sub ; sub>>=1,j++)
			if(sub&1)
				x = parent[x][j];

		int j = 0;
		if(x!=y){
			for(int i=19 ; i>=0 ; i--){
				if(parent[x][i] != parent[y][i]){
					x = parent[x][i];
					y = parent[y][i];
				}

			}
			x = parent[x][0];
			y = parent[y][0];

		}

		printf("%d\n",x);

	}
	return 0;
}