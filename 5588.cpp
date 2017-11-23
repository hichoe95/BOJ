#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(const pair<int,int> &a,const pair<int,int> &b){
  if(a.first == b.first){
    return a.second > b.second;
  }
  return a.first < b.first;
}

int main(){

  ios_base::sync_with_stdio(0);

  int n,m;
  cin >> n;

  vector<pair<int,int> > a(n);

  for(int i=0 ;i<n;i++) cin >> a[i].first >> a[i].second;

  sort(a.begin(),a.end(),cmp);

  cin >> m;

  vector<pair<int,int> > b(m);

  for(int i=0 ;i<m;i++) cin >> b[i].first >> b[i].second;
  sort(b.begin(),b.end());

  int x = a[0].first;
  int y = a[0].second;

  for(int i=0 ;i<m;i++){
    int dx = b[i].first - x, dy = b[i].second - y;
    bool flag = false;
    for(int j=0 ;j<n;j++){
      if(!binary_search(b.begin(), b.end(), make_pair(a[j].first+dx,a[j].second+dy))){
        flag = true;
        break;
      }
    }
    if(!flag){
      cout << dx << " " << dy << '\n';
      return 0;
    }
  }

  return 0;
}
