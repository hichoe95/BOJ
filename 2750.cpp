#include <bits/stdc++.h>
using namespace std;

int main(){
	int N;
	cin >> N;
	vector<int> k(N);
	
	for(int i=0 ;i<N;i++) cin >> k[i];
	sort(k.begin(),k.end());
	for(int i : k) cout << i << '\n';
}
