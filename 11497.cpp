#include <iostream>
#include <algorithm>
using namespace std;

#define ABS(x) (x)>0 ? (x) : -(x)

int main(){
	ios_base::sync_with_stdio(false);
	int T;
	cin >> T;

	while(T--){

		int n;
		cin >> n;
		int a[10001]={0,},b[10001]={0,};

		for(int i=0 ;i<n;i++) cin >> a[i];

		sort(a,a+n);
		
		int f=0,r=n-1;

		for(int i=n-2 ; i>=0 ; i-=2){
			b[f++] = a[i];
			b[r--] = a[i+1];
		}
		if(n&1) b[n/2] = a[0];
		b[n] = b[0];
		int m=-1;
		for(int i=0 ;i<n ; i++)
			m = max(m,ABS(b[i] - b[i+1]));
		cout << m << '\n';
	}	

	return 0;
}