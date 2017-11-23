#include <cstdio>

int p[2200][2200];
int cnt[3];
	
bool check(int x, int y, int n){
	int k = p[x][y];
	for(int i = x ; i<x+n ; i++)
		for(int j=y ; j<y+n ; j++)
			if(k!=p[i][j]) return false;

	return true;
}

void rec(int x, int y, int n){

	if(check(x,y,n)){
		cnt[p[x][y]+1]++;
		return;
	}

	int m = n/3;

	for(int i=0 ; i < 3 ; i++)
		for(int j=0 ; j < 3 ; j++)
			rec(x+i*m,y+j*m,m);
}

int main(){

	int n;
	scanf("%d",&n);

	for(int i=0 ; i<n ;i++)
		for(int j=0 ; j<n ;j++)
			scanf("%d",&p[i][j]);
	rec(0,0,n);
	for(int i=0 ;i<3;i++) printf("%d\n",cnt[i]);

	return 0;
}