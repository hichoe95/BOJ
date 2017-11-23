//
//  6241.cpp
//  BOJ
//
//  Created by 최환일 on 2017. 11. 23..
//  Copyright © 2017년 최환일. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;

const int DRINK = 200;
const int FOOD = 300;
const int COW = 100;
const int MAX = 400+2;
const int INF = (1<<30);
const int S = MAX -2;
const int E = MAX -1;
int c[MAX][MAX], f[MAX][MAX];
vector<int> adj[MAX];
int level[MAX] ,work[MAX];

bool bfs(){
	memset(level, -1 ,sizeof(level));
	level[S] = 0;
	
	queue<int> Q;
	Q.push(S);
	
	while(!Q.empty()){
		int cur = Q.front();
		Q.pop();
		for(int next : adj[cur]){
			if(level[next] == -1 && c[cur][next] > f[cur][next]){
				level[next] = level[cur] + 1;
				Q.push(next);
			}
		}
	}
	return level[E] != -1;
}

int dfs(int cur, int arv, int flow){
	
	if(cur == arv) return flow;
	
	for(int &i = work[cur]; i<adj[cur].size(); i++){
		int next = adj[cur][i];
		
		if(level[next] == level[cur] + 1 && c[cur][next] - f[cur][next] > 0){
			int df = dfs(next, arv, min(flow, c[cur][next] - f[cur][next]));
			
			if(df > 0){
				f[cur][next] += df;
				f[next][cur] -= df;
				return df;
			}
		}
	}
	
	return 0;
}


int main(){
	
	ios_base::sync_with_stdio(false);
	
	int N,F,D;
	
	cin >> N >> F >> D;
	//소스와 음식, 드링크
	for(int i=0 ;i<F;i++){
		c[S][i+FOOD] = 1;
		adj[i+FOOD].push_back(S);
		adj[S].push_back(i+FOOD);
	}
	for(int i=0 ;i<D;i++){
		c[i+DRINK][E] = 1;
		adj[i+DRINK].push_back(E);
		adj[E].push_back(i+DRINK);
	}
	for(int i=0 ;i<N;i++){
		adj[i].push_back(i+COW);
		adj[i+COW].push_back(i);
		c[i][i+COW] = 1;
	}
	
	for(int i=0 ;i<N ;i++){
		int F_i, D_i;
		cin >> F_i >> D_i;
		
		for(int j=0 ; j<F_i ;j++){
			int food; cin >> food; food -=1;
			c[FOOD+food][i] = 1;
			adj[i].push_back(FOOD + food);
			adj[FOOD + food].push_back(i);
		}
		for(int j=0; j<D_i ; j++){
			int drink; cin >> drink; drink-=1;
			c[i+COW][DRINK + drink] = 1;
			adj[DRINK + drink].push_back(i+COW);
			adj[i+COW].push_back(DRINK + drink);
		}
	}
	
	int total = 0;
	
	while(bfs()){
		int flow;
		memset(work, 0, sizeof(work));
		while((flow = dfs(S,E,INF))) total += flow;
	}
	cout << total << '\n';
	
	
	
	
	return 0;
}
