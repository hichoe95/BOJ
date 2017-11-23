#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

int main(){
  ios_base::sync_with_stdio(0);

  int t;
  cin >> t;

  while(t--){
    bool flag = true;
    int n;
    cin >> n;
    vector<string> v(n);
    for(int i=0 ;i<n;i++) cin >> v[i];

    sort(v.begin(),v.end());

    int sz = v.size();

    for(int i=1 ;i<sz ; i++){
      int len = v[i-1].length();
      if(!strncmp(v[i-1].c_str(),v[i].c_str(),len)){
        flag = false;
        break;
      }
    }
    cout << (flag ? "YES" : "NO") << '\n';

  }

  return 0;
}
