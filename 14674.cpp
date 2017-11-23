#include <bits/stdc++.h>
using namespace std;

bool cmp(const pair<int,pair<double,double>>& a, const pair<int,pair<double,double>>& b){


  if(a.second.second/a.second.first == b.second.second/b.second.first){
    if(a.second.first == b.second.first) return a.first < b.first;
    return a.second.first < b.second.first;
  }

  return a.second.second/a.second.first > b.second.second/b.second.first;



}

int main(){

  int n, k;

  cin >> n >> k;

  vector<pair<int,pair<double,double> > > game(n);

  for(int i=0 ;i<n;i++) cin >> game[i].first >> game[i].second.first >> game[i].second.second;

  sort(game.begin(), game.end(), cmp);

  for(int i=0 ;i<k;i++) cout << game[i].first << '\n';

  return 0;
}
