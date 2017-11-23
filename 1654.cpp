#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long

int k,n;
ll M = -1;
vector<ll> v;

bool check(ll l){
	int sum = 0;
	for(ll i : v) sum+= i/l;
	return sum>=n;
}

int main(){

	ios_base::sync_with_stdio(false);

	cin >> k >> n;

	v.resize(k);

	for(int i=0 ;i<k ; i++){
		cin >> v[i];
		M = max(M,v[i]);
	}

	ll l = 1, r = M , m;
	while(l<=r){
		 m = (l+r)/2;
		check(m) ? l = m+1 : r = m-1;
	}

	cout << r;


	return 0;
}