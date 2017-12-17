//
//  4963.cpp
//  BOJ
//
//  Created by 최환일 on 2017. 12. 17..
//  Copyright © 2017년 최환일. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;

bool visit[50][50];
int w,h;
int m[50][50];
int dx[8] = {1,1,1,-1,-1,-1,0,0};
int dy[8] = {1,0,-1,1,0,-1,1,-1};

void dfs(int x, int y){
	visit[x][y] = true;
	
	for(int i=0 ;i<8 ;i++){
		int nx = dx[i] + x, ny = dy[i] + y;
		if(nx >= 0 && ny >=0 && nx < h && ny < w)
			if(!visit[nx][ny] && m[nx][ny])
				dfs(nx,ny);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin >> w >> h;
	
	while(w && h){
		int cnt = 0;
		for(int i=0 ;i<h ; i++) for(int j=0 ;j<w ;j++)
			cin >> m[i][j];
		for(int i=0 ;i<h ;i++) for(int j=0 ;j<w ;j++){
			if(!visit[i][j] && m[i][j]){
				dfs(i,j);
				cnt++;
			}
		}
		cout << cnt << '\n';
		memset(visit,0,sizeof(visit));
		memset(m,0,sizeof(m));
		cin >> w >> h;
	}
	
	
	return 0;
}
