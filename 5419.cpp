//
//  5419.cpp
//  BOJ
//
//  Created by 최환일 on 2017. 12. 18..
//  Copyright © 2017년 최환일. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
#define P pair<int,int>

const int SIZE = 1<<18;

struct seg{
	int arr[SIZE];
	seg(){memset(arr,0,sizeof(arr));}
	
	void increase(int n){
		n += SIZE/2;
		while(n>0){
			arr[n]++;
			n/=2;
		}
	}
	
	int sum(int s, int e){ return sum(s,e,1,0,SIZE/2);}
	int sum(int s, int e, int node, int ns, int ne){
		if(e <= ns || ne <= s) return 0;
		if(s <= ns && ne <= e) return arr[node];
		int mid = (ns+ne)/2;
		return sum(s,e,node*2, ns, mid) + sum(s,e,node*2+1, mid, ne);
	}
};

int main(){
	
	ios_base::sync_with_stdio(false);
	
	int t;
	cin >> t;
	
	while(t--){
		int n,ind=0;
		cin >> n;
		seg ST;
		P p[75000];
		
		for(int i=0 ;i<n ;i++){
			int x,y;
			cin >> x >> y;
			p[i] = P(x,y);
		}
		
		sort(p, p+n, [](P &a, P &b){
			return a.second < b.second;
		});
		
		int newY[75000];
		
		for(int i=0 ;i<n; i++){
			if(i>0 && p[i].second!=p[i-1].second) ind++;
			newY[i] = ind;
		}
		
		for(int i=0 ;i<n; i++) p[i].second = newY[i];
		
		sort(p, p+n, [](P &a, P &b){
			if(a.first == b.first) return a.second > b.second;
			return a.first < b.first;
		});
		
		long long ans = 0;
		
		for(int i=0 ;i<n ;i++){
			ans += ST.sum(p[i].second, SIZE/2);
			ST.increase(p[i].second);
		}
		cout << ans << '\n';
	}
	
	return 0;
}
