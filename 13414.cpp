//
//  13414.cpp
//  BOJ
//
//  Created by 최환일 on 2017. 12. 17..
//  Copyright © 2017년 최환일. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int K,L;
	cin >> K >> L;
	map<string,int> m;
	vector<pair<int,string>> v;
	for(int i=0 ;i<L ;i++){
		string s;
		cin >> s;
		m[s] = i;
	}
	for(auto i = m.begin(); i!=m.end(); i++) v.push_back({i->second, i->first});
	sort(v.begin(),v.end());
	if(v.size()>=K) for(int i = 0 ; i<K ;i++) cout << v[i].second << '\n';
	else for(int i=0 ;i<v.size(); i++) cout << v[i].second << '\n';
	return 0;
}
