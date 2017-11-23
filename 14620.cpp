#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
#define MAX 9876543

int n,g[13][13],c[13][13],res = MAX,i,j;

void f(int px, int py,int x,int y, int sum, int s){

	if(s>=3){
		res = min(res,sum);
		return;
	}

	for(int i=2; i<n; i++)
		for(int j=2 ; j<n ;j++)
			if((abs(x-i) + abs(y-j))>2 && (abs(px-i) + abs(py-j))>2)
				f(x,y,i,j,sum+c[i][j],s+1);
	
}

int main(){
	ios_base::sync_with_stdio(false);

	cin >> n;

	for(i=1 ; i<=n ;i++)
		for(j=1 ;j<=n ;j++)
			cin >> g[i][j];

	for(i=2; i<n ; i++)
		for(j=2 ; j<n ; j++)
			c[i][j] = g[i][j] + g[i-1][j] + g[i+1][j] + g[i][j-1] + g[i][j+1];

	for(i=2 ; i<n;i++)
		for(j=2 ; j<n ; j++)
			f(MAX,MAX,i,j,c[i][j],1);

	cout << res << '\n';

	return 0;	
}