#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long

int n;
ll m;
vector<ll> v;

bool check(int height){
	ll sum = 0;

	for(int i : v) sum+= ((i-height)>=0 ? i-height : 0);
	return sum>=m;
}

int main(){

	ios_base::sync_with_stdio(false);

	int M = -1;

	cin >> n >> m;

	v.resize(n);

	for(int i=0 ;i<n ; i++) cin >> v[i], M = M<v[i]? v[i] : M;

	ll l=1,r=M,c;

	while(l<=r){
		c = (l+r)/2;

		check(c) ? l = c+1 : r = c-1;
	}

	cout << r;



	return 0;
}