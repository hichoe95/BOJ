#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define ll long long 
#define INF 1e18

ll t[110];
ll d[111][111][2];
int n,start;

void init(){
	n=start=0;
	memset(t,0,sizeof(t));
	memset(d,-1,sizeof(d));
}

ll secur(int st, int fin, int pos){

	ll & time = d[st][fin][pos];
	int remain = (n-fin) + (st+1 -1);
	
	if(st == start && fin == start) return 0;
	if(st>fin) return INF;
	if(time!=-1) return time;
	
	time = INF;
	pos ? time = min(secur(st,fin-1,0) + remain*(t[fin] - t[st]), secur(st,fin-1,1) + remain*(t[fin]-t[fin-1]))
	: time = min(secur(st+1,fin,0) + remain*(t[st+1] - t[st]), secur(st+1,fin,1) + remain*(t[fin] - t[st]));

	return time;
}

int main(){

	int T;
	scanf("%d",&T);

	while(T--){
		init();
		scanf("%d %d",&n,&start);
		for(int i=2, ti ; i<=n ; i++){
			scanf("%d",&ti);
			t[i] = t[i-1]+ti;
		}
		
		printf("%lld\n",min(secur(1,n,0),secur(1,n,1)));
	}

	return 0;
}