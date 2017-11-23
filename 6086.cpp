//
//  6086.cpp
//  BOJ
//
//  Created by 최환일 on 2017. 11. 17..
//  Copyright © 2017년 최환일. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;

const int INF (1<<30);

inline int ctoi(char c){
	if(c<='Z') return c-'A';
	return c-'a'+26;
}


int main(){
	ios_base::sync_with_stdio(0);
	
	int n;
	cin >> n;
	
	vector<int> adj[55];
	int c[55][55]={0};
	int f[55][55]={0};
	
	for(int i=0 ;i<n;i++){
		char a,b;
		int x;
		cin >> a >> b >> x;
		int from = ctoi(a);
		int to = ctoi(b);
		c[from][to] += x;
		adj[from].push_back(to);
		adj[to].push_back(from);
	}
	
	int MAX = 0, s = ctoi('A'), e = ctoi('Z');
	
	while(1){
		
		int prev[55];
		fill(prev,prev + 55 , -1);
		queue<int> q;
		
		q.push(s);
		
		while(!q.empty()){
			int cur = q.front();
			q.pop();
			for(int next : adj[cur]){
				if(c[cur][next] > f[cur][next] && prev[next]==-1){
					q.push(next);
					prev[next] = cur;
					if(next==e) break;
				}
			}
		}
		
		if(prev[e] == -1) break;
		
		int flow = INF;
		for(int i=e ; i!=s ; i=prev[i]) flow = min(flow,c[prev[i]][i] - f[prev[i]][i]);
		
		for(int i=e; i!=s ; i=prev[i]){
			f[prev[i]][i] += flow;
			f[i][prev[i]] -= flow;
		}
		
		MAX += flow;
	}
	
	cout << MAX << '\n';
	return 0;
}


