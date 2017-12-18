
//
//  2170.cpp
//  BOJ
//
//  Created by 최환일 on 2017. 12. 18..
//  Copyright © 2017년 최환일. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;

int main(){
	ios_base::sync_with_stdio(false);
	
	int N;
	
	cin >> N;
	
	vector<pair<int,int>> v(N);
	
	for(int i=0 ;i<N ;i++) cin >> v[i].first >> v[i].second;
	
	sort(v.begin(), v.end());
	
	int r = -INF , l = -INF, ans = 0;
	
	for(pair<int,int> p : v){
		if(r<p.first){
			ans += (r-l);
			l = p.first;
			r = p.second;
		}
		else r = max(r, p.second);
	}
	
	ans += r-l;
	
	cout << ans << '\n';
	
	return 0;
}
