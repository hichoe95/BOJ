#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<int> v;
bool a[1001];
int visit[1001];

bool check(int n,int k){

	if(k==3 && !n) return true;

	if(k>3) return false;

	for(int i : v){
		if(i<=n){
			visit[i]++;
			if(check(n-i,k+1)){
				return true;
			}
			visit[i]--;
		}
	}
	return false;
}


int main(){
	ios_base::sync_with_stdio(false);
	for(int i=2 ; i<=1000 ; i++)
		for(int j = i*2 ; j<=1000 ; j+=i) a[j] = true;
	for(int i=2 ; i<=1000 ; i++)
		if(!a[i]) v.push_back(i);

	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		if(check(n,0)){
			for(int i=2 ; i<n ; i++)
				for(int j = 0 ; j<visit[i] ; j++)
					cout << i << " ";
			cout << '\n';
		}
		else cout << 0 << '\n';

		memset(visit,0,sizeof(visit));
	}
	return 0;
}