#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;

  vector<int> tri[501];
  vector<int> d[501];
  for(int i=0 ; i<n;i++)
    for(int j=0;j<=i;j++){
      int k;
      cin >> k;
      tri[i].push_back(k);
    }

  d[0].push_back(tri[0][0]);

  for(int i=1 ; i<n;i++){
    for(int j=0; j<=i;j++){
      if(j==i)
        d[i].push_back(d[i-1][j-1]+tri[i][j]);
      else if(j-1>=0)
        d[i].push_back(max(d[i-1][j-1],d[i-1][j])+tri[i][j]);
      else
        d[i].push_back(d[i-1][j] + tri[i][j]);
    }
  }

  int m=0;
  for(int i=0 ;i<n;i++)
    m=max(m,d[n-1][i]);

  cout << m << endl;

  return 0;
}
