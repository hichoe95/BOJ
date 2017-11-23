#include <iostream>
using namespace std;
#define max(a,b) a>b ? a : b

int n,L[21],J[21];
int dp[21][101];

int go(int a, int b){
	if(dp[a][b]) return dp[a][b];
	if(a>=n) return 0;

	dp[a][b] = b-L[a]>0 ? max(go(a+1,b-L[a])+J[a],go(a+1,b)) : max(dp[a][b],go(a+1,b));

	return dp[a][b];
}	

int main(){
	
	cin >> n;

	for(int i=0 ;i<n;i++) cin >> L[i];
	for(int i=0 ;i<n;i++) cin >> J[i];


	cout << go(0,100) << '\n';

	return 0;
}