#include <iostream>
using namespace std;

int main(){

	ios_base::sync_with_stdio(0);

	int n,a[1001][1001]={0,},ans[1001]={0,};
	cin >> n;

	for(int i=1 ; i<=n;i++)
		for(int j=1 ; j<=n ; j++)
			cin >> a[i][j];

	for(int i=1 ; i<=n ; i++){
		for(int j=1 ; j<=n ; j++){
			if(j!=i){
				ans[i] |= a[i][j];
			}
		}
	}
	for(int i=1 ; i<=n ;i++) cout << ans[i] << ' ';
	return 0;
}