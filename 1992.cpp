#include <cstdio>

int t[64][64];

bool check(int x, int y, int n){
	for(int i=x ; i<x+n ; i++)
		for(int j=y ; j<y+n ; j++)
			if(t[i][j]!=t[x][y]) return false;

	return true;
}

void qt(int x, int y, int n){
	if(check(x,y,n)) printf("%d",t[x][y]);
	else{
		printf("(");
		int m  = n/2;
		for(int i=0 ;i<2 ; i++)
			for(int j=0 ; j<2 ; j++)
				qt(x+m*i,y+m*j,m);
		printf(")");
	}

}

int main(){

	int n;
	scanf("%d",&n);
	for(int i=0 ;i<n; i++)
		for(int j=0 ; j<n; j++)
			scanf("%1d",&t[i][j]);

	qt(0,0,n);

	return 0;
}