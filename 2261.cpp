#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int dist(int a, int b, int x, int y){
	return (a-x)*(a-x) + (b-y)*(b-y);
}

bool cmp(const pair<int,int> &a, const pair<int,int> &b){
	return a.second<b.second;
}

int find_dist(vector<pair<int,int> > &v,int start, int end){

	int m = -1;

	for(int i=start ;i<= end;i++)
		for(int j=i+1 ;j<= end; j++){
			int d = dist(v[i].first,v[i].second,v[j].first,v[j].second);
			if(m==-1|| m>d) m = d;
		}
	return m;

}

int solve(vector<pair<int,int> > &v, int start, int end){

	if(end-start+1 <=3) return find_dist(v,start,end);

	int mid = (start+end)/2;

	int ret = min(solve(v,start,mid),solve(v,mid+1,end));

	vector<pair<int,int> > tmp;

	for(int i=start ; i<=end ; i++){
		int d = v[i].first - v[mid].first;
		if(d*d < ret) tmp.push_back(v[i]);
	}

	sort(tmp.begin(), tmp.end(), cmp);

	int s = tmp.size();

	for(int i=0 ; i<s ; i++)
		for(int j=i+1 ; j<s ; j++){
			int y = tmp[i].second - tmp[j].second;
			if(y*y < ret){
				int d = dist(tmp[i].first,tmp[i].second,tmp[j].first,tmp[j].second);
				ret = ret<d ? ret : d;
			}
			else break;
		}

	return ret;


}

int main(){
	ios_base::sync_with_stdio(false);

	int n;

	cin >> n;
	
	vector<pair<int,int> > v(n);

	for(int i=0 ;i<n;i++) cin >> v[i].first >> v[i].second;

	sort(v.begin(),v.end());
	
	cout << solve(v,0,n-1);
	return 0;
}