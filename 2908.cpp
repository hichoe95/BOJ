#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main(){
  string a,b;
  cin >> a >> b;
  reverse(a.begin(),a.end());
  reverse(b.begin(),b.end());

  cout << max(a,b) << endl;

  return 0;
}
