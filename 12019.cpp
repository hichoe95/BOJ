//
//  12019.cpp
//  BOJ
//
//  Created by 최환일 on 2017. 12. 15..
//  Copyright © 2017년 최환일. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
#define INF 1<<20

int n, m;
int dp[101][11][2001];
int p[101];

int rec(int cur, int c, int dirty){
	
	if(c > m) return INF;
	if(cur >= n) return 0;
	
	int &ret = dp[cur][c][dirty];
	if(ret != -1) return ret;
	
	ret = min(rec(cur + 1, c, dirty + p[cur]),rec(cur+1, c+1, 0));
	return ret += dirty*p[cur];
}

void trace(int cur, int c, int dirty){
	if(cur >= n) return;
	if(c<=m && rec(cur+1, c+1, 0) <= rec(cur+1, c, dirty + p[cur])){
		cout << cur + 1 << " ";
		trace(cur+1, c+1, 0);
	}
	else trace(cur+1, c, dirty + p[cur]);
}

int main(){
	ios_base::sync_with_stdio(false);
	memset(dp, -1, sizeof(dp));
	
	cin >> n >> m;
	
	for(int i=0 ;i<n;i++) cin >> p[i];
	
	cout << rec(0,0,0) << '\n';
	trace(0,0,0);
	return 0;
}
