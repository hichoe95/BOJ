//
//  1708.cpp
//  BOJ
//
//  Created by 최환일 on 2017. 11. 24..
//  Copyright © 2017년 최환일. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;

const int MAX = 100000;

struct POINT{
	int x,y;
	int p,q;
	POINT(): POINT(0,0,1,0){}
	POINT(int x1, int y1): POINT(x1,y1,1,0){}
	POINT(int x1, int y1, int p1, int q1): x(x1), y(y1), p(p1), q(q1){}
	
	bool operator <(const POINT& k){
		if(1LL*k.p*q != 1LL*k.q*p) return 1LL * k.p * q < 1LL* k.q * p;
		if(y!=k.y) return y<k.y;
		return x<k.x;
	}
};

bool ccw(const POINT& a,const POINT& b,const POINT& c){
	return 1LL*(b.y-a.y)*(c.x-a.x) < 1LL*(c.y-a.y)*(b.x-a.x);
}

int main(){
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	POINT p[MAX];
	
	for(int i=0 ;i<N; i++){
		int x, y; cin >> x >> y;
		p[i] = POINT(x,y);
	}
	sort(p,p+N);
	
	for(int i=1 ;i<N ;i++){
		p[i].p = p[i].x - p[0].x;
		p[i].q = p[i].y - p[0].y;
	}
	sort(p+1,p+N);
	
	stack<int> s;
	s.push(0);
	s.push(1);
	int nx = 2;
	
	while(nx<N){
		while(s.size() >= 2){
			int first, second;
			first = s.top();
			s.pop();
			second = s.top();
			if(ccw(p[second],p[first],p[nx])){
				s.push(first);
				break;
			}
		}
		s.push(nx++);
	}
	
	cout << s.size() << '\n';
	return 0;
}
