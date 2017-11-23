#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);

  int n;
  vector<pair<int,int>> coordi;

  cin >> n;

  for(int i=0 ;i<n;i++){
    int x,y;
    cin >> x >> y;
    coordi.push_back(pair<int,int>(x,y));
  }

  sort(coordi.begin(),coordi.end());

  for(pair<int,int> a : coordi)
    cout << a.first << " " << a.second << '\n';

  return 0;
}
