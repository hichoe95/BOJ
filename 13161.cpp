//
//  13161.cpp
//  BOJ
//
//  Created by 최환일 on 2017. 11. 23..
//  Copyright © 2017년 최환일. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;

const int MAX_V = 502;
const int S = 500;
const int E = 501;
const int INF = (1<<30);

int N, c[MAX_V][MAX_V] , f[MAX_V][MAX_V];
int level[MAX_V], work[MAX_V];
vector<int> adj[MAX_V];

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
	
	int N;
	cin >> N;
	
	for(int i=0 ;i<N ;i++){
		int where;
		cin >> where;
		if(where == 1){
			c[S][i] = INF;
			adj[i].push_back(S);
			adj[S].push_back(i);
		}
		else if(where == 2){
			c[i][E] = INF;
			adj[i].push_back(E);
			adj[E].push_back(i);
		}
	}
	
	for(int i=0 ;i<N ;i++) for(int j=0 ;j<N ;j++){
		cin >> c[i][j];
		if(i != j) adj[i].push_back(j);
	}
	
	int total = 0;
	
	while(bfs()){
		int flow;
		memset(work, 0, sizeof(work));
		while((flow = dfs(S,E,INF))) total += flow;
	}
	cout << total << '\n';
	
	bool visited[MAX_V] = {false};
	visited[S] = true;
	queue<int> q;
	q.push(S);
	while(!q.empty()){
		int cur = q.front();
		q.pop();
		for(int next : adj[cur])
			if(!visited[next] && c[cur][next] - f[cur][next] > 0){
				visited[next] = true;
				q.push(next);
			}
	}
	
	for(int i=0 ;i<N ;i++) if(visited[i]) cout << i+1 << " ";
	cout << '\n';
	for(int i=0 ;i<N ;i++) if(!visited[i]) cout << i+1 << " ";
	cout << '\n';
	
	return 0;
}
