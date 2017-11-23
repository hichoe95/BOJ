#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <cstring>
using namespace std;

vector<pair<int,char> > v[1001];
string s;
int n,m;
double d[1001];
int ind[1001][26];

int main(){
  ios_base::sync_with_stdio(0);

  cin >> n >> m;

  for(int i=0 ;i<m ; i++){
    int a,b;
    char c;
    cin >> a >> b >> c;
    v[a].push_back(pair<int,char>(b,c));
    v[b].push_back(pair<int,char>(a,c));
    ind[a][c-'A']++;
    ind[b][c-'A']++;
  }

  cin >> s;
  d[1] = 1;
  int len = s.length();

  for(int i=0 ;i<len ;i++){
    double nx[1001]={0.0,};
    for(int j=1 ; j<n; j++){
      char cur = s[i];
      int go = ind[j][cur-'A'];

      if(!go) nx[j] += d[j];
      else{
        for(auto k : v[j]){
          if(k.second==cur) nx[k.first] += d[j]/((double)go);
        }
      }
    }
    nx[n] += d[n];

    for(int l=0 ;l<=n;l++) d[l] = nx[l];
  }


  cout.precision(5);
  cout << d[n]*(1.0*100) << '\n';


  return 0;
}
