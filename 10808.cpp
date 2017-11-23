#include <iostream>
#include <map>
#include <cstring>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  string a;
  cin >> a;
  int len = a.size();
  map<char,int> m;
  for(int i=1 ;i<=26 ; i++) m['a'+i-1] =0;
  for(int i=0 ;i<len ;i++) m[a[i]]++;
  for(auto &p : m) cout << p.second << " ";
  cout << '\n';
  return 0;
}
