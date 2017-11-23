//
//  1298.cpp
//  BOJ
//
//  Created by 최환일 on 2017. 11. 17..
//  Copyright © 2017년 최환일. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;

vector<int> adj[MAX];
bool visited[MAX];
int A[MAX],B[MAX];

bool dfs(int a){
	visited[a] = true;
	
	for(int b : adj[a]){
		if(B[b] == -1 || !visited[B[b]] && dfs(B[b])){
			A[a] = b;
			B[b] = a;
			return true;
		}
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(0);
	
	int n, m;
	cin >> n >> m;
	
	for(int i=0 ;i<m;i++){
		int a, b;
		cin >> a >> b;
		adj[a-1].push_back(b-1);
	}
	
	memset(A, -1 ,sizeof(A));
	memset(B, -1 , sizeof(B));
	int match = 0;
	for(int i=0 ;i<n;i++){
		if(A[i] == -1){
			memset(visited, 0 ,sizeof(visited));
			if(dfs(i)) match++;
		}
	}
	
	cout << match << '\n';
	
	return 0;
}
