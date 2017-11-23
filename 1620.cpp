#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <cstring>
#include <vector>
#include <map>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  int m,n;
  cin >> n >> m;
  string a;

  map<string,int> poketmon;
  map<int,string> index;
  vector<string> quiz(m);

  for(int i=1 ;i<=n;i++){
    cin >> a;
    poketmon[a] = i;
    index[i] = a;
  }

  for(int i=0 ;i<m;i++)
    cin >> quiz[i];

  for(int i=0 ; i<m;i++){
    if(quiz[i][0]>='A' && quiz[i][0] <= 'Z') cout << poketmon[quiz[i]] << '\n';
    else cout << index[atoi(quiz[i].c_str())] << '\n';

  }

  return 0;
}
