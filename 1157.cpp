#include <bits/stdc++.h>
using namespace std;

int main(){

  ios_base::sync_with_stdio(false);
  string s;
  cin >> s;
  int a[30]={0,};
  int len = s.size();
  transform(s.begin(), s.end(), s.begin(), ::toupper);

  for(int i=0 ;i<len;i++) a[s[i]-'A']++;

  bool flag = false;
  int idx = -1, Max=-1;

  for(int i=0 ;i<26 ;i++){
    if(a[i]>Max) Max = a[i],idx = i,flag = false;
    else if(a[i]==Max) flag = true;
  }

  if(flag) cout << "?\n";
  else cout << (char)('A'+idx) << '\n';
  return 0;
}
