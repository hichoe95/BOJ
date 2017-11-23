#include <iostream>
using namespace std;

int dist(int a, int b, int x, int y, int r){
	return (a-x)*(a-x) + (b-y)*(b-y) < r*r ? 1 : 0;
}

int main(){
	ios_base::sync_with_stdio(false);

	int t;
	cin >> t;

	while(t--){
		int a,b,c,d,cnt=0;

		cin >> a >> b >> c >> d;

		int n; cin >> n;

		for(int i=0,x,y,r;i<n;i++){
			cin >> x >> y >> r;
			int D1 = dist(a,b,x,y,r),D2=dist(c,d,x,y,r);
			if(D1 != D2) cnt++;
		}
		cout << cnt << '\n';
	}

	return 0;
}
