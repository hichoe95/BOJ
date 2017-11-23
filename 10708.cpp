#include <cstdio>

int main(){

	int n,m,a[101]={0,},b[101][101]={0,},score[101]={0,};
	scanf("%d %d",&n,&m);
	for(int i=1 ;i<=m;i++) scanf("%d",&a[i]);

	for(int i=1 ; i<=m;i++)
		for(int j=1 ; j<=n ; j++)
			scanf("%d",&b[i][j]);

	for(int i=1 ; i<=m;i++){
		int target = a[i];
		for(int j=1 ; j<=n; j++)
			if(b[i][j]==target) score[j]++;
			else score[target]++;
	}
	for(int i=1; i<=n ; i++) printf("%d\n",score[i]);
	return 0;
}