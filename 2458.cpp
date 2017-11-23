#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
int visited[501];
vector<int> l[501],s[501];

void ldfs(int n){
	visited[n] = 1;
	for(int i : l[n])
		if(!visited[i])
			ldfs(i);
}
void sdfs(int n){
	visited[n] = 1;
	for(int i : s[n])
		if(!visited[i])
			sdfs(i);
}

int main(){
	int n,m,cnt=0;
	scanf("%d %d",&n,&m);

	for(int i=0,x,y; i<m; i++){
		scanf("%d %d",&x,&y);
		l[x].push_back(y);
		s[y].push_back(x);
	}

	for(int i=1 ; i<=n; i++){
		int flag=0;
		ldfs(i),sdfs(i);
		for(int k=1 ; k<=n; k++) if(!visited[k]) flag=1;
		if(!flag) cnt++;
		memset(visited,0,sizeof(visited));
	}

	printf("%d\n",cnt);
	return 0;
}