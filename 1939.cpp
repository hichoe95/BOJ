#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
#define pii pair<int,int>

int N,M;
vector<pii> v[100000];
bool visited[100000];
int START,END;

bool check(int cur,int W){

	if(visited[cur]) return false;

	if(cur == END) return true;

	visited[cur] = true;

	for(pii next : v[cur]){
		int nx = next.first, cost = next.second;
		if(cost >= W){
			if(check(nx,W)) return true;
		}
	}
	return false;

}

int main(){
	ios_base::sync_with_stdio(false);
	int maxi=-1;
	cin >> N >> M;

	for(int i=0,x,y,c ;i<M ; i++){
		cin >> x >> y >> c;
		v[x].push_back(pii(y,c));
		v[y].push_back(pii(x,c));
		if(maxi<c) maxi = c;
	}

	cin >> START >> END;


	int L = 1, R = maxi;

	while(L<=R){
		int C = L+(R-L)/2;
		check(START,C) ? L = C+1 : R = C-1;
		memset(visited,0,sizeof(visited));
	}

	cout << R;


	return 0;
}