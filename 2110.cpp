#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N,C;
vector<int> v;

bool check(int n){
	int cnt=1, ins = v[0];
	for(int i : v) if(i-ins >= n) cnt++,ins = i;
	return cnt>=C;
}

int main(){
	ios_base::sync_with_stdio(false);

	cin >> N >> C;
	v.resize(N);
	for(int i=0 ; i<N ; i++) cin >> v[i];
	sort(v.begin(),v.end());

	int L = 1 , R = v[N-1] - v[0];

	while(L<=R){
		int mid = (L+R)/2;
		check(mid) ? L = mid+1 : R = mid-1;
	}

	cout << R;

	return 0;
}