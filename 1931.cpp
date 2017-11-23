#include <iostream>
#include <vector>
using namespace std;

struct t{
	int x,y;
};

bool cmp(const t &u,const t &v){
	if(u.y == v.y) return u.x<v.x;
	else return u.y<v.y;
}

int main(){

	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<t> a(n);

	for(int i=0 ;i<n;i++) cin >> a[i].x >> a[i].y;

	sort(a.begin(),a.end(),cmp);

	int cur=0,cnt=0;
	for(int i=0 ;i<n;i++){
		if(cur<=a[i].x){
			cur = a[i].y;
			cnt++;
		}
	}
	cout << cnt << '\n';

}