#include <iostream>
#include <vector>
using namespace std;

int main(){

  int t;
  cin >> t;

  while(t--){
    int a,b;
    cin >> a >> b;
    vector<int> v;
    if(a%10 == 0){
      cout << 10 << '\n';
      continue;
    }
    int m=a%10;
    v.push_back(m);
    while(1){
      m *= a;
      m%=10;
      if(m == (a%10)) break;
      v.push_back(m);
    }
    if(b%(v.size())) cout << v[b%v.size()-1] << '\n';
    else cout << *(v.end()-1) << '\n';
  }
  return 0;
}
