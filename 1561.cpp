#include <iostream>
#include <vector>
using namespace std;
#define ll long long


int main(){
	ios_base::sync_with_stdio(false);

	ll N,M;
	cin >> N >> M;

	vector<ll> v(M);

	for(int i=0 ;i<M; i++) cin >> v[i];

	if(N<=M){
		cout << M;
		return 0;
	}

	ll L = 1;
	ll R = 2000000000LL * 1000000LL;

	while(L<=R){
		ll C = (L + R)/2;
		ll sum = M;

		for(ll i : v) sum += (C/i);

		sum>=N ? R = C-1 : L = C+1;

		for(ll i = v.size()-1 ; i>=0 ; i--)
			if(!(C % v[i])){
				if(sum == N){
					cout << i + 1;
					return 0;
				}
				sum-=1;
			}
	}


	return 0;
}