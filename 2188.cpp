//
//  2188.cpp
//  BOJ
//
//  Created by 최환일 on 2017. 11. 17..
//  Copyright © 2017년 최환일. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;

vector<int> adj[200];
bool visited[200];
int A[200],B[200];

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
	
	int n, m;
	cin >> n >> m;
	
	for(int i=0 ;i<n; i++){
		int s; cin >> s;
		for(int j=0 ;j<s ;j++){
			int x; cin >> x;
			adj[i].push_back(x-1);
		}
	}
	int match = 0;
	fill(A, A+200, -1);
	fill(B, B+200, -1);
	
	for(int i=0 ;i<n;i++){
		if(A[i] == -1){
			memset(visited, 0, sizeof(visited));
			if(dfs(i)) match++;
		}
	}
	
	cout << match << '\n';
	
	
	return 0;
}
