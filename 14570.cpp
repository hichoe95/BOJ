#include <iostream>
using namespace std;
#define ll long long

int tree[200001][2];// 0 = left child, 1 = right child
int n,u,v;
ll c;

int go(int root,ll c){
	int lc = tree[root][0],rc = tree[root][1];

	if(!lc && !rc) return root;

	if(!lc && rc) return go(rc,c);
	if(lc && !rc) return go(lc,c);

	if(c%2) return go(rc,c>>1);
	else return go(lc,c>>1);
}

int main(){

	ios_base::sync_with_stdio(false);
	cin >> n;

	for(int i=1 ;i<=n;i++){
		cin >> u >> v;
		if(u!=-1) tree[i][0] = u;
		if(v!=-1) tree[i][1] = v;
	}

	cin >> c;

	cout << go(1,c-1) << endl;


	return 0;
}
