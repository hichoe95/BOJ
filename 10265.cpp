#include <cstdio>
#include <algorithm>
using namespace std;
int n,k;
int r[1001];
bool visited[1001];

int dfs(int i,int dep){//깊이 탐색. 연결고리 탐색.
	
	if(!visited[r[i]]){
		visited[r[i]] = true;
		return dfs(r[i],dep+1);
	}
	else return dep;
}
int dfs2(int i,int dep){//깊이 탐색. 연결고리 탐색.
	int k=0;
	if(!visited[r[i]]){
		visited[r[i]] = true;
		k = dfs(r[i],dep+1);
		visited[r[i]] = false;
	}
	else return dep;

	return k;
}

int ks(int i,int sum){

	for(int k = 1 ; k<=n ; k++){
		if(!visited[k]){
			int next = dfs2(k);
			max(ks(k,sum),ks(k,dfs(i) + sum));

		}
	}

}


int main(){

	
	scanf("%d %d",&n,&k);
	for(int i=1 ; i<=n ; i++) scanf("%d",&r[i]);

	printf("%d\n",dfs(1,1));

	return 0;
}