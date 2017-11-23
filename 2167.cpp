#include <cstdio>

int a[301][301];

int p_sum(int i,int j , int x , int y){
	return a[x][y] - a[i-1][y] - a[x][j-1] + a[i-1][j-1];
}

int main(){
	int n,m;
	scanf("%d %d",&n,&m);

	for(int i=1 ; i<=n ; i++)
		for(int j=1 ; j<=m ;j++){
			scanf("%d",&a[i][j]);
			a[i][j] += (a[i-1][j] + a[i][j-1] - a[i-1][j-1]);
		}

	int k;scanf("%d",&k);
	while(k--){
		int i,j,x,y;
		scanf("%d %d %d %d",&i,&j,&x,&y);
		printf("%d\n",p_sum(i,j,x,y));
	}
	return 0;
}