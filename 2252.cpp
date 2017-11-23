#include <cstdio>
#include <vector>
using namespace std;

vector<int> g[32001];
int v[32001];

void ts(int i){
	
	if(v[i]) return;

	v[i] = 1;

	for(int k : g[i])
		if(!v[k]){
			ts(k);
			printf("%d ",k);
		}

}

int main(){
	int n,m;
	scanf("%d %d",&n,&m);

	for(int i=0,x,y ;i<m;i++){
		scanf("%d %d",&x,&y);
		g[y].push_back(x);
	}
	for(int i=1 ; i<=n;i++) g[0].push_back(i);
	ts(0);
	return 0;
}